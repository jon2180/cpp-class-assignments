#include "GameView.h"

GameView::GameView(GameData *data) { this->data = data; }

// UI中的横线
void GameView::printLine() {
  cout << "  |";
  for (int j = 0; j < ROW; j++) {
    if (j == ROW - 1)
      cout << "---";
    else
      cout << "----";
  }
  cout << "|" << endl;
}

// 输出游戏场景
void GameView::printBoard() {
  cout << "  ";
  for (char col = 'A'; col <= 'O'; col++) {
    cout << "| " << col << " ";
  }
  cout << "|" << endl;
  printLine();
  for (int j = 1; j <= ROW; j++) {
    if (j < 10)
      cout << " ";
    cout << j << "";
    for (int i = 1; i <= COL; i++) {
      cout << "|";
      cout << " ";
      cout << transChar(data->getTile(i - 1, j - 1));
      cout << " ";
    }
    cout << "|" << endl;
    printLine();
  }
}

void GameView::printMenu() {
  cout << "===================[ The Most Interesting Gomoku ]=============="
       << endl;
  cout << "\tPlease choose the Game mode:" << endl;
  cout << "\t1. The game of one person" << endl;
  cout << "\t2. The game of two person" << endl;
  cout << "\t3. Exit game" << endl;
  cout << "================================================================"
       << endl;
  cout << "Please enter your choice: ";
}

void GameView::printRules() {
  cout << "=========================[ Game Rules ]========================"
       << endl;
  cout << endl;
  cout << "\t1. Black plays first, white plays later." << endl;
  cout << "\t2. Please enter your stone position. Like \"A1\" \"B5\" " << endl;
  cout << "==============================================================="
       << endl;
}

// 将状态改为对应的字符
// 1 for black, 0 for white
// "o" for white, "x" for black, " " for blank
char GameView::transChar(int state) {
  if (state == BLACK)
    return 'o';
  else if (state == WHITE)
    return 'x';
  else
    return ' ';
}

GameView::~GameView() = default;