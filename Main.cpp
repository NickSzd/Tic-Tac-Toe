#include<iostream>
#include<string>
using namespace std;

class board
{
	
public:
	
	char bd[9] = { '1','2','3','4','5','6','7','8','9' };
	void genBoard(); // Creates the board
	void clrBoard(); // Clears the board
	bool win(); // checks for a win
	
};

class player : public board
{
	char symbol1 = 'X'; // player symbols
	char  symbol2 = 'O';
public:
	void mark(int i);
};


void board::genBoard()// displays the board
{
	system("cls");
	cout << bd[0] << "|" << bd[1] << "|" << bd[2] << endl;
	cout << "-|-|-" << endl;
	cout << bd[3] << "|" << bd[4] << "|" << bd[5] << endl;
	cout << "-|-|-" << endl;
	cout << bd[6] << "|" << bd[7] << "|" << bd[8] << endl;
}

void board :: clrBoard() // clears the board
{
	for (int i = 1; i < 10; i++)
	{
		bd[i] = i;
	}
}

bool board::win()
{
	//Horiziontal Win Conditions
	if (bd[0] == bd[1] && bd[1] == bd[2])
		return true;
	else if (bd[3] == bd[4] && bd[4] == bd[5])
		return true;
	else if (bd[6] == bd[7] && bd[7] == bd[8])
		return true;
	//vertical win conditions
	else if (bd[0] == bd[3] && bd[3] == bd[6])
		return true;
	else if (bd[1] == bd[4] && bd[4] == bd[7])
		return true;
	else if (bd[2] == bd[5] && bd[5] == bd[8])
		return true;
	//Diagonal Win Conditions
	else if (bd[0] == bd[4] && bd[4] == bd[8])
		return true;
	else if (bd[2] == bd[4] && bd[4] == bd[6])
		return true;
	/*count++;
	if (count == 9)
	{
		cout << "It is a draw" << endl;
	}
	*/
}

void player::mark(int i)
{
	int mk;
	if (i == 1 || i == 3 || i == 5 || i == 7) // asks if it is X or O turn
	{
		cout << "Enter your cord: ";
		cin >> mk;
		if (bd[mk] == 'O')// checks the pos
		{
			cout << "Invalid Position Choose Again: ";
			cin >> mk;
			bd[mk - 1] = symbol1;
		}
		else
			bd[mk - 1] = symbol1;
	}
	
	if (i == 2 || i == 4 || i == 6 || i == 8)
	{
		cout << "Enter your cord: ";
		cin >> mk;
		if (bd[mk -1] == 'X') // checks if the pos has  been choosen
		{
			cout << "Invalid Position Choose Again: ";
			cin >> mk;
			bd[mk - 1] = symbol2;
		}
		else
			bd[mk - 1] = symbol2;
	}
}



void main()
{
	
	int f = 1;
	int ck;

	player x;
	for (int i = 0; i < 9; i++) // game has a max of 9 turns 
	{
		x.genBoard();
		x.mark(i);
		x.win();
		if (x.win() == true)
		{
			x.genBoard();
			if (i % 2 != 0)
				cout << "Player X WIns" << endl;
			else
				cout << "Player O wins" << endl;
			i = 9;
		}
		if (i == 8)
		{
			x.genBoard();
			cout << "Its a draw restart the game" << endl;
		}
	}
	
	


	system("pause");
}
