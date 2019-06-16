#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <list>
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
	virtual void DoClone(std::list<Virus*> &m_virusList) = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance()=0;
	virtual int GetResistance()=0;
};

