/**
 * Project： 五子棋 Gomoku
 * Version: 2.0.0
 * Updated: Mar 3, 2020
 * Author: Infinity, 李犁生
 * 
 * Game controller implementation
 */


#include "GameController.h"

GameController::GameController() {
  data = new GameData();
  view = new GameView(data);
  stonePos = ofstream("stonePos.txt", ios::out);
}

// 运行游戏
void GameController::runGame() {
  GameView::printMenu();
  int playerCount = 2;
  cin >> playerCount;
  switch (playerCount) {
  case 1:
    onePlayerMode();
    break;
  case 2:
    twoPlayerMode();
    break;
  case 3:
    exit(0);
  default:
    cout << "\tChoice is wrong!" << endl;
    exit(0);
  }
}

void GameController::onePlayerMode() {
  cout << "\tAI is Not ready yet. The game could not continue.";
}

void GameController::twoPlayerMode() {
  GameView::printRules();

  switch (run()) {
  case DRAWN:
    cout << "\tDrawn Game" << endl;
    runGame();
    break;
  case WHITE:
    cout << "\tWhite Win\n" << endl;
    runGame();
    break;
  case BLACK:
    cout << "\tBlack Win\n" << endl;
    runGame();
    break;
  }
}

/**
 * 进行游戏
 */
int GameController::run() {
  // 循环
  bool turnBlack = true;
  while (true) {
    view->printBoard();

    int isWin = data->checkWin();
    if (isWin)
      return isWin;

    cout << (turnBlack ? "Black" : "White") << ": ";
    if (setTile(turnBlack)) {
      turnBlack = !turnBlack;
    }
  }
}

//========================================================================
//文件操作
void GameController::writeToFile(int x, int y, const string &player) {
  if (stonePos.is_open()) {
    stonePos << "(" << x << ", " << y << ") " << player << endl;
  }
}

//========================================================================

// 落子
bool GameController::setTile(bool turnBlack) {
  int hashPosX[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  char x;
  int posY;
  cin >> x >> posY;

  // 如果输入的x值不在范围
  if (x < 'A' || (x > 'O' && x < 'a') || x > 'o') {
    return false;
  }
  // 如果输入的y值不在范围
  if (posY < 1 || posY > ROW) {
    return false;
  }

  // posX 的下标
  int pX = hashPosX[x - 'A'];

  if ('a' <= x && x <= 'o'){
    pX = hashPosX[x - 'a'];
  }

  int pY = posY - 1;
  if (GameData::inBoard(pX, pY) && !data->getTile(pX, pY)) {
    data->setTile(pX, pY, turnBlack ? BLACK : WHITE);
    writeToFile(pX, pY, turnBlack ? "Black" : "White");
    return true;
  } else {
    return false;
  }
}

GameController::~GameController() {
  delete data;
  delete view;

  stonePos.close();
}
