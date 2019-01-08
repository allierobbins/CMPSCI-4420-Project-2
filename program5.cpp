/****************************************************************************
* Program 5 for 4420 Project 2												                      *
* Author: Allie Robbins														                          *
* Language: C++ with OpenCV libraries									                    	*
* IDE: Visual Studio 2017													                          *
* Purpose: Write a program to split a grayscale image into bit planes.		  *
*	Save the bit planes and display them on screen.		 				              	*
****************************************************************************/

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {

	//Declare needed variables (in order of use)
  bitset<8> value;
	string name = "Bit Plane # ";

	//Get the input image in grey
	Mat image = imread(argv[1], IMREAD_GRAYSCALE);

	//Make the 8 bit planes, starting at 0
	Mat plane0 = Mat(image.size().height, image.size().width, CV_8UC1);
	Mat plane1 = Mat(image.size().height, image.size().width, CV_8UC1);
	Mat plane2 = Mat(image.size().height, image.size().width, CV_8UC1);
	Mat plane3 = Mat(image.size().height, image.size().width, CV_8UC1);
	Mat plane4 = Mat(image.size().height, image.size().width, CV_8UC1);
	Mat plane5 = Mat(image.size().height, image.size().width, CV_8UC1);
	Mat plane6 = Mat(image.size().height, image.size().width, CV_8UC1);
	Mat plane7 = Mat(image.size().height, image.size().width, CV_8UC1);

	//Store the bit planes in an array for easy looping
	Mat bitPlanes[8] = {plane0, plane1, plane2, plane3, plane4, plane5, plane6, plane7};

	//Loop through for each bit plane and set binary (0/1) value
	for (int a = 0; a < 8; a++) {
		for (int i = 0; i < image.rows; i++) {
			for (int j = 0; j < image.cols; j++) {
				//find the pixel value from the grey image
				value(image.at<uchar>(i, j));

				//If the pixel is used → set the bit plane to white
				if (value[a] != 0) {
					bitPlanes[a].at<uchar>(i, j) = 255;
				} else { //or make it black
						bitPlanes[a].at<uchar>(i, j) = 0;
					}
			}
		}
	}

	//Display the bit planes in a loop, customize the name and use namedWindow + imshow
	for (int i = 0; i < 8; i++) {
		name += i;
		namedWindow(name, WINDOW_AUTOSIZE);
		imshow(name, bitPlanes[i]);
	}

	//Pause to look at the images
	waitKey(0);

	//End of file
	return 0;
}
