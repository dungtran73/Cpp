#include <stdio.h>
#include <cstdlib>
#include "Patient.h"
using namespace std;
int main()
{
	Patient p;
	char t = 0;
	/*while (p.GetState() == 1)
	{
		printf("Take Medicine (0 = NO, 1 = YES");
		scanf("%c", &t);
		if (t == 1)
		{
			int min = 1;
			int max = 60;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
				p.TakeMedicine(medicine_resistance);

		}
	}*/
	system("pause");
}