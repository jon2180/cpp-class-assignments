
#ifndef LOGIN_H
#define LOGIN_H

#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Login {
private:
  map<string, string> userList{};

  bool hasLogin = false; //是否已登录

  string currUsername;

  const string accountConf = "./doc/account.txt";

public:
  Login(/* args */);

  bool getHasLogin();

  void logout();

  bool signup(const string& username, const string& password);

  bool check(const string& username, const string& password);

  bool contains(const string& username);

  void writeAccount2File();

  ~Login();
};

#endif
