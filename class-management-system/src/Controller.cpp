#include "Controller.h"

Controller::Controller(/* args */) {}

Controller::~Controller() {}

void Controller::run() {
  // 检验是否已登录
  if (!login()) {
    cout << "你已经错误地输入3次密码，自动退出!" << endl;
    return;
  }

  // 进入主界面
  int operation;
  while (true) {
    View::MainOption();
    cin >> operation;
    switch ((int)operation) {
    case 1:
      importData();
      break;
    case 2:
      printAll();
      break;
    case 3:
      randomSelect();
      break;
    case 4:
      queryAndPlusScore();
      break;
    case 5:
      openAlerm();
      break;
    case 6:
      modifySysConf();
      break;
    case 7:
      exitSafely();
      break;
    default:
      cout << "没有您输入的选项，请重新输入";
    }
    cin.clear();
    cin.ignore(24, '\n');
  }
}

bool Controller::login() {
  // 如果已登录，直接返回
  if (loginHandler.getHasLogin()) {
    cout << "已登录" << endl;
    return true;
  }

  int triesCount = 0;
  string username_past;
  string passwd_past;

  while (!loginHandler.getHasLogin() && triesCount <= 3) {
    cout << "您好，请输入用户名及密码以登录系统！(\"提示：查看./doc/"
            "account.txt\")"
         << endl;
    cin >> username_past >> passwd_past;

    if (username_past != "" && passwd_past != "" &&
        loginHandler.check(username_past, passwd_past)) {
      cout << "欢迎您，" << username_past << endl;
      return true;
    } else {
      cout << "用户名或密码 输入错误，请重新输入" << endl;
      triesCount++;
    }
  }
  return false;
}

void Controller::inputStuInfo() {
  int no_temp;
  string name_temp;
  double score_temp;
  cout << "学生信息格式：学号(int) 姓名 分数" << endl;
  while (no_temp != -1) {
    cin >> no_temp >> name_temp >> score_temp;
    if (no_temp != -1)
      table.add(Grade{no_temp, name_temp, score_temp});
  }
  cout << "添加成功!" << endl;
}

void Controller::importStuInfo() {
  int no_temp;
  string name_temp;
  double score_temp;
  ifstream in("./doc/grade.txt", ios::in);

  if (in.good()) {
    while (!in.eof()) {
      in >> no_temp >> name_temp >> score_temp;
      table.add(Grade{no_temp, name_temp, score_temp});
      in.get(); // 读取最后的回车符
      if (in.peek() == '\n')
        break;
      // if (in.peek() == EOF)
      //   break;
    }
    cout << "数据导入成功！" << endl;
  }
  in.close();
}

void Controller::importData() {
  View::SubOption_1();
  int option;
  cin >> option;
  switch (option) {
  case 1:
    inputStuInfo();
    break;
  case 2:
    importStuInfo();
    break;
  default:
    cout << "没有该选项，将回到主菜单" << endl;
  }
}

void Controller::printAll() {
  // 排序操作
  table.sort();
  view.ShowStuInfo(table);
}

bool Controller::plusOrMinusScore(Grade &t) {
  View::SubOption_2_3();

  int option;
  int score_temp;

  cin >> option >> score_temp;

  switch (option) {
  case 1:
    score_temp += t.score;
    t.score = score_temp;
    cout << "学号\t"
         << "姓名\t"
         << "分数" << endl;
    cout << t;
    return true;
  case 2:
    score_temp = t.score - score_temp;
    t.score = score_temp;
    cout << "学号\t"
         << "姓名\t"
         << "分数" << endl;
    cout << t;
    return true;
  default:
    cout << "回到主菜单" << endl;
    return false;
  }
}

void Controller::randomSelect() {
  int i = rand() % table.size();
  cout << "学号\t"
       << "姓名\t"
       << "分数" << endl;

  cout << table[i];

  plusOrMinusScore(table[i]);
}

void Controller::queryAndPlusScore() {
  cout << "\n请输入学号查找\n > ";
  int no_temp = -1;
  cin >> no_temp;

  auto data = table.find(no_temp);
  if (data == table.end()) {
    cout << "没找到" << endl;
    return;
  }

  cout << "学号\t"
       << "姓名\t"
       << "分数\t"
       << "等级" << endl;
  cout << *data;

  plusOrMinusScore(*data);
}

void Controller::openAlerm() {
  time_t now_time;
  now_time = time(NULL);
  cout << "当前时间：" << now_time << endl;
}

void Controller::modifySysConf() {
  View::ShowSettings(sys);

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

  sys.saveSettings();
  cout << "设置成功" << endl;
}

void Controller::exitSafely() {
  // 保存学生信息
  table.saveStuInfo();
  cout << "学生成绩信息已自动保存" << endl;

  // 保存设置信息
  sys.saveSettings();

  exit(0);
}