#include "Menu.hpp"

int main(int argc, char const *argv[]) {

  initscr();
  cbreak();
  noecho();

  Menu menu_win;

  menu_win.initMenu();
  // menu_win.drawMenu();
  while (1) {
    if(getch() == 'q'){
      break;
    }
  }
	endwin();
}
