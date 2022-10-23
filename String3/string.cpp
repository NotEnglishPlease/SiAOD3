#include <iostream> 
#include <string>

using namespace std;

int arrCreate(string str, string*& arr); // �������� �������
int searchLongWorld(string* arr, int k); // ����� ������ �������� ����� �� ������ ����
void resizeArr(string*& arr, int k); //��������� ������� ������������� �������


int main() {
	setlocale(LC_ALL, "rus");;
	string stop = "\n----------------------------------------------------------------------------\n";
	int problem, flag = 1, k;
	string str;
	string* arr = NULL;

	while (flag)
	{
		system("cls");
		cout << "������������ ������ �3 ����-33-21 �������� �.�. ������� 29" << "\n\n"
			"������� 2\n"
			"����\n"
			"1) ���� ������.\n"
			"2) ����� ������.\n"
			"3) ������������ ������ ����.\n"
			"4) ����� ����� ������� �����, � ������� ��� ����� ��������.\n"
			"5) ����� �� ���������.\n";
		cout << "��� �����: ";
		cin >> problem;
		cin.ignore();
		switch (problem) {
		case 1:
			cout << "������� �����: ";
			getline(cin, str); // ���������� ��������� � ����������  ������
			system("pause");
			break;
		case 2:
			cout << str<<endl;
			system("pause");
			break;
		case 3:
			k = arrCreate(str, arr);
			system("pause");
			break;
		case 4:
			cout << "����� ������� �����, � ������� ��� ����� ��������:" << arr[searchLongWorld(arr, k)] << endl;
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

void resizeArr(string*& arr, int k) {
	string* arr2 = new string[k + 1]; // �������� ����� ������ ������� �������
	for (int i = 0; i < k; i++) { // ������ �� ������� �������
		arr2[i] = arr[i]; // ������������ �������� ������� ������� ������
	}
	delete[] arr; // �������� ������� �������
	arr = arr2; // ������������ ������� ������� �������� ������
}

int arrCreate(string str, string*& arr) {
	string s = "";
	int k = 0;
	for (int i = 0; i < str.length(); i++) { // ������ �� ������
		if (str[i] != ' ') { // ����� �����������
			s = s + str[i]; // ������������ ������ �����
		}
		else if (k == 0) {
			k = k + 1;
			arr = new string[k];
			arr[k-1] = s; // ������ ����� � ������
			cout << s << endl;
			s = "";
		}
		else {
			resizeArr(arr, k);
			k = k + 1;
			arr[k-1] = s; // ������ ����� � ������
			cout << s << endl;
			s = "";
		}
	}
	resizeArr(arr, k);
	k = k + 1;
	arr[k - 1] = s; // ������ ����� � ������
	cout << s << endl;
	return k; // ���������� ���������� ��������� �������
}

int searchLongWorld(string* arr, int k) {
	int flag;
	int indMaxEl = -1;
	for (int i = 0; i < k; i++) { // ������ �� ��������� �������
		flag = 0;
		for (int j = 0; j < arr[i].length() - 1; j++) { // �������� �� ������������� �����
			for (int l = j+1; l < arr[i].length(); l++) { // ������ �� ������ �����
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
			if (arr[indMaxEl].length() < arr[i].length())
				indMaxEl = i;
		}
	}
	return indMaxEl; // ����������� ������� ������� �����
}
