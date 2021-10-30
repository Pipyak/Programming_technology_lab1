#include "Keeper.h"
using std::cout;
using std::cin;
using std::endl;

std::ostream& operator<<(std::ostream& os, University& u) {
	os <<"'s name:" << u.FIO << endl;
	return os;
}

std::istream& operator>>(std::istream& is, University& u) {
	while (is.get() != '\n'){}
	std::getline(is, u.FIO);
	return is;
}

std::ostream& operator<<(std::ostream& os, Student& s) {
	os << "1.Student";
	os << (University&)s;
	os << "2.Course:" << s.course <<endl;
	os << "3.Group:" << s.group << endl;
	os << "4.Name of speciality:" << s.sp_name << endl;
	os << "5.Average score:" << s.av_score << endl;
	os << "--------------------------" << endl;
	return os;
}

std::istream& operator>>(std::istream& is, Student& s) {
	cout << "Input student's name:";
	is >> (University&)s;
	cout<<"Input course:" ;
	is>> s.course;
	cout << "Input group:";
	is >> s.group;
	cout << "Input name of speciality:";
	is >> s.sp_name;
	cout << "Average score:";
	is >> s.av_score;
	return is;
}

std::ostream& operator<<(std::ostream& os, Professor& p) {
	os << "1.Professor";
	os << (University&)p << endl;
	os << "2.Groups: "<< endl;
	for (int i = 0; i < p.g_size; i++)
	{
		os <<'\t'<<i+1 <<")"<<p.groups[i] << endl;
	}
	os << "3.Subjects: "<<endl;
	for (int i = 0; i < p.s_size; i++)
	{
		os <<'\t'<< i+1 << ")" << p.subjects[i] << endl;
	}
	os << "--------------------------"<<endl;
	return os;
}

std::istream& operator>>(std::istream& is, Professor& p) {
	cout << "Input professor's name:";
	is >> (University&)p;
	cout << "Input number of groups:";
	is >> p.g_size;
	cout << "Input groups:\n";
	p.groups = new int[p.g_size];
	for (int i = 0; i < p.g_size; i++)
	{
		cout << i + 1 << ".";
		is >> p.groups[i];
	}
	cout << "Input number of subjects:";
	is >> p.s_size;
	cout << "Input subjects:\n";
	p.subjects = new std::string[p.s_size];
	while (is.get() != '\n') {}
	for (int i = 0; i < p.s_size; i++)
	{
		cout << i + 1<<".";
		std::getline(is, p.subjects[i]);
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, Administration& a) {
	os << "1.Administration_worker";
	os << (University&)a;
	os <<"2.Telephone number:" << a.tel_num << endl;
	os <<"3.Position:" <<a.position << endl;
	os <<"4.Responsibility:" <<a.responsibility << endl;
	os << "--------------------------" << endl;
	return os;
}

std::istream& operator>>(std::istream& is, Administration& a) {
	cout << "Input name of administration worker:";
	is >> (University&)a;
	cout << "Input telephone number:";
	is >> a.tel_num;
	cout << "Input position:";
	while (is.get() != '\n') {}
	getline(is, a.position);
	cout << "Input responsibility:";
	getline(is, a.responsibility);
	return is;
}



