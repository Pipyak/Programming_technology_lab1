#pragma once
#ifndef _KEEPER_H
#define _KEEPER_H
#include <iostream>
#include <string>
#include "Dequeue.h"


class Keeper{
private:
	Dequeue objects;
public:
	Keeper(){}
	int size() { return objects.size(); }
	Keeper& file_in();
	void file_out();
	void k_input();
	void k_delete();
	void forb(University* ob);
	void ChangeObjects(Dequeue& dec);
	void menu();
	~Keeper(){}
};
#endif // !_KEEPER_H

