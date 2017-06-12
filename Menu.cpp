#include "Menu.hpp"

int Menu::initMenu(){
  curs_set(0);
  start_color();
  /*init colors*/
  init_pair(1,COLOR_MAGENTA,COLOR_BLACK);
  init_pair(2,COLOR_BLACK,COLOR_MAGENTA);
  /*get screen size*/
  getmaxyx(stdscr,lines,cols);
  /*Start drawing menu*/
  initBG();
  initMenuItem();
  update_panels();

  drawMenuItem();

  update_panels();

  doupdate();
  return 0;
}

int Menu::initBG(){
  BG = newwin(lines,cols,0,0);
  wbkgd(BG,COLOR_PAIR(1));
  wborder(BG, 0, 0, 0, 0, 0, 0, 0, 0);

  wmove(BG,0,cols/2-6);
  wattron(BG,A_REVERSE);
  wprintw(BG,"  Anthill  ");
  wattroff(BG,A_REVERSE);

  wmove(BG,lines-2,1);
  wprintw(BG,"Ctrl+C for exit");

  P_BG = new_panel(BG);
  return 0;
}

int Menu::initMenuItem(){
  MenuItem = newwin(10,20,6,cols/2-10);
  keypad(MenuItem,TRUE);

  wbkgd(MenuItem,COLOR_PAIR(2));
  wborder(MenuItem, 0, 0, 0, 0, 0, 0, 0, 0);

  wmove(MenuItem,0,8);
  wprintw(MenuItem,"Menu");

  P_MenuItem = new_panel(MenuItem);
  return 0;
}

int Menu::drawMenuItem()
{
  char list[3][9] = {"New game","Rules","About"};
  char item[9];
  int ch, i = 0, t_width = 9;
  flag = true;

  update_panels();

  for( i=0; i<3; i++ ) {
    if( i == 0 )
        wattron( MenuItem, A_STANDOUT ); // highlights the first item.
    else
        wattroff( MenuItem, A_STANDOUT );
    sprintf(item, "%-15s",  list[i]);
    mvwprintw( MenuItem, i+3, 2, "%s", item );
  }

  while(flag){
    ch = wgetch(MenuItem);
    sprintf(item, "%-15s",  list[i]);
    mvwprintw( MenuItem, i+3, 2, "%s", item );

    switch( ch ) {
      case KEY_UP:     i--;i = ( i<0 ) ? 2 : i;  break;
      case KEY_DOWN:   i++;i = ( i>2 ) ? 0 : i;  break;
      case tKEY_ENTER: {
        if(i == 2){
          printAbout();flag=false;
        }
        else
        if( i == 0 ) {
          printNewGame();
          flag = false;
        }
        break;
      }
    }

    wattron( MenuItem, A_STANDOUT );
    sprintf(item, "%-15s",  list[i]);
    mvwprintw( MenuItem, i+3, 2, "%s", item);
    wattroff( MenuItem, A_STANDOUT );

  }
  return 0;
}

int Menu::printAbout(){
  hide_panel(P_MenuItem);
  hide_panel(P_BG);
  aboutWin = newwin(lines,cols,0,0);

  wbkgd(aboutWin,COLOR_PAIR(2));
  wborder(aboutWin, 0, 0, 0, 0, 0, 0, 0, 0);
  wmove(aboutWin,0,cols/2-4);

  wattron(aboutWin,A_REVERSE);
  wprintw(aboutWin,"  About  ");
  wattroff(aboutWin,A_REVERSE);

  wmove(aboutWin,lines/2-2,cols/2-7);
  wprintw(aboutWin,"  Anthill inc. ");
  wmove(aboutWin,lines/2-1,cols/2-11);
  wprintw(aboutWin,"  All rights reserved ");
  waddch(aboutWin,ACS_BULLET);

  panels = new_panel(aboutWin);
  update_panels();
  return 0;
}

int Menu::printNewGame()
{
  Game Game_win;
  Game_win.initGame();
  return 0;
}
