#pragma once
#include "Virus.h"
#include <time.h>
#include <cstdlib>
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

