/**
 * Project： 五子棋 Gomoku
 * Version: 2.0.0
 * Updated: Mar 3, 2020
 * Author: Infinity, 李犁生
 * 
 * Game controller definition
 */

#ifndef GOMOKU_GAME_CONTROLLER_H
#define GOMOKU_GAME_CONTROLLER_H

#include "GameData.h"
#include "GameView.h"
#include "pch.h"

#include <fstream>
#include <iostream>
#include <map>
#include <memory>

using namespace std;

class GameController {
public:
  GameController();

  void start() {
    runGame();
  }

  void runGame();     //游戏运行接口
  bool setTile(bool); //落子
  int run();
  void onePlayerMode();
  void twoPlayerMode();
  void writeToFile(int, int, const string &); //文件写入
  ~GameController();

private:
  GameData *data;
  GameView *view;
  ofstream stonePos;
};

#endif