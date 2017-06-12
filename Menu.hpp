#ifndef MENU_HPP
#define MENU_HPP

#include <panel.h>
#include "Game.hpp"
#define tKEY_ENTER 10

class Menu
{
public:
  int initMenu();
private:
  WINDOW * BG;
  PANEL * P_BG;

  WINDOW * MenuItem;
  PANEL * P_MenuItem;

  WINDOW* aboutWin;
  PANEL * panels;

  int lines, cols;

  bool flag;

  int initBG();
  int initMenuItem();
  int drawMenuItem();
  int printAbout();
  int printNewGame();
};


#endif
