#include "SystemConfiguration.h"

SystemConfiguration::SystemConfiguration() {
  ifstream ImportSettings("./doc/settings.txt", ios::in);
  if (!ImportSettings.eof()) {
    ImportSettings >> is_auto_calculate >> default_minus >> default_plus >>
        default_class_time >> default_auto_logout_time >> default_class;
  }
}

/*+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
                                system settings
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

void SystemConfiguration::setIsAutoCalculate(bool is_auto_calculate) {
  this->is_auto_calculate = is_auto_calculate;
}

bool SystemConfiguration::getIsAutoCalculate() { return is_auto_calculate; }

void SystemConfiguration::setDefaultMinus(int default_minus) {
  this->default_minus = default_minus;
}

int SystemConfiguration::getDefaultMinus() { return default_minus; }

void SystemConfiguration::setDefaultPlus(int default_plus) {
  this->default_plus = default_plus;
}

int SystemConfiguration::getDefaultPlus() { return default_plus; }

void SystemConfiguration::setDefaultClassTime(int default_class_time) {
  this->default_class_time = default_class_time;
}

int SystemConfiguration::getDefaultClassTime() { return default_class_time; }

void SystemConfiguration::setDefaultAutoLogoutTime(
    int default_auto_logout_time) {
  this->default_auto_logout_time = default_auto_logout_time;
}

int SystemConfiguration::getDefaultAutoLogoutTime() {
  return default_auto_logout_time;
}

void SystemConfiguration::setDefaultClass(string default_class) {
  this->default_class = default_class;
}

string SystemConfiguration::getDefaultClass() { return string(default_class); }

void SystemConfiguration::saveSettings() {
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

SystemConfiguration::~SystemConfiguration() = default;
