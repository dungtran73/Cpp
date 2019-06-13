#include "Patient.h"


#define DIE 0
#define ALIVE 1
Patient::Patient()
{
	InitResistance();
	DoStart();
}


Patient::~Patient()
{
}

void Patient::InitResistance()
{
	m_resistence = rand() % 8001 + 1000;
}

void Patient::DoStart()
{
	int numOfviruses = rand() % 11 + 10;
	for (int i = 0; i < numOfviruses; i++)
	{
		Virus *vr;
		if (rand()%2==0)
		{
			vr = new FluVirus();
			m_virusList.push_back(vr);
		}
		else
		{
			vr = new Dengue();
			m_virusList.push_back(vr);
		}
	}
}

void Patient::TakeMedicine(int medicine_resistance)
{
	list <Virus*>::iterator i;
	for  (i = m_virusList.begin(); i != m_virusList.end(); i++)
	{
		(*i)->ReduceResistance(medicine_resistance);
	}
}

void Patient::DoDie()
{
}

int Patient::GetState()
{
	return m_state;
}

