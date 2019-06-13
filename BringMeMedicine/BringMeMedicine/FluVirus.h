#pragma once
#include "Virus.h"

class FluVirus:public Virus
{
private:
	int m_color; //0xff0000/ 0x0000ff
public:
	FluVirus();
	~FluVirus();
	void DoBorn();
	void DoClone();
	void DoDie();
	void InitResistance();
};

