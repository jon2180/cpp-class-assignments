
#ifndef GOMOKU_GAME_VIEW
#define GOMOKU_GAME_VIEW

#include "GameData.h"

#include <iostream>
using namespace std;

class GameView {
private:
  /* data */
  GameData *data;

public:
  GameView(GameData *data);
  ~GameView();
  static void printMenu();
  static void printRules();
  void printBoard();
  static void printLine();
  char transChar(int);
};


#endif