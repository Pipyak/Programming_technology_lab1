#include "Header.h"
#include <string>

using std::cout;
using std::cin;
using std::endl;

void University::change()
{
	while (cin.get() != '\n');
	getline(cin, this->FIO);
}

void Student::change()
{
	cout << *this;
	cout << "What do you want to change?(input number)";
	int i;
	cin >> i;
	try {
		switch (i) {
		case 1:
			cout << "Input new name: ";
			University::change();
			break;
		case 2:
			cout << "Input new course: ";
			cin >> course;
			break;
		case 3:
			cout << "Input new group: ";
			cin >> group;
			break;
		case 4:
			cout << "Input new speciality name: ";
			cin >> sp_name;
			break;
		case 5:
			cout << "Input new average score: ";
			cin >> av_score;
			break;
		default:
			throw("Wrong input!");
		};
	}
	catch (const char* c) {
		cout << "Wring input! Try again!\n";
		Student::change();
	}
}

void Professor::change()
{
	cout << *this;
	cout << "What do you want to change?(input number)";
	int i;
	cin >> i;
	try {
		switch (i) {
		case 1:
			cout << "Input new name: ";
			University::change();
			break;
		case 2:
			change_g();
			break;
		case 3:
			change_g();
			break;
		default:
			throw("Wrong input!");
		};
	}
	catch (const char* c) {
	cout << "Wring input! Try again!\n";
	Professor::change();
	}
}


void Administration::change()
{
	cout << *this;
	cout << "What do you want to change?(input number)";
	int i;
	cin >> i;
	try {
		switch (i) {
		case 1:
			cout << "Input new name: ";
			University::change();
			break;
		case 2:
			cout << "Input new telephone number: ";
			cin >> tel_num;
			break;
		case 3:
			cout << "Input new position: ";
			while (cin.get() != '\n');
			getline(cin, position);
			break;
		case 4:
			cout << "Input new responsibility: ";
			while (cin.get() != '\n');
			getline(cin, responsibility);
			break;
		default:
			throw("Wrong input!");
		};
	}
	catch (const char* c){
		cout << "Wring input! Try again!\n";
		Administration::change();
	}
}

void Professor::change_g()
{
	cout << "What group you want to change?(input number):\n";
	for (int i = 0; i < g_size; i++)
		cout << i+1 <<"."<<groups[i]<<endl;
	int i;
	cin >> i;
	if (i<0 || i>g_size + 1) {
		cout << "Wrong input. Try again!\n";
		change_g();
	}
	i--;
	cin >> groups[i];
}

void Professor::change_s()
{
	cout << "What subjects you want to change?(input number):\n";
	for (int i = 0; i < g_size; i++)
		cout << i + 1 << "."<< subjects[i];
	int i;
	cin >> i;
	if (i<0 || i>s_size + 1) {
		cout << "Wrong input. Try again!\n";
		change_s();
	}
	i--;
	while (cin.get() != '\n');
	getline(cin, subjects[i]);
}