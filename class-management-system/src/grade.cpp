
#include "grade.h"

#include <fstream>

Grade::Grade() {
  score = 0;
  rank = 0;
  level = 'E';
}

Grade::Grade(int score) {
  this->score = score;
  rank = 0;
  setLevel(score);
}

void Grade::setScore(int score) {
  this->score = score;
  setLevel(score);
}

int Grade::getScore() { return score; }

//-----------------------------------
void Grade::saveStuInfo() {
  int no_temp = getNo();
  string name_temp = getName();
  string email_temp = getEmail();
  int score_temp = getScore();
  //保存格式：学号\t姓名\t邮箱\t分数
  ofstream save("./doc/grade.txt", ios::app);
  save << no_temp << "\t" << name_temp << "\t" << email_temp << "\t"
       << score_temp << "\n";
  save.close();
}

void Grade::setRank(int rank) { this->rank = rank; }

int Grade::getRank() { return rank; }

char Grade::getLevel() { return level; }

Grade::~Grade() {}

void Grade::setLevel(int score) {
  char level = 'E';
  if (score > 70 && score < 80) {
    level = 'C';
  } else if (score > 80 && score < 90) {
    level = 'B';
  } else if (score > 60 && score < 70) {
    level = 'D';
  } else if (score > 90) {
    level = 'A';
  } else if (score < 60) {
    level = 'E';
  }
  this->level = level;
}
