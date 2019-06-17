#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include "Patient.h"
#include <vld.h>
using namespace std;
int main()
{
	srand(time(0));
	Patient *p=new Patient();
	int t = 0;
	while (p->GetState() == 1)
	{
		printf("Take Medicine (0 = NO, 1 = YES) ");
		scanf("%d", &t);
		if (t == 1)
		{
			int min = 1;
			int max = 60;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			cout << "Person resistance: " << p->GetResistance() << endl;
			cout << "Medicin: " << medicine_resistance << endl;
			p->TakeMedicine(medicine_resistance);
		}

	}
	cout << "State :" << p->GetState()<<endl;
	delete p;
	system("pause");
}