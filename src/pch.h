// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for
// future builds. This also affects IntelliSense performance, including code
// completion and many code browsing features. However, files listed here are
// ALL re-compiled if any one of them is updated between builds. Do not add
// files that you will frequently be updating here (this negates the performance
// advantage).

#ifndef PCH_H
#define PCH_H

// TODO: add headers that you want to pre-compile here
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

constexpr auto MAXROW = 15;
constexpr auto MAXCOL = 15;

#define SCORECOUNT 10

#define NOTSET 0     // 0 for not set
#define BLACKSTONE 1 // 黑棋为1
#define WHITESTONE 2 // 白棋为2

#define WHOWIN int  // 谁赢了
#define DRAWNGAME 0 // 和局
#define BLACKWIN 1  // 黑赢
#define WHITEWIN 2  // 白赢
#define CONTINUE 3  // 暂无输赢，游戏继续
//
//
//
//
//
//

// id 1001
class not_in_range : public exception {
public:
  const char *what() const throw() {
    return "The data you enter is not within the allowable range.\n";
  }
};

#endif // PCH_H
