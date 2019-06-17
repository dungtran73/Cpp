#pragma once
#include "Virus.h"

class Dengue:public Virus 
{
private:
	char m_protein[4];
public:
	Dengue();
	~Dengue();
	Dengue(Dengue *vr);
	void DoBorn();
	std::list<Virus*> DoClone();
	void DoDie();
	void InitResistance();

	int GetResistance();
};

