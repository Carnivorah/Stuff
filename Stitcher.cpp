#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include <iostream>

using namespace std;
using namespace cv;

bool gpu = false;
Stitcher::Mode mode = Stitcher::PANORAMA;
vector<Mat> images;

int main(Mat Part1, Mat Part2, Mat Part3)
{
	images.push_back(Part1);
	images.push_back(Part2);
	images.push_back(Part3);
	Mat result;
	Ptr<Stitcher> stitcher = Stitcher::create(mode, gpu);
	Stitcher::Status status = stitcher->stitch(images, result);
	if (status != Stitcher::OK)
	{
		cout << "Can't stitch images, error code = " << int(status) << endl;
		return EXIT_FAILURE;
	}
	imwrite("result.png", result);
	cout << "stitching completed successfully\n Result.png saved!";
	return EXIT_SUCCESS;
}
