/**
 * Project： 五子棋 Gomoku
 * Version: 1.1.0
 * Updated: Dec 17
 * Author: Infinity, 李犁生
 */

#ifndef GOMOKU_PLAYER_H
#define GOMOKU_PLAYER_H

#include "pch.h"

class Player {
public:
  Player();
  Player(int id, int color);
  Player(const Player &player);
  //玩家身份
  void setId(int id);
  int getId();
  //玩家执棋颜色
  void setColor(int color);
  int getColor();
  //玩家的分数
  void setScore(int score);
  int getMaxScore();

  bool operator==(const Player &p) {
    if (p.id != this->id)
      return false;
    return true;
  }

  ~Player();

private:
  int id;
  int color; //  2 for white, 1 for black, other for audience
  int score[SCORECOUNT];
};

#endif