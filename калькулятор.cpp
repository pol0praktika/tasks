#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int a, b;
	char action;

	cout << "введите 1 и 2 число" << endl;
	cin >> a >> b;

	cout << "введите действие" << endl;
	cin >> action;

	switch (action)
	{
	case '+':
	{
		cout << "результат:" << a + b << endl;

		break;
	}
	case '-':
	{
		cout << "результат:" << a - b << endl;

		break;
	}
	case '*':
	{
		cout << "результат:" << a * b << endl;

		break;
	}
	case '/':
	{
		if (b == 0)
		{
			cout << "НЕТ РЕШЕНИЙ" << endl;
			return 0;
		}
		cout << "результат:" << a/b << endl;


		break;
	}
	default:
		cout << "ДЕЙСТВИЕ НЕ ОПРЕДЕЛЕНО";
		break;
	}

}