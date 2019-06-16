#pragma once
#include "Virus.h"

class FluVirus:public Virus
{
private:
	int m_color; //0xff0000/ 0x0000ff
public:
	FluVirus();
	~FluVirus();
	FluVirus(FluVirus * vr);
	void DoBorn();
	void DoClone(std::list<Virus*> &m_virusList);
	void DoDie();
	void InitResistance();

	int GetResistance();
};

