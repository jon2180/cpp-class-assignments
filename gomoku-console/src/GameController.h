#ifndef GOMOKU_GAME_CONTROLLER_H
#define GOMOKU_GAME_CONTROLLER_H

#include "GameData.h"
#include "GameView.h"
#include "pch.h"

#include <fstream>
#include <iostream>
#include <map>

using namespace std;

class GameController {
public:
  GameController();

  void runGame();     //游戏运行接口
  bool setTile(bool); //落子
  int run();
  void onePlayerMode();
  void twoPlayerMode();
  void writeToFile(int, int, const string&); //文件写入
  ~GameController();

private:
  GameData *data;
  GameView *view;
  ofstream stonePos;
};

#endif