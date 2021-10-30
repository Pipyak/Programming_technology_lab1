#include "Dequeue.h"

void Dequeue::push_back(University* ob) {
	if (this->isempty()) {
		first = new Node;
		first->object = ob;
		first->next = nullptr;
		last = first;
	}
	else {
		last->next = new Node;
		last->next->object = ob;
		last->next->next = nullptr;
		last = last->next;
	}
	dec_size++;
}

void Dequeue::pop_back()
{
	if (this->isempty()) {
		return;
	}
	if (first == last)
		delete first;
	else {
		struct Node* time_ptr;
		time_ptr = first;
		while (time_ptr->next != last) {
			time_ptr = time_ptr->next;
		}
		delete time_ptr->next;
		last = time_ptr;
		last->next = nullptr;
	}
	dec_size--;
}

void Dequeue::push_front(University* ob)
{
	if (this->isempty()) {
		first = new Node;
		first->object = ob;
		first->next = nullptr;
		last = first;
	}
	else if (first == last) {
		struct Node* time_ptr = new Node;
		time_ptr->object = ob;
		first = time_ptr;
		first->next = last;
		last->next = nullptr;
	}
	else {
		struct Node* time_ptr = new Node;//хранение данных
		struct Node* refirst_ptr = first;//хранение значения первого элемента
		time_ptr->object = ob;
		refirst_ptr = time_ptr;
		refirst_ptr->next = first;
		first = refirst_ptr;
	}
	dec_size++;
}

void Dequeue::pop_front()
{
	if (this->isempty()) {
		return;
	}
	else {
		struct Node* time_ptr = new Node;
		time_ptr = first;
		first = first->next;
		delete time_ptr;
	}
	dec_size--;
}

std::ostream& operator<<(std::ostream& os, const Dequeue& d)
{
	struct Dequeue::Node* cnt_ptr = d.first;
	while (cnt_ptr) {
		cnt_ptr->object->file_out();
		cnt_ptr = cnt_ptr->next;
	}
	return os;
}

void Dequeue::Show()
{
	if (dec_size == 0)
	{
		std::cout << "There's nothing here. Please add data!\n" << std::endl;
		return;
	}
	struct Dequeue::Node* cnt_ptr = first;
	while (cnt_ptr) {
		University::ObjectType type = cnt_ptr->object->type();
		switch (type)
		{
		case University::ObjectType::STUD:
			std::cout << (Student&)*(cnt_ptr->object);
			break;
		case University::ObjectType::PROF:
			std::cout << (Professor&)*(cnt_ptr->object);
			break;
		case University::ObjectType::AW:
			std::cout << (Administration&)*(cnt_ptr->object);
			break;
		default:
				throw ("Wrong input!");
		}
		cnt_ptr = cnt_ptr->next;
	}
}

University* Dequeue::operator[](int index)
{
	try {
		if (index >= this->dec_size) {
			throw ("Wrong index!");
		}
	}
	catch (const char* c) {
		std::cout << "Wrong index!\n" << std::endl;
	}
	struct Dequeue::Node* cnt_ptr = first;
	while (index--){
		cnt_ptr = cnt_ptr->next;
	}
	return cnt_ptr->object;
}