#ifndef GAME_HPP
#define GAME_HPP

#include <panel.h>
#include "AG.hpp"
#include <unistd.h>
class Game
{
public:
  int initGame();
    char Map[28][72] = {
    "       MMMMMMMMMM                       T                            T ",
    "      MMMMMMMMMMMM                                                     ",
    "     MMMMMMMMMMMMMM            T                     T                 ",
    "    MMMMMMMMMMMMMMMM                                                   ",
    "   MMMMMMMMMMMMMMMMMM                                         T        ",
    "  MMMMMMMMMMMMMMMMMMMM                    T                           T",
    " MMMMMMMMMMMMMMMMMMMMMM                                                ",
    "MMMMMMMMMMMMMMMMMMMMMMMM      T                        T               ",
    "                                                                       ",
    "                                                                       ",
    "                  T                                           T        ",
    "                                            T                          ",
    "        T                                                              ",
    "                        T                                              ",
    "                                                                       ",
    "                                       T                T              ",
    "          T                                                            ",
    "                                                                       ",
    "                                            T                          ",
    "                         T        T                    T               ",
    "                                                                       ",
    "           T                                                           ",
    "                                                                       ",
    "                                           T                           ",
    "                  T                                    T      T        ",
    "                                                                       ",
    "                                    T                                  "
  };
private:
  WINDOW * GUI;
  WINDOW * MAP_BOX;
  WINDOW * COMMAND_BOX;

  PANEL * P_GUI;
  PANEL * P_MAP_BOX;
  PANEL * P_COMMAND_BOX;
  
    int x_rand = 0, y_rand = 0;
    int get_x = 0, get_y = 0;
    int save_x,save_y;
    char tmp_el;
    bool flg_el = 0;
    int speed = 1;
    int r_x;
    int r_cs;
  Enemy * enmy;
  Mother * mthr_ant = new Mother();
  Builder bldr_ants[3] = {
    Builder(rand()%25,rand()%25),
    Builder(rand()%25,rand()%25),
    Builder(rand()%25,rand()%25)
  };
  Fighter fghtr_ants[3] = {
        Fighter(rand()%25,rand()%25),
        Fighter(rand()%25,rand()%25),
        Fighter(rand()%25,rand()%25)
  };
  int count_ants = 6;
  // 103x30

  int lines,cols;
  int lines_map,cols_map;
  int lines_cmd,cols_cmd;

  char anthill_b = 'M';//блоки муравейника
  char trees_b = 'T';//деревья
  char ants = 'C';//муравьи

  bool enemy_flg;

  int printGUI();
  int printMap();
  int printCommands();
  int placeAnts();
  int moveAnts();
  int enemy();
  int target_enemy();
};


#endif
