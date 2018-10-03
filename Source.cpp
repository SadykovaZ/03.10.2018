#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int sum_arr(int n, ...) //функции с переменным числом аргументов
{
	int *p = &n;
	int sum = 0;
	for (int i = 1; i < n + 1; i++)
	{
		sum += *(p + i);
	}
	return sum;
}
template <typename T1>
T1 sum2(T1 a, ...) //функции с переменным числом аргументов
{
	T1* p = &a; //начало области
	T1 sum = 0;
	while (*p)
	{
		sum += *p;
		p++;
	}
	return sum;
}
double sum3(double a, ...) //функции с переменным числом аргументов
{
	double* p = &a; //начало области
	double sum = 0;
	while (*p)
	{
		sum += *p;
		p++;
	}
	return sum;
}
template <typename T>
T oper(char o, T arg, ...)
{
	va_list p; //специальный указатель автоматически опрделеяет тип указателя
	T sum = 0;
	T prod = 1;
	int count = 0;
	T k = arg;
	__crt_va_start(p, arg); //T* p = &a;
	do
	{
		if (o == 's' || o == '+')
		{
			sum += k; count++;
		}
		else if (o == '*')
		{
			prod *= k;
		}
	} while (k = __crt_va_arg(p, T)); // --пока не ноль передвигаемся
	__crt_va_end(p);//--закрыли указатель
	if (o == 's')
		return ((sum) / count);
	else if (o == '+')
		return sum;
	else if (o == '*')
		return prod;
}
int summa(char* str)
{
	int sum = 0;
	int k = 1;
	for (int i = 0; i < strlen(str) - 1; i += 2)
	{
		sum += k * (str[i] - 48);
		if (str[i + 1] == '+')
			k = 1;
		else if (str[i + 1] == '-')
			k = -1;
	}
	sum += k * (str[strlen(str) - 1] - 48);
	return sum;
}
void main()
{
	setlocale(LC_ALL, "Rus");
	int n = 0;
	cout << "Vvedite zadanie: ";
	cin >> n;
	if (n == 1)
	{
		//Дана строка. Преобразовать в ней все прописные латинские буквы в строчные
		char str[20] = { "HELLO" };
		for (int i = 0; i < 20; i++)
		{
			if (isupper(str[i]))
				str[i] = tolower(str[i]);
		}
		cout << str;
		cout << endl;
		string a = { "HELLO" };
		for (int i = 0; a[i]; i++)
		{
			if (isupper(a[i]))
				a[i] = tolower(a[i]);
		}
		cout << a;
		cout << endl;
		string S;
		cout << "Vvedite stroku : " << endl;
		cin >> S;
		int size = S.size();
		for (int i = 0; i < size; i++)
			S[i] = (int)S[i] + 32;

		cout << S << endl;
		cout << endl;
	}
	else if (n == 2)
	{
		//функции с переменным числом аргументов
		cout << sum_arr(3, 5, 6, 7, 0) << endl;
	}
	else if (n == 3)
	{
		cout << sum2(1, 2, 7, 5, 0) << endl;
	}
	else if (n == 4)
	{
		cout << sum3(1.5, 2.4, 7.2, 5.3, 0.0) << endl;
	}
	else if (n == 5)
	{
		cout << oper('*', 1, 1, 4, 5, 5, 0) << endl;
	}
	else if (n == 6)
	{
		// Дана строка, изображающая арифметическое выражение вида «<цифра>±<цифра>±...±<цифра>», где на месте знака операции «±» находится символ «+» или «−» (например, «4+7−2−8»). Вывести значение данного выражения (целое число). 
		char str[] = "1+2-4+5";
		cout << summa(str) << endl;
	}
	else if (n == 7)
	{
		//перевод медиафайлов
		ifstream in_f("37.jpg", ios::binary);
		ofstream out_f("out.jpg", ios::binary);
		char c;
		while (in_f.get(c))
		{
			out_f << c;
		}
	}
	else if (n == 8)
	{
		ifstream in_m("dan.mp3", ios::binary);
		ofstream out_m("dan_out.mp3", ios::binary);
		char c;
		while (in_m.get(c))
		{
			out_m << c;
		}
	}
	system("pause");
}