
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//Debug x64 혹은 Release x64 권장
int main() {
	Point pt1;
	cout << "pt1(x, y) = " << pt1.x << ", " << pt1.y << endl;
	Point pt2(1, 1);
	cout << "pt2(x, y) = " << pt2.x << ", " << pt2.y << endl;
	Point pt3(pt2);
	cout << "pt3(x, y) = " << pt3.x << ", " << pt3.y << endl;
	Point pt4 = pt3;
	cout << "pt4(x, y) = " << pt4.x << ", " << pt4.y << endl;

}