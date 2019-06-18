#include "Virus.h"
#include <iostream>
#include <fstream>
using namespace std;


Virus::Virus()
{
}


Virus::~Virus()
{
}

Virus::Virus(Virus * a)
{
	m_dna = a->m_dna;
	m_resistance = a->m_resistance;
}

void Virus::LoadADNInformation()
{
	//==================
	FILE *fp = fopen("ATGX.bin", "r");
	char ch;
	if (fp != nullptr)
	{
		int len = 0;
		while ((ch = getc(fp)) != EOF)
		{
			cout << ch;
			len++;
		}
		m_dna = new char[len + 1];

		int i = 0;
		fseek(fp, 0, SEEK_SET);
		while ((ch = getc(fp)) != EOF)
		{
			m_dna[i] = ch;
			i++;
		}
		m_dna[len] = '\0';
		fclose(fp);
	}
	else
	{
		cout << "Can not open file";
	}
	//===================
}

void Virus::ReduceResistance(int medicine_resistance)
{
	m_resistance -= medicine_resistance;
}
