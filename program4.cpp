/************************************************************************************
* Program 4 for 4420 Project 2														                          *
* Author: Allie Robbins																                              *
* Language: C++ with OpenCV libraries									                        			*
* IDE: Visual Studio 2017															                              *
* Purpose: Write a program to subsample a grayscale image by removing alternate	  	*
*	  rows and columns.  														                                  *
*************************************************************************************/

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {

	//Get the input image in grey
	Mat image = imread(argv[1], IMREAD_GRAYSCALE);

	//Create the subsampled image
	Mat subsample = Mat(image.size().height / 2, image.size().width / 2, CV_8UC1);

	//Get the subsample of the original image by adding alternative lines to the image
	for (int i = 0; i < subsample.rows; i++) {
		for (int j = 0; j < subsample.cols; j++) {
			subsample.at<uchar>(i, j) = image.at<uchar>(i * 2, j * 2);
		}
	}

	//Display the origianl image & the subsample image
	namedWindow("Original Image");
	namedWindow("Subsample Image");
	imshow("Original Image", image);
	imshow("Subsample Image", subsample);

	//Pause to look at the histogram
	waitKey(0);

	//End of program 4
	return 0;
}
