#ifndef AG_HPP
#define AG_HPP
#include <stdlib.h>
#include "Ants.hpp"

class Mother: public Ant
{
public:
  struct ant_setting ant_mother;
  Mother(){ 
    
    ant_mother.x = 13;
    ant_mother.y = 5;
    ant_mother.color = RED;
    ant_mother.speed = 0;
    ant_mother.type = MOTHER;
    ant_mother.body = '@';
  }
};

 class Builder: public Ant
 {
  public:
    struct ant_setting ant_builder;
    Builder(int xi, int yi){
      ant_builder.x = xi;
      ant_builder.y = yi;
      ant_builder.color = GREEN;
      ant_builder.speed = 0;
      ant_builder.type = BUILDER;
      ant_builder.body = '0';
    }
 };

 class Fighter: public Ant
 {
  public:
      struct ant_setting ant_fighter;
    Fighter(int xi, int yi){
      ant_fighter.x = xi;
      ant_fighter.y = yi;
      ant_fighter.color = YELLOW;
      ant_fighter.speed = 0;
      ant_fighter.type = FIGHTER;
      ant_fighter.body = 'V';
    }
 };

 class Enemy: public Ant
 {
 public:
     struct ant_setting ant_enemy;
     Enemy(int xi,int yi){
      ant_enemy.x = xi;
      ant_enemy.y = yi;
      ant_enemy.color = MAGENTA;
      ant_enemy.speed = 0;
      ant_enemy.type = ENEMY;
      ant_enemy.body = '8';
     }
 };

#endif
