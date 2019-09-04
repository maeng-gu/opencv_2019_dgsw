
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//Debug x64 혹은 Release x64 권장

int main() {


	Mat mat(1000, 1000, CV_8UC3);

	for (int i = 0; i < 1000; i+=2)
	{
		for (int j = 0; j < 1000; j+=2)
		{
			Mat m1 = mat(Range(i, i+2), Range(j, j+2));
			m1 = Scalar(rand() & 0xff, rand() & 0xff, rand() & 0xff);
			//랜덤으로 색을 넣는다.
		}
	}
	
	
	imshow("hi", mat);
	waitKey(10000);
	return 0;
}
