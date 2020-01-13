/**
 * Project： 五子棋 Gomoku
 * Version: 1.1.0
 * Updated: Dec 17
 * Author: Infinity, 李犁生
*/
#include "Grid.h"

Grid::Grid() { this->state = NOTSET; }

void Grid::setPos(int posX, int posY) {
  if (posX < 1 || posX > 15 || posY < 1 || posY > 15) {
    throw not_in_range();
    return;
  }
  this->posX = posX;
  this->posY = posY;
}

int Grid::getPosX() { return this->posX; }

int Grid::getPosY() { return this->posY; }

void Grid::setState(int state) {
  if (state < NOTSET || state > WHITESTONE) {
    throw not_in_range();
    return;
  }
  this->state = state;
}

int Grid::getState() { return this->state; }

Grid::~Grid() {}
