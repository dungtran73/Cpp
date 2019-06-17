#include "Dengue.h"



Dengue::Dengue()
{
	DoBorn();
	InitResistance();
}


Dengue::~Dengue()
{
}

Dengue::Dengue(Dengue * vr)
{
	this->m_dna = vr->m_dna;
	strcpy( this->m_protein,vr->m_protein);
	this->m_resistance = vr->m_resistance;
}

void Dengue::DoBorn()
{
	LoadADNInformation();
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

std::list<Virus*> Dengue::DoClone()
{
	std::list<Virus*> m_virusListTemp;
	Virus *vr = new Dengue(this);
	Virus *vr2 = new Dengue(this);
	m_virusListTemp.push_front(vr);
	m_virusListTemp.push_front(vr2);
	//push front to avoid looping over new element
	return m_virusListTemp;
}

void Dengue::DoDie()
{
	delete this;
}

void Dengue::InitResistance()
{
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

int Dengue::GetResistance()
{
	return m_resistance;
}
