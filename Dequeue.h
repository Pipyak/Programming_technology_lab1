#pragma once
#ifndef _DEQUEUE_H
#include "Header.h"

class Dequeue {
private:
	int dec_size = 0;
	struct Node {
		University* object;
		Node* next;
	};
	Node* first;
	Node* last;
public:
	Dequeue() :dec_size(0), first(0), last(0) {}
	void push_front(University* ob);
	void push_back(University* ob);
	void pop_front();
	void pop_back();
	void Show();
	bool isempty() { return dec_size == 0; }
	int size() { return dec_size; }
	University* operator[](int index);
	friend std::ostream& operator<<(std::ostream &os, const Dequeue& d);
	~Dequeue() {}
};
#endif // !_DEQUEUE_H

