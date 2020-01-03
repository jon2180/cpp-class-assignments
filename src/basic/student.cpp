#include "student.h"

Student::Student()
{
	no = 0;
	name = "undefined";
	email = "undefined";
}

Student::Student(int no, string name)
{
	this->no = no;
	this->name = name;
}

Student::Student(int no, string name, string email)
{
	this->no = no;
	this->name = name;
	this->email = email;
}

void Student::setNo(int no)
{
	this->no = no;
}

int Student::getNo()
{
	return no;
}

void Student::setName(string name)
{
	this->name = name;
}

string Student::getName()
{
	return string(name);
}

void Student::setEmail(string email)
{
	this->email = email;
}

string Student::getEmail()
{
	return string(email);
}


Student::~Student()
{
}
