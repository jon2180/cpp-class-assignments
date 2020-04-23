
#include "GradeTable.h"

#include <fstream>

GradeTable::GradeTable() {}
GradeTable::~GradeTable() {}

void GradeTable::add(Grade stu) { stuVector.push_back(stu); }

vector<Grade>::iterator GradeTable::find(int no) {
  auto iter = stuVector.begin();
  for (; iter != stuVector.end(); iter++) {
    if (iter->no == no)
      return iter;
  }
  return stuVector.end();
}

double GradeTable::getAvg() {
  double total = 0;
  for (const auto &item : stuVector) {
    total += item.score;
  }
  return total / stuVector.size();
}

void GradeTable::saveStuInfo() {
  //保存格式：学号\t姓名\t分数
  ofstream save(gradeConf, ios::out);
  if (save.good())
    for (const auto &item : stuVector) {
      save << item.no << "\t" << item.name << '\t' << item.score << endl;
    }
  save.close();
}

void GradeTable::sort() {
  if (stuVector.size() > 1)
    std::sort(stuVector.begin(), stuVector.end());
}
