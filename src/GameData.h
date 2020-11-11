/**
 * Project： 五子棋 Gomoku
 * Version: 2.0.0
 * Updated: Mar 3, 2020
 * Author: Infinity, 李犁生
 * 
 * Game Data definition
 */

#ifndef GOMOKU_GAME_DATA
#define GOMOKU_GAME_DATA

#include "pch.h"

class GameData {
private:
  int board[ROW][COL]{};
  const int CHECK_DIRECTION[4][2] = {{1, -1}, {1, 0}, {1, 1}, {0, 1}};

public:
  GameData();
  ~GameData();

  int getTile(int, int);
  void setTile(int, int, int);

  int checkWin();
  static bool inBoard(int x, int y);
};

#endif