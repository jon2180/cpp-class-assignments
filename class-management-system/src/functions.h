
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ctime>
#include <fstream>
#include <vector>

#include "grade.h"
#include "system.h"

const int N = 3;
Grade stu[N];

vector<Grade> stuVector;

System sys;

/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
                                1. Graphical user interface
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

void MainOption() {
  cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
  cout << "\t\t1. 导入数据" << endl;
  cout << "\t\t2. 随机抽问" << endl;
  cout << "\t\t3. 查询加分" << endl;
  cout << "\t\t4. 分数总览" << endl;
  cout << "\t\t5. 上课计时" << endl;
  cout << "\t\t6. 系统设置" << endl;
  cout << "\t\t7. 退出系统" << endl;
  cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
  cout << "\n请输入选项\n > ";
}

void SubOption_1() {
  cout << "1. 输入学生信息" << endl;
  cout << "2. 批量导入学生信息(test)" << endl;
  cout << "输入其他选项回到主菜单" << endl;
}

void SubOption_2_3() {
  cout << "1. 加分" << endl;
  cout << "2. 减分" << endl;
  cout << "其他. 回到主菜单" << endl;
  // cout << "1 2 选项请继续输入加减的分值" << endl;
  // cout << "如果不输入分值，将以默认分值: 加[" << sys.getDefaultPlus() <<
  // "]减[" << sys.getDefaultMinus() << "]计算" << endl;
  cout << "请输入选项，及分值\n > ";
}

void SubOption_3() {
  cout << "1. 按姓名查找" << endl;
  cout << "2. 按学号查找" << endl;
  cout << "其他选项退出到主菜单" << endl;
  cout << "请输入选项\n > ";
}

void SubOption_6() {
  cout << "1. 设置用户名和密码" << endl;
  cout << "2. 设置其他内容" << endl;
  cout << "其他: 回到主菜单" << endl;
  cout << "请输入选项:\n > ";
}

void ShowSettings() {
  cout << "\t当前设置为：\n";
  cout << "是/否自动计算排名/平均分/方差:" << sys.getIsAutoCalculate() << endl;
  cout << "减分默认值:                  " << sys.getDefaultMinus() << endl;
  cout << "加分默认值:                  " << sys.getDefaultPlus() << endl;
  cout << "课堂默认持续时长:            " << sys.getDefaultClassTime() << endl;
  cout << "自动登出时间，不小于课堂时长: " << sys.getDefaultAutoLogoutTime()
       << endl;
  cout << "默认哪个班的课:              " << sys.getDefaultClass() << endl;
}

void ShowStuInfo() {
  cout << "学号\t"
       << "姓名\t"
       << "邮箱\t"
       << "分数\t"
       << "等级" << endl;
  for (int i = N - 1; i >= 0; i--) {
    cout << stu[i].getNo() << "\t" << stu[i].getName() << "\t"
         << stu[i].getEmail() << "\t" << stu[i].getScore() << "\t"
         << stu[i].getLevel() << endl;
  }
}

/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
                                2. Calculate function
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

void CalculateScore(int i) {
  SubOption_2_3();
  int option;
  int score_temp;
  cin >> option >> score_temp;
  switch (option) {
  case 1:
    score_temp += stu[i].getScore();
    stu[i].setScore(score_temp);
    cout << "学号\t"
         << "姓名\t"
         << "分数" << endl;
    cout << stu[i].getNo() << "\t" << stu[i].getName() << "\t"
         << stu[i].getScore() << endl;
    break;
  case 2:
    score_temp = stu[i].getScore() - score_temp;
    stu[i].setScore(score_temp);
    cout << "学号\t"
         << "姓名\t"
         << "分数" << endl;
    cout << stu[i].getNo() << "\t" << stu[i].getName() << "\t"
         << stu[i].getScore() << endl;
    break;
  default:
    cout << "回到主菜单" << endl;
  }
}

int Query() {
  // cin >> name;
  // return i;
  return 0;
}

