#include "FluVirus.h"



FluVirus::FluVirus()
{
	DoBorn();
	DoClone();
}


FluVirus::~FluVirus()
{
}

FluVirus::FluVirus(FluVirus * vr)
{
	this->m_color = vr->m_color;
	strcpy(this->m_dna, vr->m_dna);
	this->m_resistance = vr->m_resistance;
}

void FluVirus::DoBorn()
{
	LoadADNInformation();
	srand(time(NULL));
	int color = rand() % 2;
	m_color = (color == 0 ? 0xff0000 : 0x0000ff);
}

void FluVirus::DoClone()
{

}

void FluVirus::DoDie()
{
	delete this;
}

void FluVirus::InitResistance()
{
	srand(time(NULL));
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
