#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#pragma warning(disable : 4996)
//структура, хранящая
//информацию о человеке
class Man {
public:
	//Имя
	char str[255] = "hello";
	//Возраст
	int age = 0;
	Man() {
	}
};
class Man2 : public Man {
public:
	int i;
	Man2() {
	}
};
int main()
{
	//Создание объектов структуры
	Man* a[4], * b;
	a[0] = new Man;
	a[1] = new Man2;
	a[2] = new Man;
	a[3] = new Man;
	a[1]->age = 8;
	b = new Man[4];
	//Запись в объект A
	//информации, полученной с клавиатуры
	//открытие файла на запись
	FILE* f = fopen("Test.txt", "a+");
	if (!f) exit(0);
	//запись объекта А в файл
	for (size_t i = 0; i < 4; i++)
	{
		fwrite(&a[i], sizeof(Man), 1, f);
	}
	
		fclose(f);
	//открытие файла на чтение
	f = fopen("Test.txt", "r+");
	if (!f) exit(0);
	//считывание содержимого файла
	//в объект B
	for (size_t i = 0; i < 4; i++)
	{
		fread(&b[i], sizeof(Man), 1, f);
	}
	//открытие файла на запись
	fclose(f);
	//показ результата на экран
	cout << "\nName - " << b[0].str << "\n\nAge - " << b[1].age << "\n\n";
}