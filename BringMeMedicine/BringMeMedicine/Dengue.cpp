#include "Dengue.h"



Dengue::Dengue()
{
	DoBorn();
	InitResistance();
}


Dengue::~Dengue()
{
}

void Dengue::DoBorn()
{
	LoadADNInformation();
	srand(time(NULL));
	int kind = rand() % 3;
	if (kind==0)
	{
		strcpy(m_protein, "NS3");
	}
	else
	{
		if (kind==1)
		{
			strcpy(m_protein, "NS5");
		}
		else
		{
			strcpy(m_protein, "E");
		}
	}
}

void Dengue::DoClone()
{
}

void Dengue::DoDie()
{
	delete this;
}

void Dengue::InitResistance()
{
	srand(time(NULL));
	if (strcmp(m_dna,"NS3")==0)
	{
		m_resistance = rand() % 10 + 1;
	}
	else
	{
		if (strcmp(m_dna,"NS5")==0)
		{
			m_resistance = rand() % 10 + 11;
		}
		else
		{
			m_resistance = rand() % 10 + 21;
		}
	}
}
