//사진 보여주기 및 버전 보여주기
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	std::cout << "hello opencv world" << CV_VERSION << std::endl;

	Mat img;
	img = imread("apple.jpg");
	if (img.empty()) {
		cerr << "Image load failed" << endl;
		return -1;
	}
	//namedWindow("apple");
	vector<int>params;
	params.push_back(IMWRITE_JPEG_QUALITY);
	params.push_back(1);
	imwrite("apple2.jpg", img, params);
	imshow("apple", img);
	waitKey();


	return 0;
}