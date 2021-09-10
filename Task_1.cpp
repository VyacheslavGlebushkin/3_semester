#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

//Номер варианта – остаток от деления суммы всех букв фамилии на число вариантов
void Variant() {
	string surname;
	int n;
	cout << "Введите фамилию студента: ";
	cin >> surname;
	cout << "Введите количество вариантов: ";
	cin >> n;
	if (surname.length() % n > 0)
		cout << "Номер варианта для студента с фамилией " << surname << ": " << surname.length() % n << endl;
	else //Если остаток от деления - 0, вариант - 1
		cout << "Номер варианта для студента с фамилией " << surname << ": 1" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Variant();
	return 0;
}
