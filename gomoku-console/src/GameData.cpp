#include "GameData.h"

#include <cstring>

GameData::GameData(/* args */) { memset(board, NOTSET, sizeof(board)); }

GameData::~GameData() = default;

int GameData::getTile(int x, int y) { return board[y][x]; }
void GameData::setTile(int x, int y, int val) { board[y][x] = val; }

bool GameData::inBoard(int x, int y) {
  return x >= 0 && x < COL && y >= 0 && y < ROW;
}

int GameData::checkWin() {
  // search the whole board
  for (int y = 0; y < ROW; ++y) {
    for (int x = 0; x < COL; ++x) {

      int curr = getTile(x, y);

      if (curr != BLACK && curr != WHITE)
        continue;

      // search the directions
      for (auto i : CHECK_DIRECTION) {

        //
        int count = 1;
        for (int n = 1; n < 5; ++n) {
          int nextX = x + i[0] * n;
          int nextY = y + i[1] * n;

          if (!inBoard(nextX, nextY) || getTile(nextX, nextY) != curr)
            break;
          count++;
        }
        if (count == 5) {
          return curr;
        }
      }
    }
  }

  return 0;
}