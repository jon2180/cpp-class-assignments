
#ifndef VIEW_H
#define VIEW_H

#include "models/GradeTable.h"
#include "models/SystemConfiguration.h"

#include <iostream>
using namespace std;

class View {
private:
  /* data */
public:
  View(/* args */);
  static void MainOption();
  static void SubOption_1();
  static void SubOption_2_3();
  static void SubOption_3();
  static void SubOption_6();
  static void ShowSettings(SystemConfiguration&);
  void ShowStuInfo(GradeTable &table) const;
  ~View();
};

#endif