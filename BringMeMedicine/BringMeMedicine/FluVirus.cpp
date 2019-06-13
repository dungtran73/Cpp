#include "FluVirus.h"



FluVirus::FluVirus()
{
	DoBorn();
	DoClone();
}


FluVirus::~FluVirus()
{
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
