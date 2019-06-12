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

float MyPoint::Distance(MyPoint p)
{
	float d = sqrt((p.GetX() - this->GetX)*(p.GetX() - this->GetX)
				  +(p.GetY() - this->GetY())*(p.GetY() - this->GetY()));
	return d;
}
