
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

void GradeTable::swap(vector<Grade> &list, int i, int j) {
  Grade item = list[i];
  list[i] = list[j];
  list[j] = item;
}

/**
 * 快速排序 递归调用
 */
void GradeTable::quickSort(vector<Grade> &list, int l, int r) {
  if (l >= r)
    return;

  // 用数组最后一个元素作为 partition 的比较基数
  int less = l - 1;
  int more = r;

  int idx = l;

  // 降序
  while (idx < more) {
    if (list[idx].score > list[r].score) {
      swap(list, ++less, idx++);
    } else if (list[idx].score < list[r].score) {
      swap(list, --more, idx);
    } else {
      idx++;
    }
  }
  // // 升序
  //   while (idx < more) {
  //     if (list[idx].score < list[r].score) {
  //       swap(list, ++less, idx++);
  //     } else if (list[idx].score > list[r].score) {
  //       swap(list, --more, idx);
  //     } else {
  //       idx++;
  //     }
  //   }

  swap(list, more, r);

  quickSort(list, l, less);
  quickSort(list, more + 1, r);
}

void GradeTable::sort() {
  if (stuVector.size() > 1)
    quickSort(stuVector, 0, stuVector.size() - 1);
}