/*
void AutoCalculate()
{
        if (sys.getIsAutoCalculate() == true)
        {
        }
        else
        {
                cout << "默认不自动计算名次，您要现在计算么？[y/n] \n > ";
                char Option;
                cin >> Option;
                switch (Option)
                {
                case 'y':
                case 'Y':
                        //Calculate();
                        //自动计算
                        break;
                case 'n':
                case 'N':
                        return;
                default:
                        cout << "没有该选项，将回到主菜单" << endl;
                }
        }
}
*/
void InputStuInfo() {
  int no_temp;
  string name_temp;
  string email_temp;
  int score_temp;
  cout << "学生信息格式：学号(int) 姓名 邮箱 分数" << endl;
  for (int i = 0; i < N; i++) {
    cin >> no_temp >> name_temp >> email_temp >> score_temp;
    stu[i].setNo(no_temp);
    stu[i].setName(name_temp);
    stu[i].setEmail(email_temp);
    stu[i].setScore(score_temp);
  }
  for (int i = 0; i < N; i++) {
    stu[i].saveStuInfo();
  }
}

void ImportStuInfo() {
  int no_temp;
  string name_temp;
  string email_temp;
  int score_temp;
  /*
  cout << "请注意：数据格式应为格式 学号\t姓名\t邮箱\t分数 !
  否则会报错，之后修改"; char *filename; cout << "请输入要读取的文件名：\n > ";
  cin >> filename;
  */
  ifstream ImportInfo("./doc/grade.txt", ios::in);
  if (!ImportInfo.eof()) {
    for (int i = 0; i < N; i++) {
      ImportInfo >> no_temp;
      ImportInfo >> name_temp;
      ImportInfo >> email_temp;
      ImportInfo >> score_temp;
      stu[i].setNo(no_temp);
      stu[i].setName(name_temp);
      stu[i].setEmail(email_temp);
      stu[i].setScore(score_temp);
    }
  }
  cout << "数据导入成功！" << endl;
  ImportInfo.close();
}

/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
                                3. operation functions
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

// operation 1st
void ImportData() {
  system("clear");
  SubOption_1();
  int option;
  cin >> option;
  switch (option) {
  case 1:
    InputStuInfo();
    break;
  case 2:
    ImportStuInfo();
    break;
  default:
    cout << "没有该选项，将回到主菜单" << endl;
  }
}

// opertation 2ed
void RandomSelect() {
  system("clear");
  int i = rand() % N;
  cout << "学号\t"
       << "姓名\t"
       << "分数" << endl;
  cout << stu[i].getNo() << "\t" << stu[i].getName() << "\t"
       << stu[i].getScore() << endl;

  CalculateScore(i);
}

// operation 3rd
void QueryAndPlus() {
  system("clear");
  SubOption_3();

  int temp = -1;
  int option;
  cin >> option;
  string name_temp;
  int no_temp;
  switch (option) {
  case 1:
    cout << "\n请输入姓名\n > ";

    cin >> name_temp;
    for (int i = 0; i < N; i++) {
      if (stu[i].getName() == name_temp) {
        temp = i;
        break;
      }
    }
    break;
  case 2:
    cout << "\n请输入学号\n > ";
    cin >> no_temp;
    for (int i = 0; i < N; i++) {
      if (stu[i].getNo() == no_temp) {
        temp = i;
        break;
      }
    }
    break;
  default:
    cout << "错误输入，回到主菜单" << endl;
    return;
  }
  cout << "学号\t"
       << "姓名\t"
       << "邮箱\t"
       << "分数\t"
       << "等级" << endl;

  cout << stu[temp].getNo() << "\t" << stu[temp].getName() << "\t"
       << stu[temp].getEmail() << "\t" << stu[temp].getScore() << "\t"
       << stu[temp].getLevel() << endl;
  SubOption_2_3();
}

// operation 4th

