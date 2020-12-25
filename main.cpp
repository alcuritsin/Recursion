#include <iostream>
#include <conio.h>

void elevator(int floor)
{
	if (floor == 0) return;

	std::cout << floor << std::endl;
	elevator(floor - 1);
	std::cout << floor << std::endl;
}

//int Fact(int digit)
//{	
//	int resoult = 1;
//	if (digit == 0) return;
//	resoult *=Fact(digit - 1);
//	
//	return resoult;
//}

void main()
{
	setlocale(LC_ALL, "Russian");
	system("COLOR 0A");
	int n = 5;
	int nf;
	//std::cout << "На каком вы этаже? "; std::cin >> n;

	// elevator(n);
	//nf = Fact(n);
	//std::cout << nf;
	/*
	std::cout << "Hello World!\n";

	std::cout << "Для выхода Esc. Для продолжения любая клавиша.\n";

	if (_getch()!=27) main();
	*/
}