/*
 * BackgroundSubstractor.cpp
 *
 *  Created on: 25 oct. 2013
 *      Author: raiton
 */

#include "BackgroundSubstractor.hpp"
#include "distances.hpp"

Background_Substractor::Background_Substractor(Mat initial_background) {
	// TODO Auto-generated constructor stub

	this->initial_background = initial_background;
	initial_background.copyTo(Background);

	cvtColor(Background, initial_background_gray, CV_BGR2GRAY);
	cvtColor(Background, Background_gray, CV_BGR2GRAY);
	this->bgmog2= BackgroundSubtractorMOG2() ;
	bgmog2.nmixtures = 3;
		bgmog2.bShadowDetection = false;
		bgmog2.nShadowDetection = 10;
		bgmog2.varThreshold = 16;


}

Mat Background_Substractor::Running_Average(Mat frame) {

	double threshold_limit = 30;
	Mat frame_gray;
	Mat temp;

//learning rate
	float alpha = 0.01;
	Mat back_gray = this->Background_gray;
	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	Mat fore(frame_gray.rows, frame_gray.cols, CV_8U);
	fore.setTo(0);

	threshold(d0(frame_gray, back_gray), fore, threshold_limit, 255,
			THRESH_BINARY);

	// update the background
	temp = alpha * frame_gray + (1 - alpha) * back_gray;
	temp.copyTo(back_gray);

	return fore;
}

Mat Background_Substractor::Frame_diff(Mat frame) {

	double threshold_limit =50;
	Mat frame_gray;
	Mat temp;
	//learning rate
	//load alpha=0.01;
	Mat back;

	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	Mat fore(frame_gray.rows, frame_gray.cols, CV_8U);

	fore.setTo(0);
	cvtColor(frame, frame_gray, CV_BGR2GRAY);

	threshold(d1(frame, initial_background), fore, threshold_limit,
			255, THRESH_BINARY);


//	unsigned char *input = (unsigned char*)(frame_gray.data);
//		for (int var = 0; var < (frame_gray.cols*frame_gray.rows); ++var) {
//			std::cout << input[var];
//		}
	return fore;
}
Mat Background_Substractor::MixtureOfGaussian2(Mat frame) {
	Mat fore;

	bgmog2.history = 1000;
	bgmog2.operator ()(frame, fore, 0.1);
	bgmog2.getBackgroundImage(Background);
	return fore;

}

Background_Substractor::~Background_Substractor() {
	// TODO Auto-generated destructor stub
}