// 快速排序
// void Sort(Grade s[], int l, int r)  完整函数申明
void Sort(Grade s[], int l, int r) {
  if (l < r) {
    int i = l, j = r;
    Grade x = s[l];
    while (i < j) {
      while (i < j &&
             s[j].getScore() >= x.getScore()) // 从右向左找第一个小于x的数
        j--;
      if (i < j)
        s[i++] = s[j];
      while (i < j &&
             s[i].getScore() < x.getScore()) // 从左向右找第一个大于等于x的数
        i++;
      if (i < j)
        s[j--] = s[i];
    }
    s[i] = x;
    Sort(s, l, i - 1); // 递归调用
    Sort(s, i + 1, r);
  }
}

void SortByScore() {
  system("clear");
  //排序操作
  cout << "按分数从高到低输出？[y/n]" << endl;
  char option;
  cin >> option;
  switch (option) {
  case 'y':
  case 'Y':
    Sort(stu, 0, N - 1);
    break;
  default:
    cout << "将不按分数从高到低输出：" << endl;
  }
  // AutoCalculate();
  ShowStuInfo();
}

// operation 5th
void ClassAlerm() {
  system("clear");
  time_t now_time;
  now_time = time(NULL);
  cout << "当前时间：" << now_time << endl;
}

// operation 6th---------------finished
void SystemSettings() {
  system("clear");
  SubOption_6();
  int option;
  cin >> option;
  if (option == 1) {
    string username_new;
    string passwd_new;
    cout << "请输入您想使用的用户名：\n > ";
    cin >> username_new;
    cout << "请输入您的密码：\n > ";
    cin >> passwd_new;
    sys.setUsername(username_new);
    sys.setPasswd(passwd_new);
    sys.SaveAccount();
    cout << "用户 " << username_new << " 修改成功" << endl;
  } else if (option == 2) {
    ShowSettings();

    bool is_auto_calculate_temp;
    int default_minus_temp;
    int default_plus_temp;
    int default_class_time_temp;
    int default_auto_logout_time_temp;
    string default_class_temp;

    cout << "请按以上顺序依次输入设置项: \n > " << endl;
    cin >> is_auto_calculate_temp >> default_minus_temp >> default_plus_temp >>
        default_class_time_temp >> default_auto_logout_time_temp >>
        default_class_temp;

    sys.setIsAutoCalculate(is_auto_calculate_temp);
    sys.setDefaultMinus(default_minus_temp);
    sys.setDefaultPlus(default_plus_temp);
    sys.setDefaultClassTime(default_class_time_temp);
    sys.setDefaultAutoLogoutTime(default_auto_logout_time_temp);
    sys.setDefaultClass(default_class_temp);

    sys.SaveSettings();
    cout << "设置成功" << endl;
  } else {
    cout << "没有您输入的选项,回到主菜单" << endl;
    return;
  }
}

// operation 7th
void Exit() {
  for (int i = 0; i < N; i++) {
    stu[i].saveStuInfo();
    cout << "学生成绩信息已自动保存" << endl;
  }
  exit(0);
}

/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
                                4. called by main function
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

void Welcome() {
  //检验是否已登录-------------------------------------------
  int i = 1;
  while (true) {
    if (sys.Login() == true) {
      break;
    } else {
      i++;
    }
    if (i > 3) {
      cout << "你已经错误地输入3次密码，自动退出!" << endl;
      Exit();
    }
  }
  //进入主界面----------------------------------------------
  int operation;
  while (true) {
    MainOption();
    cin >> operation;
    switch ((int)operation) {
    case 1:
      ImportData();
      break;
    case 2:
      RandomSelect();
      break;
    case 3:
      QueryAndPlus();
      break;
    case 4:
      SortByScore();
      break;
    case 5:
      ClassAlerm();
      break;
    case 6:
      SystemSettings();
      break;
    case 7:
      Exit();
      break;
    default:
      cout << "没有您输入的选项，请重新输入";
    }
    cin.clear();
    cin.ignore(24, '\n');
  }
}

#endif
