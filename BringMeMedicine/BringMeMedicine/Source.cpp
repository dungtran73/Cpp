#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include "Patient.h"
using namespace std;
int main()
{
	srand(time(0));
	Patient p;
	int t = 0;
	while (p.GetState() == 1)
	{
		printf("Take Medicine (0 = NO, 1 = YES) ");
		scanf("%d", &t);
		if (t == 1)
		{
			int min = 1;
			int max = 60;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			cout << "Person resistance: " << p.GetResistance() << endl;
			cout << "Medicin: " << medicine_resistance << endl;
			p.TakeMedicine(medicine_resistance);
		}
	}
	cout << p.GetState();

	system("pause");
}