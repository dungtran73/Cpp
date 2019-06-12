#pragma once
#include "Virus.h"
#include <iostream>
#include <list>

#define DIE 0
#define ALIVE 1
using namespace std;
class Patient
{
private:
	int m_resistence;
	list<Virus*> m_virusList;
	int m_state;
public:
	Patient();
	~Patient();
	void InitResistance();
	void DoStart();
	void TakeMedicine(int);
	void DoDie();
	int GetState();
};

