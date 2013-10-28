/*
 * noise_reduction.cpp
 *
 *  Created on: 24 oct. 2013
 *      Author: raiton
 */

#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
#include <opencv2/nonfree/features2d.hpp>
#include "noise_reduction.hpp"
#include "skin_detection.hpp"
#include "BackgroundSubstractor.hpp"
#include <list>


using namespace cv;
using namespace std;


void calcule_neighbours(Mat frame,int posx,int posy,int width, int height,list<pair<int,int> >* neighbours );

Mat simple_noise_reduction(Mat frame) {
	for (int y = 0; y < frame.rows; ++y) {
			for (int x = 0; x < frame.cols; ++x) {
				if (frame.at<uchar>(y,x) > 0){
				//	printf("%u",frame.at<uchar>(y,x));
					int S=0;
					list<pair<int,int> > neighbours;
					calcule_neighbours(frame,x,y,frame.cols,frame.rows,& neighbours);
					  for (std::list<pair<int,int> >::iterator it = neighbours.begin(); it != neighbours.end(); it++){
						  if (frame.at<uchar>((*it).second,(*it).first)==255){
							  S++;
						  }
					}
					if (S==0){
						frame.at<uchar>(y,x)=0;
					}
				}
			}
		}




	return frame;
}

void calcule_neighbours(Mat frame,int posx,int posy,int width, int height,list<pair<int,int> >* neighbours ){


	//introduction of chained lists
	//able to do recursive loops
	//4-connectivity

	if (posy>0){
		neighbours->push_back(make_pair(posx,posy-1));
	}
	if (posx>0){
		neighbours->push_back(make_pair(posx-1,posy));

	}
	if (posy<height-1){
		neighbours->push_back(make_pair(posx,posy+1));

		}
	if (posx<width-1){
		neighbours->push_back(make_pair(posx+1,posy));

		}
	//end of 4-connectivity

	//begin of 8-connectivity

//	if ((posy>0) and (posx>0)){
//		neighbours->push_back(make_pair(posx-1,posy-1));
//	}
//	if ((posy<height-1) and (posx>0)){
//		neighbours->push_back(make_pair(posx+1,posy-1));
//
//	}
//	if ((posy<height-1) and (posx<width-1)){
//		neighbours->push_back(make_pair(posx+1,posy+1));
//
//		}
//	if ((posx<width-1) and (posy>0)){
//		neighbours->push_back(make_pair(posx+1,posy-1));
//
//		}

	//end of 8-connectivity

}

