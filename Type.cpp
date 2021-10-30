#include "Keeper.h"

University::ObjectType Student::type() const{
	return ObjectType::STUD;
}

University::ObjectType Professor::type() const{
	return ObjectType::PROF;
}

University::ObjectType Administration::type() const{
	return ObjectType::AW;
}

