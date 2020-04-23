
#ifndef GOMOKU_GAME_DATA
#define GOMOKU_GAME_DATA

#include "pch.h"

class GameData {
private:
  /* data */
  int board[ROW][COL]{};
  const int CHECK_DIRECTION[4][2] = {{1, -1}, {1, 0}, {1, 1}, {0, 1}};

public:
  GameData(/* args */);
  ~GameData();

  int getTile(int, int);
  void setTile(int, int, int);

  int checkWin();
  static bool inBoard(int x, int y);
};

#endif