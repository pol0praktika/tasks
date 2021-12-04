#include <iostream> 
#include <algorithm> 
#include <string> 
#include <fstream> 
using namespace std;



int main() {
	setlocale(LC_ALL, "Russian");

	int action;
	fstream my_file;
	char ch;

	cout << "Выберите действие со строками: " << endl;

	cout << "1 = Вывод строк в файл" << endl;
	cout << "2 = Чтение из файла" << endl;
	cout << "3 = Конкатенация" << endl;
	cout << "4 = Верхний регистр" << endl;
	cout << "5 = Нижний регистр" << endl;
	cout << "3 = Конкатенация" << endl;
	cout << "6 = Выход" << endl << endl;

	cout << "Выш выбор: " << endl;
	cin >> action;

	while (action < 1 || action > 6) {
		cout << "Выберите любую операцию" << endl;
		cout << "Ваш выбор: " << endl;
		cin >> action;
	}
	string str;
	string secondstr;
	string res;

	switch (action) {
	case 1:
	{
		cout << "Введите строку: ";
		cin >> secondstr;

		ofstream out("output.txt");
		out << secondstr;
		cout << "Данные в файле output.txt: " << secondstr << endl;
		out.close();

		cout << endl;
		main();
		break;
	}

	case 2:
		cout << "Введите название файла: ";
		cin >> secondstr;

		my_file.open(secondstr, ios::in);

		if (!my_file) {
			cout << "Такого файла нет.";
		}
		else {
			while (1) {
				my_file >> ch;
				if (my_file.eof())
					break;
				cout << ch;
			}
		}
		my_file.close();
		cout << endl;
		main();
		break;

	case 3:
		cout << "Введите строку: ";
		cin >> secondstr;


		cout << "Введите вторую строку: ";
		cin >> str;

		res = secondstr + " " + str;
		cout << "Результат: " << res << endl;

		cout << endl;
		main();
		break;

	case 4:
		cout << "Введите строку: ";
		cin >> secondstr;

		transform(secondstr.begin(), secondstr.end(), secondstr.begin(), ::toupper);
		cout << "Результат: " << secondstr << endl;
		cout << endl;
		main();
		break;

	case 5:
		cout << "Введите строку: ";
		cin >> secondstr;

		transform(secondstr.begin(), secondstr.end(), secondstr.begin(), ::tolower);
		cout << "Результат: " << secondstr << endl;
		
		main();
		break;
	
	case 6:
		cout << "Выход";
		return 0;
	}
}