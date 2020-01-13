/**
 * Project： 五子棋 Gomoku
 * Version: 1.1.0
 * Updated: Dec 17
 * Author: Infinity, 李犁生
 */

#ifndef GOMOKU_GRID_H
#define GOMOKU_GRID_H

#include "pch.h"

class Grid {
public:
  Grid();
  //棋盘格子的位置设定
  void setPos(int posX, int posY);
  int getPosX();
  int getPosY();
  //格子的状态设定
  void setState(int state);
  int getState();
  ~Grid();

private:
  int state; // 0 for not clicked,  1 for black, 2 for white //统一黑白的值
  int posX;  // 1 <= (posX, posY) <= 15
  int posY;
};

#endif