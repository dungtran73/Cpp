#pragma once
#include <time.h>
#include <cstdlib>
#include <cstring>
class Virus
{
protected:
	char* m_dna;
	int m_resistance;
public:
	Virus();
	~Virus();
	Virus(Virus *a);
	void LoadADNInformation();
	void ReduceResistance(int);
	virtual void DoBorn() = 0;
	virtual void DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance()=0;
	virtual int GetResistance()=0;
};

