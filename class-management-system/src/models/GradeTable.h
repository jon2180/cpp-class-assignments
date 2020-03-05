
#ifndef GRADE_H
#define GRADE_H

// #include "Student.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Grade {
public:
  int no;
  string name;
  double score;

  Grade(int no, string name) : no{no}, name{name} {}
  Grade(int no, string name, double score) : no{no}, name{name}, score{score} {}
  friend ostream &operator<<(ostream &out, Grade &item) {
    out << item.no << "\t" << item.name << "\t" << item.score << "\t"
        << item.getLevel() << endl;
    return out;
  }

  friend ostream &operator<<(ostream &out, const Grade &item) {
    out << item.no << "\t" << item.name << "\t" << item.score << "\t"
        << item.getLevel() << endl;
    return out;
  }

  char getLevel() const {
    if (score > 70 && score < 80) {
      return 'C';
      // level = 'C';
    } else if (score > 80 && score < 90) {
      return 'B';
      // level = 'B';
    } else if (score > 60 && score < 70) {
      return 'D';
      // level = 'D';
    } else if (score > 90) {
      return 'A';
      // level = 'A';

    } else {
      return 'E';
      // level = 'E';
    }
  }
};

class GradeTable {
public:
  GradeTable();

  ~GradeTable();

  void add(Grade stu);

  // Grade find(int no);
  void swap(vector<Grade> &list, int i, int j);
  void quickSort(vector<Grade> &list, int l, int r);
  double getAvg();

  vector<Grade>::iterator find(int no);

  vector<Grade>::iterator begin() { return stuVector.begin(); }
  vector<Grade>::iterator end() { return stuVector.end(); }
  Grade &operator[](size_t i) { return stuVector.at(i); }

  Grade &at(size_t i) { return stuVector.at(i); }

  void saveStuInfo();

  void sort();

  int size() const { return stuVector.size(); }

private:
  vector<Grade> stuVector{};
  const string gradeConf{"./doc/grade.txt"};

  double avg;
};

#endif
