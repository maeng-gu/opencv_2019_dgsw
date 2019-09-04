//A·B = A.길이 * B.길이 * cos(각도)
//
//
//!!Point와 원점의 거리 구하는 함수
//피타고라스의 정리 이용해서
//√(A ^ 2 + B ^ 2) = C
//
//X를 N제곱하는 함수 powf(X, N)
//X를 제곱근 을 하는 함수 sqrtf(X)

#include "opencv2/opencv.hpp"
#include <iostream>
#include <DirectXMath.h>//DirectX::XM_PI = 3.14

using namespace cv;
using namespace std;

//Debug x64 혹은 Release x64 권장

int main(){
	Rect2f r(0, 0, 10, 20); //xywh

	float max_index = -1;//최고의 각도
	float max_area = -FLT_MAX; //최고의 넓이

	for (float i = 0; i < 360; i = i + 0.001f)
	{
		RotatedRect rr{ Point2f{r.x + r.width / 2, r.y + r.height / 2}, Size2f{ r.width, r.height }, i };

		if (rr.boundingRect().area() > max_area) //도형을 돌렸을 때 나오는 최대 넓이 , 지금까지의 최대 넓이
		{
			max_area = rr.boundingRect().area();
			max_index = i;
		}
	
	}

	cout << max_index << "deg" << max_area << endl;

	waitKey();
}