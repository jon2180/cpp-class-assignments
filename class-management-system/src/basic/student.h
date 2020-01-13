
#ifndef BASIC_STUDENT_H
#define BASIC_STUDENT_H

#include "stdafx.h"

class Student {
public:
  Student();

  Student(int no, string name);
  Student(int no, string name, string email);

  void setNo(int no);
  int getNo();

  void setName(string name);
  string getName();

  void setEmail(string email);
  string getEmail();

  ~Student();

private:
  int no;
  string name;
  string email;
};

#endif
