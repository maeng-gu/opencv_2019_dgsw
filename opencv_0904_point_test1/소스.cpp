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

class _3{
public:
	Point A, B, C; //포인터 변수 3개
	
};

struct _3Angle {
	float AB, BC, AC;
};

int check(int a, int b, int c){ //예각 둔각 판별
	if (a < 90 && b < 90 && c < 90)
	{
		return 0;
	}
	else if (a > 90 || b > 90 || c > 90)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

float get_length(int x, int y)
{
	return (sqrtf(powf(x, 2) + powf(y, 2)));
}

_3Angle get(_3 O) {


	Point newC, newB, newA;

	float AB; //A와 B의 사이각
	float AC; //A와 C의 사이각
	float BC; //B와 C의 사이각

	//CAB 구하기
	{
		newA = O.A - O.A; //0으로 만들기
		newB = O.B - O.A; //이동
		newC = O.C - O.A; //이동

		float disB = get_length(newB.x, newB.y);//B와 원점사이의 거리
		float disC = get_length(newC.x, newC.y);//C와 원점사이의 거리

		//B 와 C의 내적 = A의 길이 * B의 길이 * cos(A와 B 사이각)
		///BC = newA.dot(newB);

		///BC / disC / disB;  = Cos(B와 C의 사이각)
		///float rad = acos(AB / disC / disB); //A와 B의 사이각 그러나! 라디안임
		BC = acos(newB.dot(newC) / disC / disB) / DirectX::XM_PI * 180; //C와 B의 사이각 360도!

	}
	//ABC 구하기
	{
		newA = O.A - O.B;
		newB = O.B - O.B;
		newC = O.C - O.B;

		float disA = get_length(newA.x, newA.y);
		float disC = get_length(newC.x, newC.y);

		AC = acos(newA.dot(newC) / disC / disA) / DirectX::XM_PI * 180; //A와 C의 사이각 360도!

	}

	//ACB 구하기
	{
		newA = O.A - O.C;
		newB = O.B - O.C;
		newC = O.C - O.C;

		float disB = get_length(newB.x, newB.y);
		float disA = get_length(newA.x, newA.y);

		AB = acos(newB.dot(newA) / disA / disB) / DirectX::XM_PI * 180; //A와 B의 사이각 360도!

	}

	cout << "AB 사이각 = " << AB << endl;
	cout << "AC 사이각 = " << AC << endl;
	cout << "BC 사이각 = " << BC << endl;

	return {AB, BC, AC};
}


int main() {
	_3 O;

	O.A = { 1,0 };
	O.B = { 2,0 };
	O.C = { 2, 1 }; //좌표

	//var 
	auto temp = get(O);

	cout << check(temp.AB, temp.AC, temp.BC) << endl;
	waitKey();
}