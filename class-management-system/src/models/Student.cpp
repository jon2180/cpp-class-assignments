#include "Student.h"

Student::Student(int no, string name) {
  this->no = no;
  this->name = name;
}

void Student::setNo(int no) { this->no = no; }

int Student::getNo() { return no; }

void Student::setName(string name) { this->name = name; }

string Student::getName() { return string(name); }

Student::~Student() {}
