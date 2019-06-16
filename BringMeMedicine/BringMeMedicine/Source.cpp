#include <stdio.h>
#include <cstdlib>
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
			int max = 6;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
				p.TakeMedicine(medicine_resistance);
				cout << "Medicin: " << medicine_resistance << endl;
		}
	}
	cout << p.GetState();
	system("pause");
}