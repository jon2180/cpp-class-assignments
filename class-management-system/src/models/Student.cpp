#include "Student.h"

#include <utility>

Student::Student(int no, string name) {
  this->no = no;
  this->name = std::move(name);
}

void Student::setNo(int I) { this->no = I; }

int Student::getNo() { return no; }

void Student::setName(string newName) { this->name = newName; }

string Student::getName() { return string(name); }

Student::~Student() = default;
