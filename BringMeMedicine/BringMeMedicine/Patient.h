#pragma once
#include "Virus.h"
#include "FluVirus.h"
#include "Dengue.h"
#include <iostream>
#include <list>

#define DIE 0
#define ALIVE 1
using namespace std;
class Patient
{
private:
	int m_resistence;
	
	int m_state;
public:
	Patient();
	~Patient();
	list<Virus*> m_virusList;
	void InitResistance();
	void DoStart();
	void TakeMedicine(int);
	void DoDie();
	int GetState();
	int GetResistance();
};

