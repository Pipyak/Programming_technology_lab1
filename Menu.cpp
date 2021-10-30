#include "Keeper.h"
#include <cctype>

using std::cout;
using std::cin;
using std::endl;

void Keeper::menu() {

	cout << "Enter 1 to see the table." << endl;
	cout << "Enter 2 to input data." << endl;
	cout << "Enter 3 to delete data." << endl;
	cout << "Enter 4 to change data." << endl;
	cout << "Enter 5 to read data from file." << endl;
	cout << "Enter 6 to write data into file." << endl;
	cout << "Enter 7 to quit." << endl;
	int choise;
	cin >> choise;
	while(choise!=7) {
		try {
			switch (choise) {
			case 1:
				this->objects.Show();
				break;
			case 2:
				k_input();
				break;
			case 3:
				k_delete();
				break;
			case 4:
				ChangeObjects(this->objects);
				break;
			case 5:
				file_in();
				break;
			case 6:
				file_out();
				break;
			default:
				throw ("Wrong input!");
			}
		}
		catch (const char* c){
			cout << "Wrong input! Please, try again.\n" << endl;
		}
		cout << "Enter 1 to see the table." << endl;
		cout << "Enter 2 to input data." << endl;
		cout << "Enter 3 to delete data." << endl;
		cout << "Enter 4 to change data." << endl;
		cout << "Enter 5 to read data from file." << endl;
		cout << "Enter 6 to write data into file." << endl;
		cout << "Enter 7 to quit." << endl;
		cin >> choise;
	}
}

