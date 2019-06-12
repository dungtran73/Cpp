#include <iostream>
#include "MyPoint.h"
using namespace std;
void main()
{
	MyPoint *p1 = new MyPoint(4, 5);
	MyPoint *p2 = new MyPoint(1, 2);
	MyPoint *p3 = new MyPoint();
	cout << "P1 :";
	p1->Display();
	cout << "P2: ";
	p2->Display();
	p3->SetX(4);
	p3->SetY(2);
	cout << "P3: ";
	p3->Display();
	cout << "Distance between P1 and P2: " << p1->Distance(*p2) << endl;
	cout << "Distance between P1 and P3: " << p1->Distance(*p3) << endl;
	delete p1;
	delete p3;
	delete p2;
	system("pause");
}