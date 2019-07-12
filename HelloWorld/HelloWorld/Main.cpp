#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include <iostream>

using namespace std;
using namespace cv;

bool gpu = true;
Stitcher::Mode mode = Stitcher::PANORAMA;
vector<Mat> images;

int main(int argc, char *argv[])
{
	Mat Part;
	for (int i = 1; i < argc; i++) {
		Part = imread(argv[i]);
		images.push_back(Part);
	}
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