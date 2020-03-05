#include "Login.h"

Login::Login() {
  ifstream in{accountConf, ios::in};
  string username;
  string password;
  while (!in.eof()) {
    in >> username >> password;
    if (username != "" && password != "")
      userList.insert(pair<string, string>{username, password});
  }
  in.close();
}

Login::~Login() {}

bool Login::getHasLogin() { return hasLogin; }

void Login::logout() { hasLogin = false; }

bool Login::signup(string username, string password) {
  auto result = userList.find(username);
  // 如果不存在这个账号
  if (result == userList.end()) {
    userList.insert(pair<string, string>{username, password});
    return true;
  }
  // 检测结果是否正确
  return false;
}

bool Login::check(string username, string password) {
  auto result = userList.find(username);
  // 如果不存在这个账号
  if (result == userList.end())
    return false;
  // 检测结果是否正确
  if (result->second == password) {
    hasLogin = true;
    currUsername = result->first;
    return true;
  } else
    return false;
}

bool Login::containes(string username) {
  return userList.find(username) != userList.end();
}

void Login::writeAccount2File() {
  ofstream out(accountConf, ios::out);
  if (out.good())
    for (const auto &item : userList) {
      out << item.first << ' ' << item.second << endl;
    }
  out.close();
}