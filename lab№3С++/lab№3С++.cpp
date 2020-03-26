#include <iostream>
#include <ctime>
#include <string>
using namespace std;

void Task1()
{
	const int Size = 20;
	char arr[Size];

	for (int i = 0; i < Size; i++)
	{
		int a = rand() % 15; //чтобы были разные элементы в массиве из наших 5
		if (a % 5 == 0) arr[i] = ';';
		if (a % 5 == 1) arr[i] = '*';
		if (a % 5 == 2) arr[i] = ':';
		if (a % 5 == 3) arr[i] = 'A';
		if (a % 5 == 4) arr[i] = 'B';
	}

	int a = 0;
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	for (int i = 0; i < Size; i++)
	{
		cout << arr[i] << "  ";
		if (arr[i] == ';')c1++;
		if (arr[i] == ':') c2++;
		if (arr[i] == '*') c3++;
	}
	int C = c1 + c2 + c3;
	cout << endl;
	cout << "Колличество ';' -> " << c1<<endl;
	cout << "Колличество ':' -> " << c2<<endl;
	cout << "Колличество '*' -> " << c3<<endl;
	cout << "Всего: " << C << endl;
}

//////////////////////////////////

void Task2()
{
	const int Size = 13;
	char arr[Size];

	for (int i = 0; i < Size; i++)
	{
		int a = rand() % 15;
		if (a % 3 == 0) arr[i] = 'a';
		if (a % 3 == 1) arr[i] = 'b';
		if (a % 3 == 2) arr[i] = '*';
	}

	int count = 0, max = 0;
	/* В переменную max записываем самую длинную цепочку элементов А подряд,
	count считает текущую цепочку элементов А подряд */
	for (int i = 0; i < Size; i++)
	{
		if (arr[i] == 'a')
		{
			count++;
		}
		else
		{
			if (count > max)
				max = count;
			count = 0;
		}

	}
	cout << " | ";
	for (int i = 0; i < Size; i++)
	{
		cout << arr[i] << " | ";
	}

	cout << "\n\n" << max;
}

////////////////////////////

void Task3()
{
	srand(time(0));// для того чтобы рандом каждый раз был разным
	string number = "0";
	int num;
	const int Size = 13;
	char arr[Size];

	for (int i = 0; i < Size;)
	{
		char ch = rand() % 127;//127 потому что цифры и буквы(латинские) находятся в таблице ASCII как раз до 127 позиции
		if (isalnum(ch))//Проверяет является ли символ либо буквой алфавита либо цифрой
		{
			arr[i] = ch;
			cout << arr[i];
			++i;
		}
	}

	for (int i = 0; i < Size; i++)
	{

		if (isdigit(arr[i]))//isdigit - Проверяет является ли числом переменная в скобках
		{
			number += arr[i];//Записываем в нашу строковую переменную символ, который подходит по условию(цифру)
		}

	}
	cout << "\n";
	num = stoi(number);//STOI - Переводит тип данных String в Int



	if (num > 6000)
	{
		cout << "Пожалуйста, повторите запуск программы, числло слишком велико!";
	}

	cout << "| " << num << " |\n";


	if (floor(num / 1000) > 0)//floor - Округление в меньшую сторону
	{
		for (int i = 0; i < floor(num / 1000); i++)
		{
			cout << "M";
		}
		num -= floor(num / 1000) * 1000;
	}

	if (floor(num / 500) > 0)
	{
		for (int i = 0; i < floor(num / 500); i++)
		{
			cout << "D";
		}
		num -= floor(num / 500) * 500;
	}

	if (floor(num / 100) > 0)
	{
		for (int i = 0; i < floor(num / 100); i++)
		{
			cout << "C";
		}
		num -= floor(num / 100) * 100;
	}

	if (floor(num / 50) > 0)
	{
		for (int i = 0; i < floor(num / 50); i++)
		{
			cout << "L";
		}
		num -= floor(num / 50) * 50;
	}

	if (floor(num / 10) > 0)
	{
		for (int i = 0; i < floor(num / 10); i++)
		{
			cout << "X";
		}
		num -= floor(num / 10) * 10;
	}

	if (floor(num / 5) > 0)
	{
		for (int i = 0; i < floor(num / 5); i++)
		{
			cout << "V";
		}
		num -= floor(num / 5) * 5;
	}

	if (floor(num / 1) > 0)
	{
		for (int i = 0; i < floor(num / 1); i++)
		{
			cout << "I";
		}
		num -= floor(num / 1) * 1;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int numTask;
	cout << "Enter num of task: ";
	cin >> numTask;

	switch (numTask)
	{
	case 1:
		Task1();
		break;
	case 2:
		Task2();
		break;
	case 3:
		Task3();
		break;
	}
}
