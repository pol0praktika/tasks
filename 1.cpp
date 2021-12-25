#include <iostream>

using namespace std;

void valid(int& a, int& b) {

	bool fail = false;
	while (!fail)
	{
		cin >> a >> b;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You entered the wrong number, please enter the correct one." << endl;
		}
		else {
			fail = 1;
		}
	}

}

int main()
{
	setlocale(LC_ALL, "ru");
	int a, b;
	char action;
	while (true)
	{
		cout << "Enter 1 and 2 number" << endl;
		valid(a, b);

		cout << "Select an action" << endl;
		cin >> action;

		switch (action)
		{
		case '+':
		{
			cout << "Result:" << a + b << endl;
			break;
		}
		case '-':
		{
			cout << "Result:" << a - b << endl;
			break;
		}
		case '*':
		{
			cout << "Result:" << a * b << endl;
			break;
		}
		case '/':
		{
			if (b == 0)
			{
				cout << "There is no solutions. You have tried to divide by zero." << endl;
				return 0;
			}
			cout << "Result:" << a / b << endl;
			break;
		}
		default:
			cout << "ДЕЙСТВИЕ НЕ ОПРЕДЕЛЕНО";
			break;
		}
		cout << endl << endl;
	}
}