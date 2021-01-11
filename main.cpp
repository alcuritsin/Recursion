#include <iostream>
#include <conio.h>

#define Fact

void elevator(int floor)
{
	if (floor == 0) return;

	std::cout << floor << std::endl;
	elevator(floor - 1);
	std::cout << floor << std::endl;
}

int Factorial(int n)
{	
	if (n == 0) return 1;

	return n * Factorial(n - 1);
}

double Power(double a, int n)
{
	//if (n == 0) return 1;
	//
	//if (n > 0) return a * Power(a, n - 1);
	//if (n < 0) return 1 / a * Power(a, n - 1);
	
	return n>0? a * Power(a, n-1) : n<0 ? 1/a * Power(a, n + 1) : 1;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	system("COLOR 0A");


	//int n = 5;

	//std::cout << "n = "; std::cin >> n;
	//std::cout << Factorial(n);

	int a;
	int s;

	std::cout << "a = "; std::cin >> a;
	std::cout << "n = "; std::cin >> s;

	std::cout << a << "^(" << s << ") = " << Power(a,s);


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