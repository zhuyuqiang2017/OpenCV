#include <iostream>
#include <opencv2\opencv.hpp>
using namespace cv;
using namespace std;

const char* source_window = "source";
int initial_size = 1;
int x = 0;
int y = 0;
Mat source, result;
void onSizeChange(int position) {
	cout << "y = " << x;
	cout << " , x = " << y;
	cout << " , initial_size = " << initial_size << endl;
	if (position == 0) {
		position = 1;
	}
	if (position%2 == 0) {
		position += 1;
	}
	
	initial_size = position;
	try {
		GaussianBlur(source, result, Size(initial_size, initial_size),x,y);
		imshow(source_window, result);
	}
	catch (Exception e) {
		std::cout << "Exception message = " << e.msg << std::endl;
	}
}

void onXChange(int position) {
	cout << "y = " << x;
	cout << " , x = " << y;
	cout << " , initial_size = " << initial_size << endl;
	x = position;
	try {
		GaussianBlur(source, result, Size(initial_size, initial_size), x, y);
		imshow(source_window, result);
	}
	catch (Exception e) {
		std::cout << "Exception message = " << e.msg << std::endl;
	}
}
void onYChange(int position) {
	cout << "y = " << x;
	cout << " , x = " << y;
	cout << " , initial_size = " << initial_size << endl;
	y = position;
	try {
		GaussianBlur(source, result, Size(initial_size, initial_size), x, y);
		imshow(source_window, result);
	}
	catch (Exception e) {
		std::cout << "Exception message = " << e.msg << std::endl;
	}
}
int main()
{
	source = imread("fifth.jpg", IMREAD_UNCHANGED);
	result.create(source.rows, source.cols, source.type());
	cvNamedWindow(source_window, CV_WINDOW_AUTOSIZE);
	cvCreateTrackbar("changeSize", source_window, &initial_size, 100, onSizeChange);
	cvCreateTrackbar("x方向方差", source_window, &x, 100, onXChange);
	cvCreateTrackbar("y方向方差", source_window, &y, 100, onYChange);
	cvSetTrackbarPos("changeSize", source_window, 0);
	cvSetTrackbarPos("x方向方差", source_window, 0);
	cvSetTrackbarPos("y方向方差", source_window, 0);
	waitKey(0);
	cvDestroyAllWindows();
	return 0;
}