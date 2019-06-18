#pragma once
#include "Virus.h"
#include <string.h>
class FluVirus:public Virus
{
private:
	int m_color; //0xff0000/ 0x0000ff
public:
	FluVirus();
	~FluVirus();
	FluVirus(FluVirus * vr);
	void DoBorn();
	std::list<Virus*> DoClone();
	void DoDie();
	void InitResistance();

	int GetResistance();
};

