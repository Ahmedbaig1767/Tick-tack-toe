#include<iostream>
using namespace std;
void printboard(int b[][3], int r)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (b[i][j] == 0)
			{
				cout << "_ ";
			}
			else if (b[i][j] == 1)
			{
				cout << "X ";
			}
			else
			{
				cout << "O ";
			}

		}
		cout << endl;
	}
}
bool check(int b[][3], int& who)
{
	for (int i = 0; i < 3; i++)
	{
		if ((b[i][0] == b[i][1]) && (b[i][2]) && (b[i][0] != 0))
		{
			who = b[i][0];
			return true;
		}
		if ((b[0][i] == b[1][i]) && (b[0][i] == b[2][i]) && (b[0][i] != 0))
		{
			who = b[0][i];
			return true;
		}
		
	
	}
	return false;

}
int main()
{
	int row, player = 1,who;
	int column;
	int board[3][3] = { 0 };
	printboard(board, 3);
	bool winner = 0;
	for (int i = 0; (i < 9)&&(winner==0); i++)
	{
		if (player == 1)
		{
			cout << "Enter row num and col number explicitly";
			cin >> row >> column;
			while (board[row][column] != 0)
			{
				cout << "Enter Again"<<endl;
				cin >> row >> column;
			}
			board[row][column] = 1;
			player = 2;
		}
		else
		{
			cout << "Enter row num and col number explicitly\t  "<<endl<<endl;
			cin >> row >> column;
			while (board[row][column] != 0)
			{
				cout << "Enter Again" << endl;
				cin >> row >> column;
			}
	
			board[row][column] = 2;
			player = 1;

		}
		printboard(board, 3);
		winner=check(board, who);
		if (winner)
		{
			cout << "Winner is player  " << who;
		}
	}
	
	return 0;
}