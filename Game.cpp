#include "Game.hpp"

int Game::initGame()
{
  Game::printGUI();
  Game::printMap();
  Game::printCommands();
  Game::placeAnts();
  Game::printMap();

  char ch;
  while(true) {
    clear();
    Game::moveAnts();
//    Game::placeAnts();
    enemy();
    Game::printMap();
    
    refresh();

    sleep(1);
  }
//  Game::moveAnts();
  return 0;
}

int Game::printGUI()
{
  curs_set(0);
  start_color();
  /*init colors*/
  init_pair(1,COLOR_MAGENTA,COLOR_BLACK);
  init_pair(2,COLOR_BLACK,COLOR_MAGENTA);
  init_pair(3,COLOR_CYAN,COLOR_BLACK);
  init_pair(4,COLOR_BLACK,COLOR_CYAN);
  init_pair(5,COLOR_BLACK,COLOR_WHITE);

  init_pair(6,COLOR_BLACK,COLOR_RED);
  init_pair(7,COLOR_BLACK,COLOR_YELLOW);
  init_pair(8,COLOR_BLACK,COLOR_GREEN);

  /*get screen size*/
  getmaxyx(stdscr,lines,cols);

  /*Start drawing*/
    /*Global gui*/
      GUI = newwin(lines,cols,0,0);
      wbkgd(GUI,COLOR_PAIR(2));
      whline(GUI, ACS_HLINE, cols);

      wmove(GUI,0,cols/2-6);
      wattron(GUI,A_REVERSE);
      wprintw(GUI,"  Anthill  ");
      wattroff(GUI,A_REVERSE);

      P_GUI = new_panel(GUI);
    /***************/
  /***************/

  update_panels();

  doupdate();
  return 0;
}

int Game::printMap()
{
  /*Map box*/
    MAP_BOX = newwin(lines-1,cols-30,1,0);
    wbkgd(MAP_BOX,COLOR_PAIR(4));
    wborder(MAP_BOX, 0, 0, 0, 0, 0, 0, 0, 0);

    getmaxyx(MAP_BOX,lines_map,cols_map);

    wmove(MAP_BOX,0,cols_map/2-4);
    wattron(MAP_BOX,A_REVERSE);
    wprintw(MAP_BOX,"  Map  ");
    wattroff(MAP_BOX,A_REVERSE);

    for (size_t i = 0; i < 28; i++){
        for(size_t j = 0; j < 72; j++){

            switch(Map[i][j])
            {
                case '@':{
                    wattron(MAP_BOX,COLOR_PAIR(6));
                    mvwprintw(MAP_BOX,i+1 , j+1, "%c", Map[i][j]);
                    wattroff(MAP_BOX,COLOR_PAIR(4));
                    break;
                }
                case '0':{
                    wattron(MAP_BOX,COLOR_PAIR(7));
                    mvwprintw(MAP_BOX,i+1 , j+1, "%c", Map[i][j]);
                    wattroff(MAP_BOX,COLOR_PAIR(4));
                    break;
                }
                case 'V':{
                    wattron(MAP_BOX,COLOR_PAIR(8));
                    mvwprintw(MAP_BOX,i+1 , j+1, "%c", Map[i][j]);
                    wattroff(MAP_BOX,COLOR_PAIR(4));
                    break;
                }
                case 'M':{
                    mvwprintw(MAP_BOX,i+1 , j+1, "%c", Map[i][j]);
                    break;
                }
                case 'T':{
                    mvwprintw(MAP_BOX,i+1 , j+1, "%c", Map[i][j]);
                    break;
                }
                case '8':{
                    wattron(MAP_BOX,COLOR_PAIR(2));
                    mvwprintw(MAP_BOX,i+1 , j+1, "%c", Map[i][j]);
                    wattroff(MAP_BOX,COLOR_PAIR(4));
                    break;
                }
                default: {
                    mvwprintw(MAP_BOX,i+1 , j+1, "%c", Map[i][j]);
                }
            }

        }
    }
    P_MAP_BOX = new_panel(MAP_BOX);
    update_panels();
  /***************/
  return 0;
}

