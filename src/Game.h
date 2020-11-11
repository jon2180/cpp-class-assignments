#ifndef GOMOKU_GAME_H
#define GOMOKU_GAME_H

#include "Grid.h"
#include "Player.h"
#include "pch.h"

#include <iostream>
#include <map>

using namespace std;

class Game {
public:
  Game();
  void initGame();            //初始化游戏
  void runGame();             //游戏运行接口
  void display();             //棋盘打印
  bool setChessman(Player p); //落子
  WHOWIN checkWin();          //胜负判断
  //坐标处理
  int trans(int x, int y);
  void parse(int value, int &x, int &y);
  char transChar(int state);

  bool CheckCanSet(Grid grid);
  void onePlayerMode();
  void twoPlayerMode();
  void writeToFile(); //文件写入
  ~Game();

private:
  Player player01;
  Player player02;
  map<int, Grid> chess;

  void line();
};

#endif