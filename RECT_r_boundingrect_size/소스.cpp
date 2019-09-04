//A��B = A.���� * B.���� * cos(����)
//
//
//!!Point�� ������ �Ÿ� ���ϴ� �Լ�
//��Ÿ����� ���� �̿��ؼ�
//��(A ^ 2 + B ^ 2) = C
//
//X�� N�����ϴ� �Լ� powf(X, N)
//X�� ������ �� �ϴ� �Լ� sqrtf(X)

#include "opencv2/opencv.hpp"
#include <iostream>
#include <DirectXMath.h>//DirectX::XM_PI = 3.14

using namespace cv;
using namespace std;

//Debug x64 Ȥ�� Release x64 ����

int main(){
	Rect2f r(0, 0, 10, 20); //xywh

	float max_index = -1;//�ְ��� ����
	float max_area = -FLT_MAX; //�ְ��� ����

	for (float i = 0; i < 360; i = i + 0.001f)
	{
		RotatedRect rr{ Point2f{r.x + r.width / 2, r.y + r.height / 2}, Size2f{ r.width, r.height }, i };

		if (rr.boundingRect().area() > max_area) //������ ������ �� ������ �ִ� ���� , ���ݱ����� �ִ� ����
		{
			max_area = rr.boundingRect().area();
			max_index = i;
		}
	
	}

	cout << max_index << "deg" << max_area << endl;

	waitKey();
}