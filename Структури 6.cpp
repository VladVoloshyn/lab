#include <iostream> 
#include <fstream> 
#include <string>  
#include <cstring>
using namespace std;

struct WORKER // структура 
{
	string name;
	char surname[20];
	string patronymic; // отчество
	string job_title;
	int year;
};



int main()
{
	const int size = 4;  // количесто работников
	WORKER wok[size];   // массив работников
	int N;
	int flag = 0;      // счётчик по стажу

	int n = 0;
	int i, j;
	ifstream infile;
	infile.open("Text.txt"); // открываем файл

	while (!infile.eof())   // считываем в массив до конца файла
	{
		infile >> wok[n].surname >> wok[n].name >> wok[n].patronymic
			>> wok[n].job_title >> wok[n].year;
		n++;
	}

	for (i = 0; i < size; i++)
		for (j = i + 1; j < size; j++)  // сортируем по фамилиям
		{
			if (strcmp(wok[i].surname, wok[j].surname) > 0)
			{
				WORKER temp;
				temp.name = wok[i].name;
				strcpy_s(temp.surname, wok[i].surname);
				temp.patronymic = wok[i].patronymic;
				temp.job_title = wok[i].job_title;
				temp.year = wok[i].year;

				wok[i].name = wok[j].name;
				strcpy_s(wok[i].surname, wok[j].surname);
				wok[i].patronymic = wok[j].patronymic;
				wok[i].job_title = wok[j].job_title;
				wok[i].year = wok[j].year;

				wok[j].name = temp.name;
				strcpy_s(wok[j].surname, temp.surname);
				wok[j].patronymic = temp.patronymic;
				wok[j].job_title = temp.job_title;
				wok[j].year = temp.year;
			}

		}

	for (i = 0; i < size; i++) // выводим отсортированный список
	{
		cout << wok[i].surname << " " << wok[i].name << " " << wok[i].patronymic << endl;
		cout << wok[i].job_title << " " << wok[i].year << endl;
	}

	cout << endl << endl;
	cout << "Inter a year " << endl;
	cin >> N;

	for (i = 0; i < size; i++)
		if (N < 2021 - wok[i].year) // сравниваем стаж от 2021
		{
			cout << wok[i].surname << " " << wok[i].name << " " << wok[i].patronymic << " "
				<< wok[i].job_title << " " << wok[i].year << endl;
			flag++; // если есть выполнение условия увеличиваем счётчик
		}

	if (flag == 0)  // если счётчик равен 0
		cout << "such workers aren't present " << endl; // таких работников нет

	system("Pause");

}
