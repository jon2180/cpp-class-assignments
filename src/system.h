#pragma once

#include "./basic/stdafx.h"

class System {
public:
  System();

  void setUsername(string username);
  string getUsername();

  void setPasswd(string passwd);
  string getPasswd();

  void SaveAccount();

  void setWasEnrolled(bool was_enrolled);
  bool getWasEnrolled();

  bool Login();

  void setIsAutoCalculate(bool is_auto_calculate);
  bool getIsAutoCalculate();

  void setDefaultMinus(int default_minus);
  int getDefaultMinus();

  void setDefaultPlus(int default_plus);
  int getDefaultPlus();

  void setDefaultClassTime(int default_class_time);
  int getDefaultClassTime();

  void setDefaultAutoLogoutTime(int default_auto_logout_time);
  int getDefaultAutoLogoutTime();

  void setDefaultClass(string default_class);
  string getDefaultClass();

  void SaveSettings();

  ~System();

private:
  string username;
  string passwd;
  bool was_enrolled;            //是否已登录
  bool is_auto_calculate;       //是否自动计算排名/平均分/方差
  int default_minus;            //减分默认值
  int default_plus;             //加分默认值
  int default_class_time;       //课堂默认持续时长
  int default_auto_logout_time; //自动登出时间，不能小于课堂持续时长
  string default_class;         //默认哪个班的课
};
