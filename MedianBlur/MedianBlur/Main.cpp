#include <iostream>
#include <opencv2\opencv.hpp>
using namespace cv;
using namespace std;

const char* source_window = "source";
int initial_size = 1;
Mat source, result;
void onSizeChange(int position) {
	cout << " , initial_size = " << initial_size << endl;
	if (position == 0) {
		position = 1;
	}
	if (position%2 == 0) {
		position = position + 1;
	}

	initial_size = position;
	try {
		medianBlur(source, result, initial_size);
		imshow(source_window, result);
	}
	catch (Exception e) {
		std::cout << "Exception message = " << e.msg << std::endl;
	}
}

int main()
{
	source = imread("tw.jpg", IMREAD_UNCHANGED);
	result.create(source.rows, source.cols, source.type());
	cvNamedWindow(source_window, CV_WINDOW_AUTOSIZE);
	cvCreateTrackbar("changeSize", source_window, &initial_size, 100, onSizeChange);
	cvSetTrackbarPos("changeSize", source_window,2);
	waitKey(0);
	cvDestroyAllWindows();
	return 0;
}