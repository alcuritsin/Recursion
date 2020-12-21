#include <iostream>
#include <conio.h>

void elevator(int floor)
{
	if (floor == 0) return;

	std::cout << floor << std::endl;
	elevator(floor - 1);
	std::cout << floor << std::endl;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	system("COLOR 0A");
	int n =1000000;

	//std::cout << "На каком вы этаже? "; std::cin >> n;

	elevator(n);

	/*
	std::cout << "Hello World!\n";

	std::cout << "Для выхода Esc. Для продолжения любая клавиша.\n";

	if (_getch()!=27) main();
	*/
}