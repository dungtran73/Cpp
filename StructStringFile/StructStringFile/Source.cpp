#include <iostream>

using namespace std;

struct Student
{
	int id;
	string name;
	float score;
};
void Input();
void Display();
void Save();
void Load();
void Exit();
void main()
{
	cout << "------------------MENU-------------------" << endl;
	cout << "\t1. Input" << endl;
	cout << "\t2. Display" << endl;
	cout << "\t3. Save to file" << endl;
	cout << "\t4. Load from file" << endl;
	cout << "\t0. Exit" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Choose: ";
	int answer;
	cin >> answer;
	switch (answer)
	{
	case 1:
		Input();
		break;
	case 2:
		Display();
		break;
	case 3:
		Save();
		break;
	case 4:
		Load();
		break;
	default:
		break;
	}
}

void Input()
{
}

void Display()
{
}

void Save()
{
}

void Load()
{
}

void Exit()
{
}
