#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;
const char* source_window = "source_window";
Mat source, result;


int main() {

	source = imread("tw.jpg", 0);
	cvNamedWindow(source_window, CV_WINDOW_AUTOSIZE);
	cvMoveWindow(source_window,0,0);
	bilateralFilter(source,source,15,40.0,10.0);
	imshow(source_window,source);
	waitKey(0);

	return 0;
}