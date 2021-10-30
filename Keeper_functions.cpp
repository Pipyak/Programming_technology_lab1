#include "Keeper.h"

using std::cout;
using std::cin;
using std::endl;

void Keeper::ChangeObjects(Dequeue& dec){

	if (dec.size() == 0) {
		cout << "There is nothing here. Please add data and continue.\n\n";
		return;
	}
	for (int i = 0; i < dec.size(); i++) {
		cout << i + 1 << ")"; 
		this->objects[i]->printf();
	}
	cout << "What element you want to change?(input number)"<<std::endl;
	int change;
	cin >> change;
	change--;
	this->objects[change]->change();
}

void Keeper::k_input(){
	cout << "Enter 1 to input data about student." << std::endl;
	cout << "Enter 2 to input data about professor." << std::endl;
	cout << "Enter 3 to input data about administration worker." << std::endl;
	int choise;
	cin >> choise;
	try {
		if (choise == 1) {
			University* ob = new Student;
			ob->scanf();
			forb(ob);
		}
		if (choise == 2) {
			University* ob = new Professor;
			ob->scanf();
			forb(ob);
		}
		if (choise == 3) {
			University* ob = new Administration;
			ob->scanf();
			forb(ob);
		}
		else if (choise != 1 && choise != 2 && choise != 3) {
			throw("Wrong input!");
		}
	}
	catch (const char* c) {
		cout << "Wrong input! Please, try again.\n" << endl;
		this->k_input();
	}
}

void Keeper::forb(University* ob) {

	cout << "If you want to add data to the beginning, input 1" << endl;
	cout << "If you want to add data to the end, input 2" << endl;
	int choise;
	cin >> choise;
	try {
		switch (choise) {
		case 1:
			this->objects.push_front(ob);
			break;
		case 2:
			this->objects.push_back(ob);
			break;
		default:
			throw ("Wrong input!");
		};
	}
	catch (const char* c) {
		cout << "Wrong input! Please, try again.\n" << endl;
		this->forb(ob);
	}
}

void Keeper::k_delete() {
	cout << "If you want to delete data from the beginning, input 1" << endl;
	cout << "If you want to delete data from the end, input 2" << endl;
	int choise;
	cin >> choise;

	try {
		switch (choise) {
		case 1:
			this->objects.pop_front();
			break;
		case 2:
			this->objects.pop_back();
			break;
		default:
			throw ("Wrong input!");
		};
	}
	catch (const char* c) {
		cout << "Wrong input! Please, try again.\n" << endl;
		this->k_delete();
	}
}