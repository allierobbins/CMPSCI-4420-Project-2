/****************************************************************************
* Program 1 for 4420 Project 2																							*
* Author: Allie Robbins																											*
* Language: C++ with OpenCV libraries																				*
* IDE: Visual Studio 2017																										*
* Purpose: Write a program to compare two grayscale images of the same size.*
* Compute the average distance between corresponding pixel intensity levels.*
****************************************************************************/

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

	//Declare needed variables (in order of use)
	int intensityLevel1 = 0;
	int intensityLevel2 = 0;
	int imageSize = 0;
	float avgIntensity1 = 0;
	float avgIntensity2 = 0;
	float avgDistance = 0;

	// Get grey images from command line
	Mat image1 = imread(argv[1], IMREAD_GRAYSCALE);
	Mat image2 = imread(argv[2], IMREAD_GRAYSCALE);

	//Loop through the images to add the values (in int)
	for (int i = 0; i < image1.rows; i++) {
		for (int j = 0; j < image1.cols; j++) {
			intensityLevel1 += image1.at<uchar>(i, j);
			intensityLevel2 += image2.at<uchar>(i, j);
		}
	}

	//Get the image size to use for calculatig the averages
	imageSize = image1.rows * image1.cols;

	//Find the average by dividing the sum by the size (in float)
	avgIntensity1 = float(intensityLevel1) / float(imageSize);
	avgIntensity2 = float(intensityLevel2) / float(imageSize);

	//Get the average distance of the two images
	avgDistance = abs(avgIntensity1 - avgIntensity2);

	//Print statistic
	printf("Average Distance: %g", avgDistance);

	//End of program 1
	return 0;
}
