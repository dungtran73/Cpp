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
int num;
void Replace(string &str, char to, char by);
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
void Replace(string &str,char to,char by)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i)==to)
		{
			str.at(i) = by;
		}
	}
}
void Input()
{
	s++;
	
	if (s > 0)
	{
		Student *st_temp = new Student[s];
		//Copy data from st to st_temp
		for (int i = 0; i < s; i++)
		{
			(st_temp + i)->id = (st + i)->id;
			(st_temp + i)->name = (st + i)->name;
			(st_temp + i)->score = (st + i)->score;
		}
		// Resize st
		st = new Student[s + 1];
		//Copy data from st_temp to st
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
	//Load();
	system("cls");
	if (s<0)
	{
		cout << "Student list is empty!" << endl;
		
	}
	else
	{ 
		cout <<setw(10)<<left<<"ID"<<setw(35)<<left<<"FULL NAME"<<setw(5)<<left<<"SCORE"<< endl;
		for (int i = 0; i < num+s; i++)
		{
			cout <<setw(10)<<left<< (st+i)->id <<setw(35)<<left << (st+i)->name << setw(5) <<left<< (st+i)->score << endl;
		}
	}
}

void Save()
{
	Load();
	ofstream outfile;
	outfile.open("StudentList.txt",ios::trunc);
	if (outfile.is_open())
	{
		outfile << s+1 << endl;
		for (int i = 0; i <= s; i++)
		{
			outfile << (st + i)->id << " ";
			string fullname((st + i)->name);
			Replace(fullname, ' ', '_');
			outfile << fullname << " " << (st + i)->score << endl;
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
	if (s<0)
	{
		s = 0;
	}
	
	ifstream infile;
	infile.open("StudentList.txt");
	if (infile.is_open())
	{
		infile >> num;
		Student *st_temp = new Student[num + s];
		if (num > 0)
		{
			//cout << num << endl;
			//Sao chep data tu file sang st_temp
			for (int i = 0; i <num; i++)
			{
				string fullname;
				Student *sv = new Student;
				infile >> sv->id;
				infile >> fullname;
				Replace(fullname, '_', ' ');
				sv->name = fullname;
				infile >> sv->score;
				(st_temp + i)->id = sv->id;
				(st_temp + i)->name = sv->name;
				(st_temp + i)->score = sv->score;
			}		
			int j = 0;
			//Sao chep data tu st sang st_temp
			for (int i = num; i <num + s; i++)
			{
				
				(st_temp + i)->id = (st + j)->id;
				(st_temp + i)->name = (st + j)->name;
				(st_temp + i)->score = (st + j)->score;
				j++;
			}
			// Tang kich thuoc cua mang
			st = new Student[num + s];
			//Sao chep data tu st_temp sang st
			for (int i = 0; i < num + s; i++)
			{
				(st + i)->id = (st_temp + i)->id;
				(st + i)->name = (st_temp + i)->name;
				(st + i)->score = (st_temp + i)->score;
			}
			cout << "Loaded data from StudentList.txt" << endl;
		}
		else
		{
			cout << "File is empty!" << endl;
		}
	}
	
	infile.close();
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
