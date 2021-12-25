#include <iostream> 
#include <algorithm> 
#include <string> 
#include <fstream> 
using namespace std;

int menuOption() {
	char action[1000];
	int menuOption;

	cout << "Choose action from the list: " << endl;

	cout << "1 = Output string to file" << endl;
	cout << "2 = Read string from the file" << endl;
	cout << "3 = Concatenation" << endl;
	cout << "4 = Upper register" << endl;
	cout << "5 = Lower register" << endl;
	cout << "6 = Exit" << endl << endl;

	cout << "Your choice: ";
	cin >> action;

	if (strlen(action) == 1 && (action[0] == '1' || action[0] == '2' || action[0] == '3' || action[0] == '4' || action[0] == '5' || action[0] == '6'))
	{
		menuOption = atoi(action);
	}
	else {
		menuOption = 0;
	}
	return menuOption;
}
int menu() {
	int option = menuOption();
	while (option == 0)
	{
		cout << "You entered the wrong menu option. Enter the corrent option from the list. " << endl << endl << endl;
		int option = menuOption();
	}
	return option;
}

int main() {

	int action = 0;
	fstream my_file;
	char ch;

	while (action != 6) {


		string str;
		string secondstr;
		string res;
		action = menu();
		switch (action) {
		case 1:
		{
			cout << "Enter string: ";
			cin >> secondstr;

			ofstream out("output.txt");
			out << secondstr;
			cout << "Data in file with name «output.txt»: " << secondstr << endl;
			out.close();

			cout << endl;
			break;
		}

		case 2:
			cout << "Enter file name: ";
			cin >> secondstr;

			my_file.open(secondstr, ios::in);

			if (!my_file) {
				cout << "There is no file like this.";
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
			break;

		case 3:
			cout << "Enter string: ";
			cin >> secondstr;
			cout << "Enter second string: ";
			cin >> str;
			res = secondstr + " " + str;
			cout << "Result: " << res << endl;
			cout << endl;
			break;

		case 4:
			cout << "Enter string: ";
			cin >> secondstr;

			transform(secondstr.begin(), secondstr.end(), secondstr.begin(), ::toupper);
			cout << "Result: " << secondstr << endl;
			cout << endl;
			break;

		case 5:
			cout << "Enter string: ";
			cin >> secondstr;
			transform(secondstr.begin(), secondstr.end(), secondstr.begin(), ::tolower);
			cout << "Result: " << secondstr << endl;
			break;
		}

		
	}
	return 0;
}
