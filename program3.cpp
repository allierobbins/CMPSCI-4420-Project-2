/************************************************************************************
* Program 3 for 4420 Project 2														                          *
* Author: Allie Robbins																                              *
* Language: C++ with OpenCV libraries												                        *
* IDE: Visual Studio 2017														                                *
* Purpose: Write a program that will provide some statistical information on gray	  *
*	  scale images. Find the average value of pixels and the standard deviation. Plot	*
*	  a 256×256 histogram with the data.												                      *
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

	//Declare needed variables (in order of use)
	int histogramArray[256];
	int intensityLevel = 0;
	int avgIntensity = 0;
	int imageSize = 0;
	double varience[256];
	double total = 0;
	double SD = 0;

	//Get the input image in grey
	Mat image = imread(argv[1], IMREAD_GRAYSCALE);

	//Create a 256x256 histogram
	Mat histogram = Mat::zeros(256, 256, CV_8UC1);

  //Get the intensity levels of the grey image
	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			histogramArray[image.at<uchar>(i, j)] += 1;
			intensityLevel += image.at<uchar>(i, j);
		}
	}

  //Find the image size
  imageSize = image.rows * image.cols;

	//Find the average by dividing the sum by the size
	avgIntensity = intensityLevel / imageSize;

	//Find the varience (sum of the differences^2) for standard deviation
	for (int i = 0; i < 256; i++) {
		varience[i] = pow(double(i) - double(avgIntensity), 2);
		total += varience[i];
	}

	//Find the mean of the differences
	total /= 256;

	//Find the standard deviation (square root of the varience)
	SD = sqrt(total);

	//Print statistics
	printf("Average grayscale value of pixels: %d", avgIntensity);
	printf("Standard Deviation: %g", SD);

	//Make the histogram w. line()
	for (int i = 0; i < 256; i++) {
		line(histogram, Point(i, 255), Point(i, 255 - histogramArray[i]), Scalar(255));
	}

	//Display the histogram
	namedWindow("Histogram");
	imshow("Histogram", histogram);

	//Pause to look at the histogram
	waitKey(0);

	//End of program 3
	return 0;
}
