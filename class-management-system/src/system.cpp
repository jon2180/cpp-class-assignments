#include "system.h"

#include <fstream>

System::System() {
  ifstream ImportSettings("./doc/settings.txt", ios::in);
  if (!ImportSettings.eof()) {
    ImportSettings >> is_auto_calculate >> default_minus >> default_plus >>
        default_class_time >> default_auto_logout_time >> default_class;
  }

  ifstream ImportEnrolled("./doc/enrolled.txt", ios::in);
  if (!ImportEnrolled.eof()) {
    ImportEnrolled >> was_enrolled;
  }

  ifstream fin("./doc/account.txt", ios::in);
  while (!fin.eof()) {
    fin >> username;
    fin >> passwd;
  }
  fin.close();
}

/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
                                account settings
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

void System::setUsername(string username) { this->username = username; }

string System::getUsername() { return string(username); }

void System::setPasswd(string passwd) { this->passwd = passwd; }

string System::getPasswd() { return string(passwd); }

void System::setWasEnrolled(bool was_enrolled) {
  ofstream openfile("./doc/enrolled.txt", ios::out);
  if (!openfile) {
    cout << "文件不能打开" << endl;
  } else {
    openfile << was_enrolled;
  }
  openfile.close();

  this->was_enrolled = was_enrolled;
}

bool System::getWasEnrolled() { return was_enrolled; }

void System::SaveAccount() {
  ofstream Save("./doc/account.txt", ios::out);
  Save << username << "\t" << passwd;
  Save.close();
}

bool System::Login() {
  if (was_enrolled == false) {
    cout << "欢迎，请注册" << endl;

    cout << "请输入您想使用的用户名：\n > ";
    cin >> username;
    cout << "请输入您的密码：\n > ";
    cin >> passwd;

    SaveAccount();
    was_enrolled = true;
    cout << "用户 " << username << " 注册成功" << endl;

    return true;
  } else {
    string username_past;
    string passwd_past;

    cout << "您好，请登录！" << endl;
    cout << "提示：查看./doc/account.txt" << endl;
    cout << "用户名：\n > ";
    cin >> username_past;
    cout << "密  码：\n > ";
    cin >> passwd_past;

    if (username == username_past && passwd == passwd_past) {
      cout << "欢迎您，" << username << endl;
      return true;
    } else {
      cout << "用户名或密码 输入错误" << endl;
      return false;
    }
  }
}

/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
                                system settings
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

void System::setIsAutoCalculate(bool is_auto_calculate) {
  this->is_auto_calculate = is_auto_calculate;
}

bool System::getIsAutoCalculate() { return is_auto_calculate; }

void System::setDefaultMinus(int default_minus) {
  this->default_minus = default_minus;
}

int System::getDefaultMinus() { return default_minus; }

void System::setDefaultPlus(int default_plus) {
  this->default_plus = default_plus;
}

int System::getDefaultPlus() { return default_plus; }

void System::setDefaultClassTime(int default_class_time) {
  this->default_class_time = default_class_time;
}

int System::getDefaultClassTime() { return default_class_time; }

void System::setDefaultAutoLogoutTime(int default_auto_logout_time) {
  this->default_auto_logout_time = default_auto_logout_time;
}

int System::getDefaultAutoLogoutTime() { return default_auto_logout_time; }

void System::setDefaultClass(string default_class) {
  this->default_class = default_class;
}

string System::getDefaultClass() { return string(default_class); }

void System::SaveSettings() {
  ofstream Save("./doc/settings.txt", ios::out);
  Save << is_auto_calculate << "\n"
       << default_minus << "\n"
       << default_plus << "\n"
       << default_class_time << "\n"
       << default_auto_logout_time << "\n"
       << default_class;
  cout << "自动保存设置成功" << endl;
  Save.close();
}

System::~System() {}
