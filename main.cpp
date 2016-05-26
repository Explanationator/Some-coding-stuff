#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int s = 1000;

bool isGameOver;
char matrix[s][s];
char turn;
char winner;
int vs = 4;
int x;
int y;
int k;
int l;
int m;
int n;
int o;
int p;

void setup()
{
	isGameOver = false;
	turn = 'X';
	for (int i = 0; i < vs; i++)
	{
		for (int j = 0; j < vs; j++)
		{
			matrix[i][j] = '-';
		}
	}
}
void display()
{
	for (int i = 0; i < vs; i++)
	{
		for (int j = 0; j < vs; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
//j = x; i = y;
void logic()
{
	for (int i = 0; i < vs; i++)
	{
		for (int j = 0; j < vs; j++)
		{
			k = i + 1;
			l = k + 1;
			m = j + 1;
			n = m + 1;
			o = i - 1;
			p = o - 1;
			if (((matrix[i][j] == 'X') && (matrix[k][j] == 'X') && (matrix[l][j] == 'X')) || ((matrix[i][j] == 'X') && (matrix[i][m] == 'X') && (matrix[i][n] == 'X')) || ((matrix[i][j] == 'X') && (matrix[k][m] == 'X') && (matrix[l][n] == 'X')) || ((matrix[i][j] == 'X') && (matrix[o][m] == 'X') && (matrix[p][n] == 'X')))
			{
				isGameOver = true;
				if (turn == 'O')
					winner = 'X';
				else if (turn == 'X')
					winner = 'O';
			}
			if (((matrix[i][j] == 'O') && (matrix[k][j] == 'O') && (matrix[l][j] == 'O')) || ((matrix[i][j] == 'O') && (matrix[i][m] == 'O') && (matrix[i][n] == 'O')) || ((matrix[i][j] == 'O') && (matrix[k][m] == 'O') && (matrix[l][n] == 'O')) || ((matrix[i][j] == 'O') && (matrix[o][m] == 'O') && (matrix[p][n] == 'O')))
			{
				isGameOver = true;
				if (turn == 'O')
					winner = 'X';
				else if (turn == 'X')
					winner = 'O';
			}
		}
	}
}

int main()
{
	cout << "Specify board size: ";
	cin >> vs;
	if (vs > s)
	{
		cout << "ERROR : The specified size cannot be over 1,000" << endl;
		system("pause");
		return 0;
	}
	system("CLS");
	setup();
	while (!isGameOver)
	{
		system("CLS");
		cout << "Currently " << turn << "'s turn. . ." << endl;
		display();
		x = 0;
		y = 0;
		cout << "Please input the column number: ";
		cin >> y;
		cout << "Please input the row number: ";
		cin >> x;
		x--; y--;
		if ((matrix[x][y] == '-') && (-1 < x < vs) && (-1 < y < vs))
		{
			matrix[x][y] = turn;
			if (turn == 'X')
				turn = 'O';
			else if (turn == 'O')
				turn = 'X';
		}
		logic();
	}
	system("CLS");
	cout << "GAME OVER" << endl;
	display();
	cout << "The winner is " << winner << endl;
	system("pause");
	return 0;
}