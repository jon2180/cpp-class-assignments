
#include "View.h"


View::View(/* args */) {}

View::~View() {}

void View::MainOption() {
  cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
  cout << "\t\t1. 导入数据" << endl;
  cout << "\t\t2. 分数总览" << endl;
  cout << "\t\t3. 查询加分" << endl;
  cout << "\t\t4. 随机抽问" << endl;
  cout << "\t\t5. 上课计时" << endl;
  cout << "\t\t6. 系统设置" << endl;
  cout << "\t\t7. 退出系统" << endl;
  cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
  cout << "\n请输入选项\n > ";
}

void View::SubOption_1() {
  cout << "1. 输入学生信息" << endl;
  cout << "2. 批量导入学生信息(test)" << endl;
  cout << "输入其他选项回到主菜单" << endl;
}

void View::SubOption_2_3() {
  cout << "1. 加分" << endl;
  cout << "2. 减分" << endl;
  cout << "其他. 回到主菜单" << endl;
  // cout << "1 2 选项请继续输入加减的分值" << endl;
  // cout << "如果不输入分值，将以默认分值: 加[" << sys.getDefaultPlus() <<
  // "]减[" << sys.getDefaultMinus() << "]计算" << endl;
  cout << "请输入选项，及分值\n > ";
}

void View::SubOption_3() {
  cout << "1. 按姓名查找" << endl;
  cout << "2. 按学号查找" << endl;
  cout << "其他选项退出到主菜单" << endl;
  cout << "请输入选项\n > ";
}

void View::SubOption_6() {
  cout << "1. 设置用户名和密码" << endl;
  cout << "2. 设置其他内容" << endl;
  cout << "其他: 回到主菜单" << endl;
  cout << "请输入选项:\n > ";
}

void View::ShowSettings(SystemConfiguration& sys) {
  cout << "\t当前设置为：\n";
  cout << "是/否自动计算排名/平均分/方差:" << sys.getIsAutoCalculate() <<
  endl; cout << "减分默认值:                  " << sys.getDefaultMinus() <<
  endl; cout << "加分默认值:                  " << sys.getDefaultPlus() <<
  endl; cout << "课堂默认持续时长:            " << sys.getDefaultClassTime()
  << endl; cout << "自动登出时间，不小于课堂时长: " <<
  sys.getDefaultAutoLogoutTime()
       << endl;
  cout << "默认哪个班的课:              " << sys.getDefaultClass() << endl;
}

void View::ShowStuInfo(GradeTable &table) const {
  cout << "学号\t"
       << "姓名\t"
       << "分数\t"
       << "等级" << endl;
  for (const auto &item : table) {
    cout << item;
  }
}
