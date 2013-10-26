/*
 * BackgroundSubstractor.hpp
 *
 *  Created on: 25 oct. 2013
 *      Author: raiton
 */
#ifndef BACKGROUNDSUBSTRACTOR_HPP_
#define BACKGROUNDSUBSTRACTOR_HPP

#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>

using namespace cv;

class Background_Substractor {
protected:
	Mat initial_background;
	Mat initial_background_gray;
	Mat Background;
	Mat Background_gray;
	BackgroundSubtractorMOG2 bgmog2;

public:
	Background_Substractor(Mat );
	virtual ~Background_Substractor();
	Mat Running_Average(Mat);
	Mat Frame_diff(Mat);
	Mat MixtureOfGaussian2(Mat);
};

#endif /* BACKGROUNDSUBSTRACTOR_HPP_ */
