/*

 * distances.cpp
 *
 *  Created on: 25 oct. 2013
 *      Author: raiton
 */



#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
#include <stdio.h>
using namespace cv;


// d0 is used on grayscale iamges
Mat d0(Mat I,Mat B){
	return abs(I-B);
}

Mat d1(Mat I,Mat B){
    Mat result= Mat(I.rows,I.cols,CV_8U);

	for (int y = 0; y < I.rows; ++y) {
		for (int x = 0; x < I.cols; ++x) {
			Vec3b intensityI = I.at<Vec3b>(y, x);
			Vec3b intensityB = B.at<Vec3b>(y, x);
			result.at<uchar>(y,x)= abs(intensityI.val[0]-intensityB.val[0])+abs(intensityI.val[1]-intensityB.val[1])+ abs(intensityI.val[2]-intensityB.val[2]);
		}
	}

	return result;
}

Mat d2(Mat I,Mat B){
    Mat result= Mat(I.rows,I.cols,CV_8U);

	for (int y = 0; y < I.rows; ++y) {
		for (int x = 0; x < I.cols; ++x) {
			Vec3b intensityI = I.at<Vec3b>(y, x);
			Vec3b intensityB = B.at<Vec3b>(y, x);
			result.at<uchar>(y,x)=(intensityI.val[0]-intensityB.val[0])^2+(intensityI.val[1]-intensityB.val[1])^2+ (intensityI.val[2]-intensityB.val[2])^2;
		}
	}

	return result;
}
