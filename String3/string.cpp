#include <iostream> 
#include <string>

using namespace std;

int arrCreate(string str, string*& arr); // создание массива
int searchLongWorld(string* arr, int k); // поиск самого длинного слова из разных букв
void resizeArr(string*& arr, int k); //изменение размера динамического массива


int main() {
	setlocale(LC_ALL, "rus");;
	string stop = "\n----------------------------------------------------------------------------\n";
	int problem, flag = 1, k;
	string str;
	string* arr = NULL;

	while (flag)
	{
		system("cls");
		cout << "ѕрактическа€ работа є3 » Ѕќ-33-21 Ёрднеева Ќ.ƒ. ¬аринат 29" << "\n\n"
			"«адание 2\n"
			"ћеню\n"
			"1) ¬вод текста.\n"
			"2) ¬ывод текста.\n"
			"3) —формировать массив слов.\n"
			"4) Ќайти самое длинное слово, в котором все буквы различны.\n"
			"5) ¬ыход из программы.\n";
		cout << "¬аш выбор: ";
		cin >> problem;
		cin.ignore();
		switch (problem) {
		case 1:
			cout << "¬ведите текст: ";
			getline(cin, str); // считывание введенной с клавиатуры  строки
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
			cout << "—амое длинное слово, в котором все буквы различны:" << arr[searchLongWorld(arr, k)] << endl;
			system("pause");
			break;
		case 5:
			system("pause");
			break;
		default:
			cout << "»звините, € не совсем понимаю, что вы хотите сделать. ѕопробуйте в другой раз." << stop;
			system("pause");
		}
	}
	return 0;
}

void resizeArr(string*& arr, int k) {
	string* arr2 = new string[k + 1]; // создание новой строки нужного размера
	for (int i = 0; i < k; i++) { // проход по старому массиву
		arr2[i] = arr[i]; // присваивание значений старого массива новому
	}
	delete[] arr; // удаление старого массива
	arr = arr2; // присваивание старому массиву значени€ нового
}

int arrCreate(string str, string*& arr) {
	string s = "";
	int k = 0;
	for (int i = 0; i < str.length(); i++) { // проход по строке
		if (str[i] != ' ') { // поиск разделител€
			s = s + str[i]; // формирование строки слова
		}
		else if (k == 0) {
			k = k + 1;
			arr = new string[k];
			arr[k-1] = s; // запись слова в массив
			cout << s << endl;
			s = "";
		}
		else {
			resizeArr(arr, k);
			k = k + 1;
			arr[k-1] = s; // запись слова в массив
			cout << s << endl;
			s = "";
		}
	}
	resizeArr(arr, k);
	k = k + 1;
	arr[k - 1] = s; // запись слова в массив
	cout << s << endl;
	return k; // возращение количества элементов массива
}

int searchLongWorld(string* arr, int k) {
	int flag;
	int indMaxEl = -1;
	for (int i = 0; i < k; i++) { // проход по элементам массива
		flag = 0;
		for (int j = 0; j < arr[i].length() - 1; j++) { // проверка на повтор€ющиес€ буквы
			for (int l = j+1; l < arr[i].length(); l++) { // проход по буквам слова
				if (arr[i][j] == arr[i][l]) {
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				break;
		}
		if (indMaxEl == -1) { // поиск максимального из слов, удовлетвор€ющи условию
			indMaxEl = i;
		}
		else if (flag == 0) {
			if (arr[indMaxEl].length() < arr[i].length())
				indMaxEl = i;
		}
	}
	return indMaxEl; // возвращение индекса нужного слова
}
