/*
TODO:
1. Написать рекурсивную функцию Factorial, которая принимает число и возвращает факториал этого числа;
2. Написать рекурсивную функцию Power, которая возводит число в степень;
3. Написать рекурсивную функцию Fibonacci, которая выводит на экран ряд Фибоначчи, до указанного числа;
4. Написать рекурсивную функцию Fibonacci, которая выводит на экран указанное количество чисел из ряда Фибоначчи;
*/
#include <iostream>

unsigned long long int factorial(unsigned int f);

template <typename T>
long double power(T a, int n);

long long int fibonacci(int n);
void fibonacci_n(int n);

void main()
{
	setlocale(LC_ALL, "Russian");

//1. Factorial
	unsigned int n;

	//n = 65; //проверочные значения
	std::cout << "--- Factorial ---\n";
	std::cout << "Введите число от 0 до 65 для рассчета факториала.\n";
	std::cout << "n = "; std::cin >> n;
	std::cout << n << "! = " << factorial(n) << std::endl;

//2. Power
	int a; //число
	int s; //степень

	//a = 2; //проверочные значения
	//s = -3; //проверочные значения
	std::cout << "\n--- Power ---\n";
	std::cout << "Введите число для возведения в степень.\n";
	std::cout << "a = "; std::cin >> a;
	std::cout << "Введите степень.\n";
	std::cout << "n = "; std::cin >> s;
	if (s < 0 && a == 0)
	{
		std::cout << "Невозможно вычислить " << a << "^(" << s << "). Ошибка --деление на ноль.";
	}
	else
	{
		std::cout << a << "^(" << s<< ") = " << power(a,s) << std::endl;
	}

//3. Fibonacci до числа
	int f1;
	int  n1 = 0;
	
	//f1 = 100; //проверочные значения
	std::cout << "\n--- Fibonacci_1 ---\n";
	std::cout << "Введите число, до которого необходимо вывести ряд Фибоначи.\n";
	std::cout << "F = "; std::cin >> f1;
	while (fibonacci(n1) < f1) //Не смог придумать как это сделать рекурсивно (((
	{
		std::cout << "n = " << n1 << "   Fn = " << fibonacci(n1) << std::endl;
		n1++;
	}

//4. Fibonacci n-чисел
	int n2;

	//f2 = 10; //проверочные значения
	std::cout << "\n--- Fibonacci_2 ---\n";
	std::cout << "Введите количество чисел Фибоначи, для отображения.\n";
	std::cout << "n = "; std::cin >> n2;
	fibonacci_n(n2 - 1); // n-1 -- так как F0 первый элемент. 

	std::cout << "\n--- Program end ---\n";
}

unsigned long long int factorial(unsigned int f)
{

	if (f == 1 || f == 0) return 1; // 1!=1 и 0!=1

	return f * factorial(f - 1);
}

template <typename T>
long double power(T a, int n)
{

	if (n == 0) return 1; //a^0 = 1
	
	if (n > 0)
	{

		return a * power(a, n - 1); //a^n

	}

	if (n < 0)
	{
		n *= -1; //избавляемся от минуса в степени

		return 1/ (a * power(a, n - 1)); //a^-n
	}	
}

long long int fibonacci(int n)
{

	if (n == 0) return 0;
	if (n == 1) return 1;
	
	return fibonacci(n - 1) + fibonacci(n - 2);
}
void fibonacci_n(int n)
{
	if (n < 0) return;
	fibonacci_n(n - 1);
	std::cout << n + 1 << " -- n = " << n << " Fn = " << fibonacci(n) << std::endl;
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
|   Екатеринбург - 2020                             |
|                                                   |
-----------------------------------------------------*/
