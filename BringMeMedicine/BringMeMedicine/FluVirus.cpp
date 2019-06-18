#include "FluVirus.h"



FluVirus::FluVirus()
{
	DoBorn();
	InitResistance();
	//std::cout << m_dna<<std::endl;
}


FluVirus::~FluVirus()
{
}

FluVirus::FluVirus(FluVirus * vr)
{
	this->m_color = vr->m_color;
	this->m_dna = new char[strlen(vr->m_dna) + 1];
	for (int i = 0; i < strlen(vr->m_dna); i++)
	{
		this->m_dna[i] = vr->m_dna[i];
	}
	this->m_dna[strlen(vr->m_dna)] = '\0';

	this->m_resistance = vr->m_resistance;
}

void FluVirus::DoBorn()
{
	LoadADNInformation();
	int color = rand() % 2;
	m_color = (color == 0 ? 0xff0000 : 0x0000ff);
	InitResistance();
}

std::list<Virus*> FluVirus::DoClone()
{
	std::list<Virus*> m_virusListTemp;
	Virus *vr = new FluVirus(this);
	m_virusListTemp.push_front(vr);
	return m_virusListTemp;
}

void FluVirus::DoDie()
{
	delete m_dna;
	delete this;
}

void FluVirus::InitResistance()
{
	if (m_color == 0x0000ff)	//red virus
	{
		m_resistance = rand() % 11 + 10;
	}
	else
	{
		m_resistance = rand() % 11 + 5;
	}
}

int FluVirus::GetResistance()
{
	return m_resistance;
}
