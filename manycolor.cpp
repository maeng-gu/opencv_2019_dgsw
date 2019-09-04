
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//Debug x64 혹은 Release x64 권장

int main() {
	Mat mat21;

	mat21 = imread("apple.jpg");

	int count[256] = { 0, };

	for (int j = 0; j < mat21.rows; j++)
	{
		uchar *p = mat21.ptr<uchar>(j);
		for (int i = 0; i < mat21.cols; i++)
		{
			++count[p[i]];
		}
	}
	cout << "mat21 = " << mat21 << endl;
	return 0;
}
