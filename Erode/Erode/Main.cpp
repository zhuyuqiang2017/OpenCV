#include <iostream>
#include <opencv2\opencv.hpp>
#include <string>
using namespace cv;
using namespace std;
int dilateSize = 1;
int erodeSize = 1;
char * dilateBar = "dilate_KSize";
char * dilate_window = "Dilate";
char * erodeBar = "erode_KSize";
char * erode_window = "Erode";
Mat source, dilate_result, erode_result,dilate_element,erode_element;
void onDilateCallBack(int position,void* userdata) {
	if (position <= 0) {
		position = 1;
	}
	dilateSize = position;
	dilate_element = getStructuringElement(MORPH_RECT, Size(dilateSize, dilateSize));
	dilate(source, dilate_result, dilate_element);
	imshow(dilate_window, dilate_result);
}

void onErodeCallBack(int position, void* userdata) {
	if (position <= 0) {
		position = 1;
	}
	erodeSize = position;
	erode_element = getStructuringElement(MORPH_RECT, Size(erodeSize, erodeSize));
	erode(dilate_result, erode_result, erode_element);
	imshow(erode_window, erode_result);
}

int main() {

	source = imread("tw.jpg", IMREAD_COLOR);
	dilate_result = Mat(source.rows,source.cols,CV_8UC3);
	cvNamedWindow(dilate_window, CV_WINDOW_AUTOSIZE);
	createTrackbar(dilateBar, dilate_window, &dilateSize, 50, onDilateCallBack);
	onDilateCallBack(1, dilateBar);
	cvNamedWindow(erode_window, CV_WINDOW_AUTOSIZE);
	createTrackbar(erodeBar, erode_window, &erodeSize, 50, onErodeCallBack);
	onErodeCallBack(1, erodeBar);
	waitKey(0);
	return 0;
}