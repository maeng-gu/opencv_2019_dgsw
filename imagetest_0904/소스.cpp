#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//Debug x64 혹은 Release x64 권장
int main() {
	std::cout << "Hello opencv world!" << CV_VERSION << std::endl;

	Mat img1(480, 640, CV_8UC1);

	Mat img2(480, 640, CV_8UC3);

	Mat img3(Size(640, 480), CV_8UC3);

	Mat img4(480, 640, CV_8UC1, Scalar(128));

	Mat img5(480, 640, CV_8UC3, Scalar(0, 0, 255));

	Mat img6 = Mat::zeros(480, 640, CV_32FC1);

	Mat img7 = Mat::ones(480, 640, CV_32FC1);

	Mat img8 = Mat::eye(480, 640, CV_32FC1);

	float data[] = { 1,2,3,4,5,6 };
	Mat img9(2, 3, CV_32FC1, data);

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);
	imshow("img5", img5);

	waitKey();

//	int data2[] = { 1,2,3,4,5,6 };
//	Mat img10(2, 3, CV_16UC1, data); //결과 확인해보자

	return 0;
}