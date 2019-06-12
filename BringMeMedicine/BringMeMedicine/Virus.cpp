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
	ifstream fp;
	fp.open("ATGX.bin", ios::in);
	if (fp.is_open)
	{
		fp >> m_dna;
	}
	else
	{
		cout << "Can not open file!\n";
	}
}

void Virus::ReduceResistance(int medicine_resistance)
{
	m_resistance -= medicine_resistance;
}
