#include <iostream>
#include <conio.h>
#include <string.h>

//Co the thay doi kich thuoc ban co va so quan de thang
#define MAX 3 // Kich thuoc cua ban co 3x3
#define NUM 3 // So ki hieu lien tiep thang hang de thang game
using namespace std;

static int turn = 0;
char board[MAX][MAX];
char p1[20], p2[20];
char p1Play[3], p2Play[3];
int row, col;
bool result1, result2;
//bool isValid = false;

void DrawTable();
void ExitGame() {
	exit(0);
}

void InitBoard() {
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			board[i][j] = 'z';
		}
	}
}

bool EndGame() {
	if(result1==false && result2==false && turn<(MAX*MAX))
		return false;
	else
	{
		return true;
	}
}

void GameStart() {
	InitBoard();
	cout << "Welcome To Tic-tac-toe game! Play with your way!" << endl;
	cout << "If you find any problem, please contact trandung050797@gmail.com" << endl;
	cout << "SELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME):" << endl;
	int answer;
	cin >> answer;
	if (answer != 1)
	{
		ExitGame();
	}
	cout << "Enter Player 1 Name:" << endl;
	cin >> p1;
	cout << "Enter Player 2 Name:" << endl;
	cin >> p2;
	cin.ignore();
	system("cls");
	DrawTable();
}

bool CheckWin(char k,int row,int col) {
	
	int s = 0;
	//Kiem tra theo Cot
	//Ben Duoi
	for (int i = row; i < MAX; i++)
	{
		if (board[i][col]==k)
		{
			s++;
		}
		else
		{
			break;
		}
	}
	//Ben Tren
	for (int i = row-1; i >= 0; i--)
	{
		if (board[i][col] == k)
		{
			s++;
		}
		else
		{
			break;
		}
	}
	if (s == NUM)
		return true;
	//Kiem tra theo Hang
	s = 0;
	//Ben Phai
	for (int i = col; i < MAX; i++)
	{
		if (board[row][i] == k)
		{
			s++;
		}
		else
		{
			break;
		}
	}
	//Ben Trai
	for (int i = col-1; i >= 0; i--)
	{
		if (board[row][i] == k)
		{
			s++;
		}
		else
		{
			break;
		}
	}
	if (s == NUM)
		return true;
	//Kiem tra cheo TrenTrai-DuoiPhai
	s = 0;
	//Duoi Phai
	int jbr = col;
	for (int i = row; i < MAX; i++)
	{
		if (jbr<MAX)
		{
			if (board[i][jbr] == k)
			{
				s++;
			}
			else
			{
				break;
			}
		}
		jbr++;
	}
	//Tren Trai
	int jtl = col-1;
	for (int i = row-1; i >= 0; i--)
	{
		if (jtl>=0)
		{
			if (board[i][jtl] == k)
			{
				s++;
			}
			else
			{
				break;
			}
		}
		jtl--;
	}
	if (s == NUM)
		return true;
	//Kiem tra cheo DuoiTrai-TrenPhai
	s = 0;
	//Duoi Trai
	int jbl = col;
	for (int i = row; i < MAX; i++)
	{
		if (jbl>=0)
		{
			if (board[i][jbl] == k)
			{
				s++;
			}
		}
		else
		{
			break;
		}
		jbl--;
	}
	//Tren Phai
	int jtr = col+1;
	for (int i = row-1; i >= 0; i--)
	{
		if (jtr < MAX)
		{
			if (board[i][jtr] == k)
			{
				s++;
			}
		}
		else
		{
			break;
		}
		jtr++;
	}
	if (s == NUM)
		return true;
	//
	return false;
}

void Play() {
	while (!EndGame())
	{
		p1Turn:
		cout << "Your Turn " << p1 << ": - O" << endl;
		cin >> p1Play;
		if (!isdigit(p1Play[0]) || !isdigit(p1Play[1]))
		{
			cout << "Invalid input (number only)" << endl;
			goto p1Turn;
		}
		row = (atoi(p1Play) / 10) - 1;
		col = (atoi(p1Play) % 10) - 1;
		if (board[row][col] == 'z') {
			board[row][col] = 'O';
			DrawTable();
			//isValid = true;
			turn++;
			result1 = CheckWin('O', row, col);
			if (result1)
			{
				cout << p1<<" WIN!" << endl;
				break;
			}
		}
		else
		{
			cout << "Invalid input" << endl;
			goto p1Turn;
		}
		if (turn == (MAX*MAX))
		{
			break;
		}
		p2Turn:
		cout << "Your Turn " << p2 << ": - X" << endl;
		cin >> p2Play;
		//Chi cho phep nhap so
		if (!isdigit(p2Play[0]) || !isdigit(p2Play[1]))
		{
			cout << "Invalid input" << endl;
			goto p2Turn;
		}
		row = (atoi(p2Play) / 10) - 1;
		col = (atoi(p2Play) % 10) - 1;
		if (board[row][col] == 'z') {
			board[row][col] = 'X';
			DrawTable();
			//isValid = true;
			turn++;
			result2 = CheckWin('X', row, col);
			if (result2)
			{
				cout <<p2<< " WIN!" << endl;
				break;
			}
		}
		else
		{
			cout << "Invalid input"<<endl;
			goto p2Turn;
		}
	}
	if(!result1 && !result2)
		cout << "DRAW!" << endl;
}

void DrawTable() {
	system("cls");
	for (int i = 0; i < MAX; i++)
	{
		for (int k = 0; k < MAX; k++)
		{
			cout << "----";
		}
		cout << endl;
		for (int j = 0; j < MAX; j++)
		{
			cout << "| ";
			if (board[i][j] != 'z')
				cout << board[i][j]<<" ";
			else
				cout << "  ";
		}
		cout <<"|"<< endl;
	}
	for (int k = 0; k < MAX; k++)
	{
		cout << "----";
	}
	cout << endl;
}

int main() {
	GameStart();
	Play();
	
	getch();
}