/*****************************************************************************
* Program 2 for 4420 Project 2														                   *
* Author: Allie Robbins																                       *
* Language: C++ with OpenCV libraries											                 	 *
* IDE: Visual Studio 2017															                       *
* Purpose: Write a function to convert a color image to a greyscale image.	 *
*   Compute the distance of your greyscale-converted image from the					 *
*   grayscale conversion by OpenCV using the program from program1.cpp.			 *
******************************************************************************/

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
	float avgDistence = 0;

	//Get image file
	Mat image = imread(argv[1], IMREAD_GRAYSCALE);

	//Make an image to hold greyscale values
	Mat newGreyImage = image.clone();

	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			//Get the original RGB values of the pixel
			Vec3b intensity = image.at<Vec3b>(i, j);

			//Times RGB values by the equivalent greyscale multiplier
			uchar newBlue = intensity.val[0] * 0.11;
			uchar newGreen = intensity.val[1] * 0.59;
			uchar newRed = intensity.val[2] * 0.30;

			//Make new image grey by assignign new values to pixel
			newGreyImage.at<uchar>(i, j) = (newBlue + newGreen + newRed);
		}
	}

	//Convert the original image with cvtColor()
	Mat greyOpencvImage;
  cvtColor(image, greyOpencvImage, CV_BGR2GRAY);

	//Use function from program 1 to compare intensities
  int intensityLevel1 = 0;
  int intensityLevel2 = 0;
  int imageSize = 0;
  float avgIntensity1 = 0;
  float avgIntensity2 = 0;
  float avgDistance = 0;

  //Loop through the images to add the values (in int)
  for (int i = 0; i < newGreyImage.rows; i++) {
    for (int j = 0; j < greyOpencvImage.cols; j++) {
      intensityLevel1 += newGreyImage.at<uchar>(i, j);
      intensityLevel2 += greyOpencvImage.at<uchar>(i, j);
    }
  }

  //Get the image size to use for calculatig the averages
  imageSize = newGreyImage.rows * newGreyImage.cols;

  //Find the average by dividing the sum by the size (in float)
  avgIntensity1 = float(intensityLevel1) / float(imageSize);
  avgIntensity2 = float(intensityLevel2) / float(imageSize);

  //Get the average distance of the two images
  avgDistance = abs(avgIntensity1 - avgIntensity2);

	//Print statistic
	printf("Average Distance: %g", avgDistance);

	//End of program 2
	return 0;
}
