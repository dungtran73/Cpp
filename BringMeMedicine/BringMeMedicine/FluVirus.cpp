#include "FluVirus.h"



FluVirus::FluVirus()
{
	DoBorn();
	InitResistance();
}


FluVirus::~FluVirus()
{
}

FluVirus::FluVirus(FluVirus * vr)
{
	this->m_color = vr->m_color;
	this->m_dna = vr->m_dna;
	this->m_resistance = vr->m_resistance;
}

void FluVirus::DoBorn()
{
	LoadADNInformation();
	int color = rand() % 2;
	m_color = (color == 0 ? 0xff0000 : 0x0000ff);
	InitResistance();
}

void FluVirus::DoClone(std::list<Virus*> &m_virusList)
{
	Virus *vr = new FluVirus(this);
	m_virusList.push_front(vr);
}

void FluVirus::DoDie()
{
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
