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
	m_state = ALIVE;
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
	int TotalVirusResistance = 0;
	list <Virus*>::iterator i;
	for  (i = m_virusList.begin(); i != m_virusList.end(); i++)
	{
		list<Virus*>::iterator temp;
		(*i)->ReduceResistance(medicine_resistance);
		if ((*i)->GetResistance()<=0)
		{
			temp=m_virusList.erase(i);
			i = temp;
		}
	}
	
	for (i = m_virusList.begin(); i != m_virusList.end(); i++)
	{
		TotalVirusResistance += (*i)->GetResistance();
		cout << (*i)->GetResistance() << " - ";
	}
	if (m_resistence<TotalVirusResistance)
	{
		DoDie();
	}
}

void Patient::DoDie()
{
	m_state = DIE;
	delete this;
}

int Patient::GetState()
{
	return m_state;
}
