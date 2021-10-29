#pragma once
#ifndef _HEADER_H
#define _HEADER_H
#include <iostream>
class University {
private:
	std::string FIO;
public:
	University() :FIO("None") {};
	explicit University(std::string& s) :FIO(s) {}
	virtual ~University() {}
	enum class ObjectType{ STUD, PROF, AW };
	virtual ObjectType type()const = 0;

	virtual void change();
	virtual void printf() { std::cout << *this; }
	virtual void scanf() { std::cin >> *this; }
	virtual University& file_in();
	virtual void file_out() = 0;
	friend std::ostream& operator<<(std::ostream& os, University& u);
	friend std::istream& operator>>(std::istream& is, University& u);
};

class Student : public University {
private:
	size_t group;
	std::string sp_name;
	size_t course;
	double av_score;
public:
	Student() :University(), group(0), sp_name("None"), course(0), av_score(0.0) {}
	Student(std::string& name, size_t g, std::string& spec, size_t c, double as) :
		University(name), group(g), sp_name(spec), course(c), av_score(as) {}
	virtual~Student() {}

	virtual ObjectType type()const;
	virtual void change();
	virtual void printf() { std::cout << *this; }
	virtual void scanf() { std::cin >> *this; }
	virtual Student& file_in();
	virtual void file_out();
	friend std::ostream& operator<<(std::ostream& os, Student& s);
	friend std::istream& operator>>(std::istream& is, Student& s);
};

class Professor : public University {
private:
	int* groups;
	std::string* subjects;
	int g_size, s_size;
public:
	Professor() :groups(0), g_size(0), s_size(0), subjects(0) {}
	virtual ~Professor() {}

	virtual ObjectType type()const;
	virtual void change();
	void change_g();
	void change_s();
	virtual Professor& file_in();
	virtual void file_out();
	virtual void printf() { std::cout << *this; }
	virtual void scanf() { std::cin >> *this; }
	friend std::ostream& operator<<(std::ostream& os, Professor& p);
	friend std::istream& operator>>(std::istream& is, Professor& p);
};

class Administration :public University {
private:
	std::string tel_num;
	std::string position;
	std::string responsibility;
public:
	Administration() :position("None"), responsibility("None"), tel_num("None") {}
	virtual ~Administration() {}

	virtual ObjectType type()const;
	virtual void change();
	virtual Administration& file_in();
	virtual void file_out();
	virtual void printf() { std::cout << *this; }
	virtual void scanf() { std::cin >> *this; }
	friend std::ostream& operator<<(std::ostream& os, Administration& a);
	friend std::istream& operator>>(std::istream& is, Administration& a);
};
#endif // !_HEADER_H

