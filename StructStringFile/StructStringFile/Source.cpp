#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct Student
{
	int id;
	float score;
	string name;
};
Student *st;
static int s = -1; //So luong sinh vien trong mang
void Input();
void Display();
void Save();
void Load();
void Exit();
bool CheckId(int id);
void main()
{
	do {
		cout << "                 ------------------MENU-------------------" << endl;
		cout << "                      1. Input" << endl;
		cout << "                      2. Display" << endl;
		cout << "                      3. Save to file" << endl;
		cout << "                      4. Load from file" << endl;
		cout << "                      0. Exit" << endl;
		cout << "                 -----------------------------------------" << endl;
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
		case 0:
			Exit();
			break;
		default:
			break;
		}
	}
	while (true);
}

void Input()
{
	s++;
	
	Student *st_temp =new Student[s];
	if (s > 0)
	{
		//Sao chep data tu st sang st_temp
		for (int i = 0; i < s; i++)
		{
			(st_temp + i)->id = (st + i)->id;
			(st_temp + i)->name = (st + i)->name;
			(st_temp + i)->score = (st + i)->score;
		}
		// Tang kich thuoc cua mang
		st = new Student[s + 1];
		//Sao chep data tu st_temp sang st
		for (int i = 0; i < s; i++)
		{
			(st + i)->id = (st_temp + i)->id;
			(st + i)->name = (st_temp + i)->name;
			(st + i)->score = (st_temp + i)->score;
		}
	}
	else
		st = new Student[s + 1];
	int id_temp;
	do
	{
		cout << "Enter ID: ";
		cin >> id_temp;
		if (!CheckId(id_temp))
		{
			cout << "Duplicated student ID" << endl;
		}
	} while (!CheckId(id_temp));
	(st+s)->id = id_temp;
	cin.ignore();
	cout << "Enter full name: ";
	getline(cin,(st+s)->name);
	float scr;
	do
	{
		cout << "Enter score: ";
		cin >> scr;
		if (scr > 10 || scr < 0)
			cout << "Invalid input" << endl;
	} while (scr>10 ||scr<0);
	(st+s)->score = scr;
	//cin.ignore();
}

void Display()
{
	if (s<0)
	{
		cout << "Student list is empty!" << endl;
		
	}
	else
	{ 
		cout <<setw(10)<<left<<"ID"<<setw(35)<<left<<"FULL NAME"<<setw(5)<<left<<"SCORE"<< endl;
		for (int i = 0; i <= s; i++)
		{
			cout <<setw(10)<<left<< (st+i)->id <<setw(35)<<left << (st+i)->name << setw(5) <<left<< (st+i)->score << endl;
		}
	}
}

void Save()
{
	ofstream outfile;
	outfile.open("StudentList.txt",ios::app);
	if (outfile.is_open())
	{
		for (int i = 0; i <= s; i++)
		{
			outfile << (st + i)->id << " " << (st + i)->name << " " << (st + i)->score << endl;
		}
		cout << "Saved to StudentList.txt" << endl;
	}
	else
	{
		cout << "Error" << endl;
	}
}

void Load()
{
	
}

void Exit()
{
	delete[] st;
	exit(0);
}

bool CheckId(int id)
{
	for (int i = 0; i <= s; i++)
	{
		if (id==(st+i)->id)
		{
			return false;
		}
	}
	return true;
}
