#pragma once
#include "./basic/student.cpp"

class Grade : public Student {
public:
  Grade();
  Grade(int score);

  // score, set level automatically
  void setScore(int score);
  int getScore();

  void saveStuInfo();

  // rank
  void setRank(int rank);
  int getRank();

  // level
  char getLevel();

  virtual ~Grade();

private:
  int score;
  int rank;
  char level;
  void setLevel(int score);
};
