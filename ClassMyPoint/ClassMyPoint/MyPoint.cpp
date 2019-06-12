#include "MyPoint.h"
#include <iostream>
#include <math.h>
using namespace std;


MyPoint::MyPoint()
{
}


MyPoint::~MyPoint()
{
}

MyPoint::MyPoint(int x, int y)
{
	mPosX = x;
	mPosY = y;
}

void MyPoint::Display()
{
	cout << "(" << mPosX << "," << mPosY << ")" << endl;
}

void MyPoint::SetX(int x)
{
	mPosX = x;
}

int MyPoint::GetX()
{
	return mPosX;
}

void MyPoint::SetY(int y)
{
	mPosY = y;
}

int MyPoint::GetY()
{
	return mPosY;
}

float MyPoint::Distance( MyPoint p)
{
	float x1 = this->GetX(),
		x2 = p.GetX();
	float y1 = this->GetY(),
		y2 = p.GetY();
	float d = sqrt(( x2 - x1 )*(x2 - x1)
				  +(y2 - y1)*(y2 - y1));
	return d;
}
