#include "FluVirus.h"



FluVirus::FluVirus()
{
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
}

void FluVirus::InitResistance()
{
}
