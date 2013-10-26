/*
 * skin_detection.cpp
 *
 *  Created on: 25 oct. 2013
 *      Author: raiton
 */



#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
#include <stdio.h>
using namespace cv;

Mat skin_detection(Mat I){
 Mat result= Mat(I.rows,I.cols,CV_8U);
 //Mat result= Mat(I.rows,I.cols,CV);

 result.setTo(0);

	for (int y = 0; y < I.rows; ++y) {
		for (int x = 0; x < I.cols; ++x) {
			Vec3b intensityI = I.at<Vec3b>(y, x);
			uchar B=intensityI.val[0];
			uchar G=intensityI.val[1];
			uchar R=intensityI.val[2];

				if ((R > 95) and (G >40) and (B>20) and (max(R,max(G,B))-min(R,min(G,B))>15) and (abs(R-G)>15) and (R >G) and (R>B)){
							result.at<uchar>(y,x)=255;
			}

		}
	}

	return result;

}
