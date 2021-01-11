#include <iostream>
#include <conio.h>

#define OFFSET_TOP "\n\n\n\n\n\n\n"
#define OFFSET_LEFT "\t\t\t\t\t\t\t"

void PrintField(char field[], const int n, char player);
void Move(char field[], const int n, char player);

void main()
{
	setlocale(LC_ALL, "Russian");

	const int n = 9;
	char field[n]{};

	/*
	for (int i = 0; i < n; i++)
	{
		field[i] = i + 49;
	}
	*/
	PrintField(field, n, 'X');
}

void PrintField(char field[], const int n, char player)
{
	system("CLS");

	std::cout << OFFSET_TOP;
	std::cout << OFFSET_LEFT << " ";
	std::cout << "TicTacToe\n\n";

	for (int i = 6; i >= 0; i -= 3)
	{
		std::cout << OFFSET_LEFT << " ";
		
		for (int j = 0; j < 3; j++)
		{
			std::cout << field[i + j];
			if (j!=2) std::cout << " | ";
		}
		std::cout << std::endl;
		std::cout << OFFSET_LEFT;
		if (i != 0)
		{
			std::cout << "--- --- ---";
		}
		std::cout << std::endl;
	}

	std::cout << OFFSET_TOP;

	Move(field, n, player);
}

void Move(char field[], const int n, char player)
{
	char key;
	
	do
	{
		key = _getch();

		if (key == 27)
		{
			return;
		}

		if ((key < '1' || key >'9') && key != 27)
		{
			std::cout << "Error!";
		}

	} while (key < '1' || key >'9');

	//field[key - 49] = key;
	
	field[key - 49] = player; //Вносим в массив символ текущего игрока

	(player == 'X') ? player = '0': player = 'X'; //Чередуем символ игрока

	PrintField(field, n, player);
}