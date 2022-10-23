#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif
#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include <string>

using namespace std;

int arrCreate(char** arr, char* str, char* s); // создание массива
int searchLongWorld(char** arr, int k); // поиск самого длинного слова из разных букв


int main() {
	setlocale(LC_ALL, "rus");;
	string stop = "\n----------------------------------------------------------------------------\n";
	int problem, flag = 1, k;
	char str[100] = "";
	char* arr[100];				
	char s[] = " ";


	while (flag)
	{
		system("cls");
		cout << "Практическая работа №3 ИКБО-33-21 Эрднеева Н.Д. Варинат 29" << "\n\n"
			"Задание 1\n"
			"Меню\n"
			"1) Ввод текста.\n"
			"2) Вывод текста.\n"
			"3) Сформировать массив слов.\n"
			"4) Найти самое длинное слово, в котором все буквы различны.\n"
			"5) Выход из программы.\n";
		cout << "Ваш выбор: ";
		cin >> problem;
		switch (problem) {
		case 1:
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			gets_s(str); // считывание введенной с клавиатуры  строки
			system("pause");
			break;
		case 2:
			printf("% s", str); // вывод строки
			cout << endl;
			system("pause");
			break;
		case 3:
			arr[0] = strtok(str, s); // инициализация массива слов с разделителем - пробелом
			k = arrCreate(arr, str, s); 
			system("pause");
			break;
		case 4:
			cout << "Самое длинное слово, в котором все буквы различны:" << arr[searchLongWorld(arr,k)] << endl;
			system("pause");
			break;
		case 5:
			system("pause");
			break;
		default:
			cout << "Извините, я не совсем понимаю, что вы хотите сделать. Попробуйте в другой раз." << stop;
			system("pause");
		}
	}
	return 0;
}

int arrCreate(char** arr, char* str, char* s) {
	int i = 0;
	while (arr[i] != NULL) // проход по строке
	{
		puts(arr[i]); // вывод слова
		arr[++i] = strtok(NULL, s); // запись слова в двумерный массив
	}
	return i; // возвращение количества переменных в массиве
}

int searchLongWorld(char** arr, int k) {
	int flag;
	int indMaxEl = -1;
	for (int i = 0; i < k; i++) { // проход по элементам массива
		flag = 0;
		for (int j = 0; j < strlen(arr[i])-1; j++) { // проверка на повторяющиеся буквы
			for (int l = j+1; l < strlen(arr[i]); l++) { // проход по буквам слова
				if (arr[i][j] == arr[i][l]) {
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				break;
		}
		if (indMaxEl == -1) { // поиск максимального из слов, удовлетворяющи условию
			indMaxEl = i;
		}
		else if (flag == 0) {
			if (strlen(arr[indMaxEl]) < strlen(arr[i]))
				indMaxEl = i;
		}
	}
	return indMaxEl; // возвращение индекса нужного слова
}
