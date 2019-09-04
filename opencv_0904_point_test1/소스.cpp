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

class _3{
public:
	Point A, B, C; //������ ���� 3��
	
};

struct _3Angle {
	float AB, BC, AC;
};

int check(int a, int b, int c){ //���� �а� �Ǻ�
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

	float AB; //A�� B�� ���̰�
	float AC; //A�� C�� ���̰�
	float BC; //B�� C�� ���̰�

	//CAB ���ϱ�
	{
		newA = O.A - O.A; //0���� �����
		newB = O.B - O.A; //�̵�
		newC = O.C - O.A; //�̵�

		float disB = get_length(newB.x, newB.y);//B�� ���������� �Ÿ�
		float disC = get_length(newC.x, newC.y);//C�� ���������� �Ÿ�

		//B �� C�� ���� = A�� ���� * B�� ���� * cos(A�� B ���̰�)
		///BC = newA.dot(newB);

		///BC / disC / disB;  = Cos(B�� C�� ���̰�)
		///float rad = acos(AB / disC / disB); //A�� B�� ���̰� �׷���! ������
		BC = acos(newB.dot(newC) / disC / disB) / DirectX::XM_PI * 180; //C�� B�� ���̰� 360��!

	}
	//ABC ���ϱ�
	{
		newA = O.A - O.B;
		newB = O.B - O.B;
		newC = O.C - O.B;

		float disA = get_length(newA.x, newA.y);
		float disC = get_length(newC.x, newC.y);

		AC = acos(newA.dot(newC) / disC / disA) / DirectX::XM_PI * 180; //A�� C�� ���̰� 360��!

	}

	//ACB ���ϱ�
	{
		newA = O.A - O.C;
		newB = O.B - O.C;
		newC = O.C - O.C;

		float disB = get_length(newB.x, newB.y);
		float disA = get_length(newA.x, newA.y);

		AB = acos(newB.dot(newA) / disA / disB) / DirectX::XM_PI * 180; //A�� B�� ���̰� 360��!

	}

	cout << "AB ���̰� = " << AB << endl;
	cout << "AC ���̰� = " << AC << endl;
	cout << "BC ���̰� = " << BC << endl;

	return {AB, BC, AC};
}


int main() {
	_3 O;

	O.A = { 1,0 };
	O.B = { 2,0 };
	O.C = { 2, 1 }; //��ǥ

	//var 
	auto temp = get(O);

	cout << check(temp.AB, temp.AC, temp.BC) << endl;
	waitKey();
}