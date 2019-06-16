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
	list<Virus*>::iterator it = m_virusList.begin();
	while (it != m_virusList.end())
	{
		list<Virus*>::iterator temp;
		(*it)->ReduceResistance(medicine_resistance);
		if ((*it)->GetResistance() <= 0)
		{
			temp = m_virusList.erase(it);
			it = temp;
		}
		else
		{
			it++;
		}
	}
	for (list<Virus*>::iterator i = m_virusList.begin(); i != m_virusList.end(); i++)
	{
		TotalVirusResistance += (*i)->GetResistance();
		cout << (*i)->GetResistance() << "  ";
	}
	cout << endl;
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
