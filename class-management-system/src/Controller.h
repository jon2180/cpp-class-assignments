
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Login.h"
#include "View.h"
#include "models/GradeTable.h"
#include "models/SystemConfiguration.h"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Controller {
private:

  View view{};
  SystemConfiguration sys{};
  Login loginHandler{};
  GradeTable table{};

  void importStuInfo();
  void inputStuInfo();

public:
  Controller(/* args */);

  ~Controller();

  bool login();
  void run();
  /**
   * 导入学生数据, 可选择导入或输入
   */
  void importData();

  /**
   * 输出所有学生成绩表
   */
  void printAll();

  /**
   * 随机选择一个学生进行提问，并可选择加减分
   */
  void randomSelect();

  /**
   * 查找一个指定的学生，并且可以加分或减分
   */
  void queryAndPlusScore();

  /**
   * 课堂时钟，这个应该使多线程运行
   */
  void openAlerm();

  /**
   * 修改系统配置
   */
  void modifySysConf();

  /**
   * 安全退出，退出前保存所有信息
   */
  void exitSafely();
};

#endif