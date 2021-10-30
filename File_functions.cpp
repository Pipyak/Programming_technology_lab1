#include "Keeper.h"
#include <fstream>


void University::file_out()
{
	std::ofstream fout("hello.txt", std::ios::app);
	fout << FIO << std::endl;
}

void Student::file_out()
{
	std::ofstream fout("hello.txt", std::ios::app);
	fout << '0' << std::endl;
	University::file_out();
	fout << group << std::endl;
	fout << sp_name << std::endl;
	fout << course << std::endl;
	fout << av_score << std::endl;
	fout.close();
}

void Professor::file_out()
{
	std::ofstream fout("hello.txt", std::ios::app);
	fout << (int)University::ObjectType::PROF << std::endl;
	University::file_out();
	fout << g_size << std::endl;
	for (int i = 0; i < g_size; i++)
		fout << groups[i] << std::endl;
	fout << s_size << std::endl;
	for (int i = 0; i < s_size; i++)
		fout << subjects[i] << std::endl;
	fout.close();
}

void Administration::file_out(){
	std::ofstream fout("hello.txt", std::ios::app);
	fout << (int)University::ObjectType::AW << std::endl;
	University::file_out();
	fout << tel_num << std::endl;
	fout << position << std::endl;
	fout << responsibility << std::endl;
	fout.close();
}

University& University::file_in(std::istream& is){
	while (is.get() != '\n') {}
	getline(is, this->FIO);
	return *this;
}

Student& Student::file_in(std::istream& is){
	University::file_in(is);
	is >> this->group;
	is >> this->sp_name;
	is >> this->course;
	is >> this->av_score;
	return *this;
}

Professor& Professor::file_in(std::istream& is)
{
	University::file_in(is);
	is >> this->g_size;
	this->groups = new int[g_size];
	for (int i = 0; i < g_size; i++)
		is >> this->groups[i];
	is >> this->s_size;
	this->subjects = new std::string[s_size];
	while (is.get() != '\n') {}
	for (int i = 0; i < s_size; i++)
		getline(is, this->subjects[i]);
	return *this;
}

Administration& Administration::file_in(std::istream& is){
	University::file_in(is);
	is >> this->tel_num;
	while (is.get() != '\n') {}
	getline(is, this->position);
	getline(is, this->responsibility);
	return *this;
}

void Keeper::file_out()//запись в файл
{
	std::ofstream fout("hello.txt", std::ios::trunc);
	if (this->objects.isempty()) {
		std::cout << "There are no objects. Please push object and try again." << std::endl;
		return;
	}
	fout << this->objects.size();
	fout << this->objects;
	fout.close();
}

Keeper& Keeper::file_in()//запись из файла
{
	std::ifstream fin("hello.txt");
	int size;
	fin >> size;
	int i = 0, type = 0;
	while (i!=size) {
		fin >> type;
		if (type == int(University::ObjectType::STUD) ) {
			University* ob = new Student;
			ob->file_in(fin);
			this->objects.push_back(ob);
		}
		if (type == int(University::ObjectType::PROF)) {
			University* ob = new Professor;
			ob->file_in(fin);
			this->objects.push_back(ob);
		}
		if (type == int(University::ObjectType::AW)) {
			University* ob = new Administration;
			ob->file_in(fin);
			this->objects.push_back(ob);
		}
		i++;
	}
	return *this;
}

