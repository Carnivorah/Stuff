#include<opencv2/opencv.hpp>
#include<iostream>
#include<conio.h>

int main() {
	cv::Mat imgOriginal;

	imgOriginal = cv::imread("image.png");

	cv::imshow("imgOriginal", imgOriginal);

	cv::waitKey(0);

	return(0);
}
