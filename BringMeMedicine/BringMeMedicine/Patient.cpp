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
	cout << "Virus: ";
	for (int i = 0; i < numOfviruses; i++)
	{
		Virus *vr;
		if (rand()%2==0)
		{
			vr = new FluVirus();
			m_virusList.push_back(vr);
			cout << vr->GetResistance() << " ";
		}
		else
		{
			vr = new Dengue();
			m_virusList.push_back(vr);
			cout << vr->GetResistance() << " ";
		}
	}
	cout << endl;
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
			(*it)->DoDie();
			temp = m_virusList.erase(it);
			it = temp;
		}
		else
		{
			list<Virus*> m_virusListTemp = (*it)->DoClone();
			m_virusList.insert(m_virusList.begin(), m_virusListTemp.begin(), m_virusListTemp.end());
			it++;
		}
		
	}
	for (list<Virus*>::iterator i = m_virusList.begin(); i != m_virusList.end(); i++)
	{
		TotalVirusResistance += (*i)->GetResistance();
		cout << (*i)->GetResistance() << "  ";
	}
	cout << "\nTotal Virus resistance: " << TotalVirusResistance;
	cout << endl;
	if (m_resistence<TotalVirusResistance)
	{
		DoDie();
	}
	
}

void Patient::DoDie()
{
	for (list<Virus*>::iterator i = m_virusList.begin(); i != m_virusList.end(); i++)
	{
		delete (*i);
	}
	m_virusList.clear();
	m_state = DIE;
}

int Patient::GetState()
{
	return m_state;
}

int Patient::GetResistance()
{
	return m_resistence;
}
