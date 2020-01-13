/**
 * Project： 五子棋 Gomoku
 * Version: 1.1.0
 * Updated: Dec 17
 * Author: Infinity, 李犁生
 */

#include "Player.h"

Player::Player() {
  this->id = NOTSET;
  this->color = NOTSET;
}

Player::Player(const Player &player) {
  this->id = player.id;
  this->color = player.color;
}

Player::Player(int id, int color) {
  this->id = id;
  this->color = color;
}

void Player::setId(int id) { this->id = id; }

int Player::getId() { return this->id; }

void Player::setColor(int color) { this->color = color; }

int Player::getColor() { return this->color; }

// 用于记录计时成绩，暂且不计时
void Player::setScore(int score) {
  for (int i = 0; i < SCORECOUNT; i++) {
    // if (score[i] == '\0') {
    //     score[i] = score;
    // }
  }
}

int Player::getMaxScore() {
  int maxScore = this->score[0];
  for (int i = 0; score[i] != '\0'; i++) {
    if (maxScore < score[i]) {
      int tmpScore = score[i];
      score[i] = maxScore;
      maxScore = tmpScore;
    }
  }
  return maxScore;
}

Player::~Player() {}
