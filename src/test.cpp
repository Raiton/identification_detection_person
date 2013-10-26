#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
#include "background_substract.hpp"
#include <opencv2/nonfree/features2d.hpp>
#include "noise_reduction.hpp"
#include "skin_detection.hpp"
#include "BackgroundSubstractor.hpp"

using namespace cv;
using namespace std;




int main(int argc, char *argv[])
{
	Mat frame;
	Mat foreground;
	Mat foreground_denoised;
	Mat skin;
	Mat background;
	Mat foreground_with_contours;
	String window_name="Test";

	namedWindow( window_name, CV_WINDOW_AUTOSIZE );
	namedWindow( "1", CV_WINDOW_AUTOSIZE );

	namedWindow( "2", CV_WINDOW_AUTOSIZE );



	VideoCapture cap(0);
	cap >> frame;
	frame.copyTo(background);

    std::vector<std::vector<Point> > contours;

	Background_Substractor* bs = new Background_Substractor(background);
	for(;;)
	{

		cap >> frame;

		foreground =bs->Frame_diff(frame);
		skin=skin_detection(frame);



		foreground_denoised=simple_noise_reduction(foreground.clone());
		foreground.copyTo(foreground_with_contours);
		findContours(foreground_with_contours,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);


	     for (uint i = 0; i< contours.size(); i++)
	     {
	         Scalar color = Scalar( 255,0,0 );

	         // Get bounding box for contour
	         Rect roi = boundingRect(contours[i]);
	         if (roi.area()>10000){
		         rectangle( frame, roi.tl(), roi.br(), color, 2, 8, 0 );

	         }

	     }




		imshow(window_name,frame);
		imshow("1",foreground);

		imshow("2",foreground_denoised);


		if(waitKey(30) >= 0) break;

	}
    return 0;
}
