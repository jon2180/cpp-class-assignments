/**
 * Project： 五子棋 Gomoku
 * Version: 1.1.0
 * Updated: Dec 17
 * Author: Infinity, 李犁生
 */

#include "Game.h"

Game::Game() { initGame(); }

// 初始化游戏
void Game::initGame() {
  player01.setId(1001);
  player01.setColor(BLACKSTONE);

  player02.setId(1002);
  player02.setColor(WHITESTONE);

  for (int j = 1; j <= MAXROW; j++) {
    for (int i = 1; i <= MAXCOL; i++) {
      int tmpKey = trans(i, j);
      Grid tmpGrid;
      tmpGrid.setState(NOTSET);
      tmpGrid.setPos(i, j);
      chess.insert(pair<int, Grid>(tmpKey, tmpGrid));
    }
  }
}

// 运行游戏
void Game::runGame() {
  cout << "===================[ The Most Interesting Gomoku ]=============="
       << endl;
  cout << "\tPlease choose the Game mode:" << endl;
  cout << "\t1. The game of one person" << endl;
  cout << "\t2. The game of two person" << endl;
  cout << "\t3. Exit game" << endl;
  cout << "================================================================"
       << endl;
  cout << "Please enter your choice: ";
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

void Game::onePlayerMode() {
  cout << "\tAI is Not ready yet. The game could not continue.";
  return;
}

void Game::twoPlayerMode() {
  Player p;
  // 初始化 p 为 player02
  // while中会交换， 结果仍然是黑棋先行
  p = player02;

  while (1) {
    system("cls");
    cout << "=========================[ Game Rules ]========================"
         << endl;
    cout << endl;
    cout << "\t1. Black plays first, white plays later." << endl;
    cout << "\t2. Please enter your stone position. Like \"A1\" \"B5\" "
         << endl;
    cout << "==============================================================="
         << endl;
    display();
    WHOWIN winner = checkWin();
    switch (winner) {
    case DRAWNGAME:
      cout << "\tDrawn Game" << endl;
      runGame();
      break;
    case WHITEWIN:
      cout << "\tWhite Win\n" << endl;
      runGame();
      break;
    case BLACKWIN:
      cout << "\tBlack Win\n" << endl;
      runGame();
    case CONTINUE:
      break;
    }

    p = (player01 == p) ? player02 : player01;
    string notice = (p.getColor() == WHITESTONE) ? "White" : "Black";
    cout << notice << ": ";

    bool isSetted = false;
    try {
      isSetted = setChessman(p);
    } catch (not_in_range &e) {
      cout << e.what();
    };
    if (isSetted == false) {
      p = (player01 == p) ? player02 : player01;
    }
  }
}

// 输出游戏场景
void Game::display() {
  cout << "  ";
  for (char col = 'A'; col <= 'O'; col++) {
    cout << "| " << col << " ";
  }
  cout << "|" << endl;
  line();
  //
  int tmpKey;
  for (int j = 1; j <= MAXROW; j++) {
    if (j < 10)
      cout << " ";
    cout << j << "";
    for (int i = 1; i <= MAXCOL; i++) {
      cout << "|";
      cout << " ";

      // TODO
      tmpKey = trans(i, j);
      cout << transChar(chess[tmpKey].getState());

      cout << " ";
    }
    cout << "|" << endl;
    line();
  }
}

//========================================================================
//文件操作
void Game::writeToFile() {
  ofstream stonePos("stonePos.txt", ios::out);
  if (stonePos.is_open()) {
    stonePos << "125"
             << " "
             << "A"
             << "2" << endl;
  }
}

//========================================================================

// 落子
bool Game::setChessman(Player p) {
  int posX[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  char x;
  int posY;
  cin >> x >> posY;

  // 如果输入的x值不在范围
  if (x < 'A' || (x > 'O' && x < 'a') || x > 'o') {
    throw not_in_range();
    return false;
  }
  // 如果输入的y值不在范围
  if (posY < 1 || posY > MAXROW) {
    throw not_in_range();
    return false;
  }

  // posX 的下标
  int i = x - 'A';

  if (x >= 'a' && x <= 'o') {
    i = x - 'a';
  }

  int tmpKey = trans(posX[i], posY);
  // 检测该位置能否下子
  if (!CheckCanSet(chess[tmpKey]))
    return false;
  // 下子
  chess[tmpKey].setState(p.getColor());
  writeToFile();
  return true;
}

// 检测是否出现输赢或和局
WHOWIN Game::checkWin() {
  bool isWin = false;
  int gridCount = 0;
  int notSetCount = 0; // 还没有下子的格子的数目
  map<int, Grid>::iterator iter;
  //遍历格子
  for (iter = chess.begin(); iter != chess.end(); iter++) {
    //检测临近格子
    int x = iter->second.getPosX();
    int y = iter->second.getPosY();
    // 检测第一种胜利情况（往右）
    int i;
    for (i = 1; i < 5; i++) {
      if (x < 0 || x > 11)
        break;
      int tmpKey = trans(x + i, y);
      if (chess[tmpKey].getState() != iter->second.getState()) {
        isWin = false;
        break;
      }
    }
    if (i == 5) {
      isWin = true;
      if (iter->second.getState() == WHITESTONE)
        return WHITEWIN;
      else if (iter->second.getState() == BLACKSTONE)
        return BLACKSTONE;
    }
    // 检测第二种胜利情况（往下）
    for (i = 1; i < 5; i++) {
      if (y < 0 || y > 11)
        break;
      int tmpKey = trans(x, y + i);
      if (chess[tmpKey].getState() != iter->second.getState()) {
        isWin = false;
        break;
      }
    }
    if (i == 5) {
      isWin = true;
      if (iter->second.getState() == WHITESTONE)
        return WHITEWIN;
      else if (iter->second.getState() == BLACKSTONE)
        return BLACKSTONE;
    }

    // 检测第三种胜利情况（往右下）
    for (i = 1; i < 5; i++) {
      if ((x < 0 || x > 11) || (y < 0 || y > 11))
        break;
      int tmpKey = trans(x + i, y + i);
      if (chess[tmpKey].getState() != iter->second.getState()) {
        isWin = false;
        break;
      }
    }
    if (i == 5) {
      isWin = true;
      if (iter->second.getState() == WHITESTONE)
        return WHITEWIN;
      else if (iter->second.getState() == BLACKSTONE)
        return BLACKSTONE;
    }

    // 检测第四种胜利情况(左下)
    for (i = 1; i < 5; i++) {
      if ((x < 5 || x > 15) || (y < 0 || y > 11))
        break;
      int tmpKey = trans(x - i, y + i);
      if (chess[tmpKey].getState() != iter->second.getState()) {
        isWin = false;
        break;
      }
    }
    if (i == 5) {
      isWin = true;
      if (iter->second.getState() == WHITESTONE)
        return WHITEWIN;
      else if (iter->second.getState() == BLACKSTONE)
        return BLACKSTONE;
    }

    // 检测是否和局，棋盘是否已满但无胜利
    if (iter->second.getState() == NOTSET) {
      notSetCount++;
    }
    gridCount++;
  }
  // 检测棋盘上空位置的数量，为0则表示和局
  if (notSetCount == 0) {
    return DRAWNGAME;
  }
  return CONTINUE;
}

// 检测Grid是否能落子
bool Game::CheckCanSet(Grid grid) {
  // if (grid == NULL) return false;
  if (grid.getState() != NOTSET)
    return false;
  return true;
}

Game::~Game() {}

// UI中的横线
void Game::line() {
  cout << "  |";
  for (int j = 0; j < MAXROW; j++) {
    if (j == MAXROW - 1)
      cout << "---";
    else
      cout << "----";
  }
  cout << "|" << endl;
}

// 将横纵坐标转化为map键值
int Game::trans(int x, int y) { return (x * 100 + y); }

// 将map键值解析为其横纵坐标
void Game::parse(int value, int &x, int &y) {
  x = value / 100;
  y = value % 100;
}

// 将状态改为对应的字符
// "o" for white, "x" for black, " " for blank
char Game::transChar(int state) {
  if (state == WHITESTONE)
    return 'o';
  else if (state == BLACKSTONE)
    return 'x';
  else
    return ' ';
}
