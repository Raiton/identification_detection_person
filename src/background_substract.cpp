#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<iostream>
#include<vector>
#include <stdio.h>
#include "noise_reduction.hpp"
#include "distances.hpp"
using namespace cv;

void changing_threshold(int pos,void* data);

Mat running_average(Mat frame)
{
	double threshold_limit=10;
	Mat frame_gray;
	Mat temp;
//learning rate
float alpha=0.01;
	    Mat back;
		cvtColor( frame, frame_gray, CV_BGR2GRAY );
        Mat fore(frame_gray.rows,frame_gray.cols,CV_8U);

        frame_gray.copyTo(back);
        namedWindow("Foreground");
        namedWindow("Background");


	           fore.setTo(0);
	       	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	           threshold(d0(frame_gray,back),fore,threshold_limit,255,THRESH_BINARY);

	          // update the background
	           temp=alpha*frame_gray+(1-alpha)*back;
	           temp.copyTo(back);

return fore;

}
int threshold_limit=40;

void frame_diff()
{

	int const max_value = 255;
	int threshold_value = 40;

	String window_name = "Backround_Substraction";

	String trackbar_value = "Threshold value";


	  namedWindow( window_name, CV_WINDOW_AUTOSIZE );
	  createTrackbar(trackbar_value,window_name,&threshold_value , max_value, changing_threshold);

	Mat frame_gray;
	Mat temp;
//learning rate
//load alpha=0.01;
	Mat frame;
	    Mat back;
	    Mat back_gray;

	    VideoCapture cap(0);
        cap >> frame;

		cvtColor( frame, frame_gray, CV_BGR2GRAY );
		//equalizeHist(frame_gray,frame_gray);
        Mat fore(frame_gray.rows,frame_gray.cols,CV_8U);

        frame.copyTo(back);

        frame_gray.copyTo(back_gray);



	    for(;;)
	       {

	           cap >> frame;
	           fore.setTo(0);
	       	cvtColor(frame, frame_gray, CV_BGR2GRAY);
			//equalizeHist(frame_gray,frame_gray);

	          threshold(d0(frame_gray,back_gray),fore,threshold_limit,255,THRESH_BINARY);
	          //threshold(d1(frame,back),fore,threshold_limit,255,THRESH_BINARY);
	          //threshold(d2(frame,back),fore,threshold_limit,255,THRESH_BINARY);

	          // update the background
	          // temp=alpha*frame_gray+(1-alpha)*back;
	           //temp.copyTo(back);

	         //  frame_gray.copyTo(back,255-fore);
	        imshow(window_name,fore);



		if(waitKey(30) >= 0) break;
	       }

}

void Mixture_Of_Gaussian2()
{
	Mat frame;
    Mat back;
    Mat fore;
    VideoCapture cap(0);
    BackgroundSubtractorMOG2 bg;
    bg.nmixtures = 3;
    bg.bShadowDetection = false;
    bg.nShadowDetection=0;
    bg.varThreshold=16;

    bg.history=1000;
    std::vector<std::vector<Point> > contours;

    namedWindow("Frame");
    namedWindow("Background");

    for(;;)
    {
        cap >> frame;
        Mat substracted(frame.rows,frame.cols,CV_8UC3);
        substracted.setTo(Scalar(0,0,0));
        bg.operator ()(frame,fore,0.01);
        bg.getBackgroundImage(back);
     //   subtract(frame,back,fore);

       dilate(fore,fore,Mat());
       erode(fore,fore,Mat());

    // findContours(fore,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
      // drawContours(frame,contours,-1,Scalar(0,0,255),2);
    //    imshow("Frame",fore);
   //    frame.copyTo(substracted,fore);
      //  normalize(fore.clone(), fore, 0.0, 255.0, CV_MINMAX, CV_8UC1);

       frame.copyTo(substracted,fore);
       imshow("Frame",fore);

        imshow("Background",back);

        if(waitKey(30) >= 0) break;
    }
}

void changing_threshold(int pos,void* data){
	threshold_limit=pos;
		}
