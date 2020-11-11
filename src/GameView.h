/**
 * Project： 五子棋 Gomoku
 * Version: 2.0.0
 * Updated: Mar 3, 2020
 * Author: Infinity, 李犁生
 * 
 * Game view definition
 */

#ifndef GOMOKU_GAME_VIEW
#define GOMOKU_GAME_VIEW

#include "GameData.h"

#include <iostream>
using namespace std;

class GameView {
private:
  GameData *data;

public:
  explicit GameView(GameData *data);
  ~GameView();
  static void printMenu();
  static void printRules();
  void printBoard();
  static void printLine();
  static char transChar(int);
};

#endif