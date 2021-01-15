/*

TODO:
1. Проверка на ничью;
2. Предложить сыграть еще раз;

DONE:
Вместо циферки в клеточку должен ставиться крестик либо нолик.

*/

#include <iostream>
#include <conio.h>

#define OFFSET_TOP "\n\n\n\n\n\n\n"
#define OFFSET_LEFT "\t\t\t\t\t\t\t"
#define OFFSET_LEFT_FOR_TEXT "\t\t\t\t\t\t"

void PrintField(char field[], const int n, char player);
void Move(char field[], const int n, char player);
void Check(char field[], const int n, char player);

void main()
{
	setlocale(LC_ALL, "Russian");

	char key;
	do
	{
		const int n = 9;
		char field[n]{};
		
		PrintField(field, n, '0');

		std::cout << OFFSET_LEFT_FOR_TEXT;
		std::cout << "Желаете сыграть ещё? (Y/N) >>"; std::cin >> key;

	} while (key == 'Y' || key =='y' || key =='Н' || key == 'н');
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
			(field[i + j] != '0' && field[i + j] != 'X') ? std::cout << " " : std::cout << field[i + j];
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

	Check(field, n, player);
}

void Move(char field[], const int n, char player)
{
	char key;
	bool busy;
	do
	{
		do
		{
			busy = false;
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
		
		if (field[key - 49] != 0)
		{
			busy = true;
			std::cout << "Клетка занята!\n";
		}

	} while (busy);
	
	field[key - 49] = player; //Вносим в массив символ текущего игрока

	PrintField(field, n, player);
}

void Check(char field[], const int n, char player)
{
	bool game_over = false;
	bool move_posible = false;

	if (field[0] == field[4] && field[4] == field[8] && field[0] != 0 ||
		field[0] == field[1] && field[1] == field[2] && field[0] != 0 ||
		field[0] == field[3] && field[3] == field[6] && field[0] != 0 ||
		field[2] == field[4] && field[4] == field[6] && field[2] != 0 ||
		field[2] == field[5] && field[5] == field[8] && field[2] != 0 ||
		field[4] == field[3] && field[3] == field[5] && field[4] != 0 ||
		field[4] == field[1] && field[1] == field[7] && field[4] != 0 ||
		field[7] == field[6] && field[6] == field[8] && field[7] != 0 )
	{
		game_over = true;
	}

	if (game_over)
	{
		std::cout << OFFSET_LEFT_FOR_TEXT;
		std::cout << "Игра окончина!\n";
		std::cout << OFFSET_LEFT_FOR_TEXT;
		std::cout << "Победитель - " << player << std::endl << std::endl;

		return;
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			if (field[i] == 0) move_posible = true;
		}

		if (move_posible)
		{ //Ходы есть
			(player == 'X') ? player = '0' : player = 'X'; //Чередуем символ игрока

			Move(field, n, player);
		}
		else
		{
			std::cout << OFFSET_LEFT_FOR_TEXT;
			std::cout << "Игра окончина!\n";
			std::cout << OFFSET_LEFT_FOR_TEXT;
			std::cout << "Ничья!!!" << std::endl << std::endl;
		}
	}
}
/*Исполнитель
-----------------------------------------------------
|                                                   |
|   "Компьютерная академия ШАГ"                     |
|   Курс: БД011                                     |
|   Предмет: Основы програмvирования на языке C++   |
|                                                   |
|   Исполнитель: Курицын Алексей                    |
|   Преподаватель: Ковтун Олег                      |
|                                                   |
|   Екатеринбург - 2021                             |
|                                                   |
-----------------------------------------------------*/
