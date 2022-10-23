#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif
#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include <string>

using namespace std;

int arrCreate(char** arr, char* str, char* s); // �������� �������
int searchLongWorld(char** arr, int k); // ����� ������ �������� ����� �� ������ ����


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
		cout << "������������ ������ �3 ����-33-21 �������� �.�. ������� 29" << "\n\n"
			"������� 1\n"
			"����\n"
			"1) ���� ������.\n"
			"2) ����� ������.\n"
			"3) ������������ ������ ����.\n"
			"4) ����� ����� ������� �����, � ������� ��� ����� ��������.\n"
			"5) ����� �� ���������.\n";
		cout << "��� �����: ";
		cin >> problem;
		switch (problem) {
		case 1:
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			gets_s(str); // ���������� ��������� � ����������  ������
			system("pause");
			break;
		case 2:
			printf("% s", str); // ����� ������
			cout << endl;
			system("pause");
			break;
		case 3:
			arr[0] = strtok(str, s); // ������������� ������� ���� � ������������ - ��������
			k = arrCreate(arr, str, s); 
			system("pause");
			break;
		case 4:
			cout << "����� ������� �����, � ������� ��� ����� ��������:" << arr[searchLongWorld(arr,k)] << endl;
			system("pause");
			break;
		case 5:
			system("pause");
			break;
		default:
			cout << "��������, � �� ������ �������, ��� �� ������ �������. ���������� � ������ ���." << stop;
			system("pause");
		}
	}
	return 0;
}

int arrCreate(char** arr, char* str, char* s) {
	int i = 0;
	while (arr[i] != NULL) // ������ �� ������
	{
		puts(arr[i]); // ����� �����
		arr[++i] = strtok(NULL, s); // ������ ����� � ��������� ������
	}
	return i; // ����������� ���������� ���������� � �������
}

int searchLongWorld(char** arr, int k) {
	int flag;
	int indMaxEl = -1;
	for (int i = 0; i < k; i++) { // ������ �� ��������� �������
		flag = 0;
		for (int j = 0; j < strlen(arr[i])-1; j++) { // �������� �� ������������� �����
			for (int l = j+1; l < strlen(arr[i]); l++) { // ������ �� ������ �����
				if (arr[i][j] == arr[i][l]) {
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				break;
		}
		if (indMaxEl == -1) { // ����� ������������� �� ����, �������������� �������
			indMaxEl = i;
		}
		else if (flag == 0) {
			if (strlen(arr[indMaxEl]) < strlen(arr[i]))
				indMaxEl = i;
		}
	}
	return indMaxEl; // ����������� ������� ������� �����
}