int Game::printCommands()
{
  /*Command box*/
    COMMAND_BOX = newwin(lines-1,cols-cols_map-2,1,cols_map+1);
    wbkgd(COMMAND_BOX,COLOR_PAIR(5));
    wborder(COMMAND_BOX, 0, 0, 0, 0, 0, 0, 0, 0);

    getmaxyx(COMMAND_BOX,lines_cmd,cols_cmd);

    wmove(COMMAND_BOX,0,cols_cmd/2-6);
    wattron(COMMAND_BOX,A_REVERSE);
    wprintw(COMMAND_BOX,"  Commands  ");
    wattroff(COMMAND_BOX,A_REVERSE);

    char cmd_items[4][16] = {
      "CTRL+C - exit",
      "r - restart",
      "f - add figher",
      "b - add builder",
    };
    char cmd_item[12];
    for (size_t i = 0; i < 1; i++) {
      sprintf(cmd_item, "%-16s",  cmd_items[i]);
      mvwprintw( COMMAND_BOX, i+2, 2, "%s", cmd_item );

    }

    P_COMMAND_BOX = new_panel(COMMAND_BOX);
    update_panels();
  /***************/

  return 0;
}

int Game::placeAnts()
{
    int tmp_x; int tmp_y;
    srand(time(NULL));
    //init Mother
    mthr_ant->getpos(mthr_ant->ant_mother,&tmp_x,&tmp_y);
    Map[tmp_y][tmp_x] = mthr_ant->ant_mother.body;
//    enemy();
    return 0;
}

int Game::moveAnts()
{
    for(int i = 0; i < 3; i++){
            Map[bldr_ants[i].ant_builder.x][bldr_ants[i].ant_builder.y] = ' ';
            if(bldr_ants[i].ant_builder.x > 9 || bldr_ants[i].ant_builder.y > 24){
                bldr_ants[i].move(&bldr_ants[i].ant_builder.x,&bldr_ants[i].ant_builder.y);
            }
            else
            {
                bldr_ants[i].ant_builder.x +=5;
            }
            bldr_ants[i].getpos(bldr_ants[i].ant_builder,&get_x, &get_y);
            if(Map[get_x][get_y] == ' ') Map[get_x][get_y] = bldr_ants[i].ant_builder.body;
            else
            {
                tmp_el = Map[get_x][get_y];
                save_x = get_x;
                save_y = get_y;
                Map[get_x][get_y] = bldr_ants[i].ant_builder.body;
                flg_el = 1;
            }
            if(flg_el) Map[save_x][save_y] = tmp_el;
    }
    target_enemy();        
    return 0;
}

int Game::enemy()
{
    srand(time(NULL));
    int xenmy,yenmy;
    if(enemy_flg == false){
        enmy = new Enemy(rand()%25,25+rand()%25);
        enmy->getpos(enmy->ant_enemy,&xenmy,&yenmy);
        Map[xenmy][yenmy] = enmy->ant_enemy.body;
        enemy_flg = true;
    }
    return 0;
}

int Game::target_enemy()
{
    int ex,ey;
    if(enemy_flg == true)
    {
        enmy->getpos(enmy->ant_enemy,&ex,&ey);
      for(int i = 0; i < 3; i++){
        Map[fghtr_ants[i].ant_fighter.x][fghtr_ants[i].ant_fighter.y] = ' ';
        //    Move
            if(fghtr_ants[i].ant_fighter.x > 9 || fghtr_ants[i].ant_fighter.y > 24 ){
               
                fghtr_ants[i].move(&fghtr_ants[i].ant_fighter.x,&fghtr_ants[i].ant_fighter.y,ex,ey);
            }
            else
            {
                fghtr_ants[i].ant_fighter.x +=5;
            }
        //    ****
            fghtr_ants[i].getpos(fghtr_ants[i].ant_fighter,&get_x, &get_y);
            if(Map[get_x][get_y] == ' ') Map[get_x][get_y] = fghtr_ants[i].ant_fighter.body;
            else
            {
                tmp_el = Map[get_x][get_y];
                save_x = get_x;
                save_y = get_y;
                Map[get_x][get_y] = fghtr_ants[i].ant_fighter.body;
                flg_el = 1;
            }
            if(flg_el) Map[save_x][save_y] = tmp_el;
            if(fghtr_ants[i].ant_fighter.x == ex && fghtr_ants[i].ant_fighter.y == ey-1){
                enemy_flg = false;
                Map[ex][ey] = ' ';
            }
        }  
    }
    
    return 0;
}