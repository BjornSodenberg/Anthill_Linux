#include "Ants.hpp"

int Ant::getpos(struct ant_setting ant_ini,int *x,int *y)
{
  *x = ant_ini.x;
  *y = ant_ini.y;
}
int Ant::move(int *x, int *y){
    
    r_x = rand()%60 - rand()% 60 + rand()%60;
    r_y = rand()%60 - rand()% 60 + rand()%60;
    if(r_x > 30) *x += speed;
    else *x -=speed;
    if(r_y > 30) *y += speed;
    else *y -=speed;
    return 0;
}

int Ant::move(int *x, int *y, int x_enemy, int y_enemy)
{
//    *x = x_enemy;//^ v
//    *y = y_enemy-1;//------------->
    if(*y < y_enemy-1){
        *y+=speed;
    }
    else if(*y > y_enemy-1){
        *y-=speed;
    }
    else if(*y == y_enemy-1 ){
        flg_x = 1;
    }
    if(flg_x == 1){
        if(*x >= x_enemy){
            *x-=speed;
        }
        else if(*x <= x_enemy){
            *x+=speed;
        }
        else if(*x == x_enemy){
            *x+=0;
        }
        flg_x = 0;
    }
    return 0;
}
