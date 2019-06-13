#pragma once
#include "Virus.h"
class Dengue:public Virus 
{
private:
	char m_protein[4];
public:
	Dengue();
	~Dengue();
	void DoBorn();
	void DoClone();
	void DoDie();
	void InitResistance();
};

