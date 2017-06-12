#ifndef ANTS_HPP
#define ANTS_HPP

#include <random>

class Ant
{
public:
  enum TypeOfAnt{
    MOTHER,
    BUILDER,
    FIGHTER,
    ENEMY
  };
  enum ColorsOfType{
    RED,
    GREEN,
    YELLOW,
    MAGENTA
  };
  struct ant_setting
  {
    int x;
    int y;
    enum ColorsOfType color;
    int speed;
    enum TypeOfAnt type;
    char body;
  };
  int speed = 1;
  int r_x = 0;
  int r_y = 0;
  int flg_x = 0;
  int flg_y = 0;
  int getpos(ant_setting ant_ini,int *x,int *y);
  int move(int *x, int *y);
  int move(int *x, int *y, int x_enemy, int y_enemy);
};

#endif
