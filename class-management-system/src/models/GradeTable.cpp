
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
// // 快速排序
// // void Sort(Grade s[], int l, int r)  完整函数申明
void Sort(Grade s[], int l, int r) {
  if (l < r) {
    int i = l, j = r;
    Grade x = s[l];
    while (i < j) {
      // 从右向左找第一个小于x的数
      while (i < j && s[j].score >= x.score)
        j--;
      if (i < j)
        s[i++] = s[j];

      // 从左向右找第一个大于等于x的数
      while (i < j && s[i].score < x.score)
        i++;
      if (i < j)
        s[j--] = s[i];
    }
    s[i] = x;
    Sort(s, l, i - 1); // 递归调用
    Sort(s, i + 1, r);
  }
}

void GradeTable::sort() {}
