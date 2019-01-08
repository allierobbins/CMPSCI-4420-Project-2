/****************************************************************************
* Program 6 for 4420 Project 2												                      *
* Author: Allie Robbins													                          	*
* Language: C++ with OpenCV libraries								                     		*
* IDE: Visual Studio 2017												                           	*
* Purpose: Write functions to flip and flop an image in-place. 	 			      *
****************************************************************************/

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

//Prototypes for flip() and flop()
void flip(const cv::Mat& input, cv::Mat& output);
void flop(const cv::Mat& input, cv::Mat& output);

using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {

	//Get the input image in grey
	Mat image = imread(argv[1], IMREAD_GRAYSCALE);

	//Make the flipped and flopped images
	Mat flipped = Mat(image.size().height, image.size().width, CV_8UC1);
	Mat flopped = Mat(image.size().height, image.size().width, CV_8UC1);

	//Run flip() and flop()
	flip(image, flipped);
	flop(image, flopped);

	//Show the image results
	namedWindow("Flipped Image");
	namedWindow("Flopped Image");
	imshow("Flipped Image", flipped);
	imshow("Flopped Image", flopped);

	//Pause to look at the images
	waitKey(0);

	//End of file
	return 0;
}

//Flip function - turns image upside down
void flip(const Mat &input, Mat &output) {

	for (int i = 0; i < input.rows; i++) {
		for (int j = 0; j < input.cols; j++) {
			//Flip the pixel positions (pg. 72)
			output.at<uchar>(i, input.size().height - 1 - j) = input.at<uchar>(i, j);
		}
	}
}

//Flop Function - makes image mirrored
void flop(const Mat &input, Mat &output) {

	for (int i = 0; i < input.rows; i++) {
		for (int j = 0; j < input.cols; j++) {
			//Flop the pixel positions (pg. 72)
			output.at<uchar>(input.size().width - 1 - i, j) = input.at<uchar>(i, j);
		}
	}
}
