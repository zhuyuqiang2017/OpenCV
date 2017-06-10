#include <iostream>
#include <opencv2\opencv.hpp>
using namespace cv;
using namespace std;

const char* source_window = "source";
int initial_size = 1;
Mat source, result;
void onSizeChange(int position) {
	if (position == 0) {
		position = 1;
	}
	cout << "position" << position << endl;
	initial_size = position;
	try {
		blur(source, result, Size(initial_size, initial_size),Point(-1,-1));
		imshow(source_window, result);
	}
	catch (Exception e) {
		std::cout << "Exception message = " << e.msg << std::endl;
	}
}
int main()
{
	source = imread("test_clear.jpg", IMREAD_UNCHANGED);
	result.create(source.rows,source.cols,source.channels());
	cvNamedWindow(source_window, CV_WINDOW_AUTOSIZE);
	cvCreateTrackbar("changeSize", source_window, &initial_size, 100, onSizeChange);
	cvSetTrackbarPos("changeSize", source_window, 80);
	imwrite("test_blur.jpg",result);
	waitKey(0);
	return 0;
}
