#include "AG.hpp"

Mother::Mother()
{
    struct ant_setting ant_mother;
    ant_mother.x = 13;
    ant_mother.y = 5;
    ant_mother.color = RED;
    ant_mother.speed = 0;
    ant_mother.type = MOTHER;
    ant_mother.body = '@';
}

Builder::Builder()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(13,28);
    struct ant_setting ant_builder;
    ant_builder.x = dist(gen);
    ant_builder.y = dist(gen);
    ant_builder.color = BLUE;
    ant_builder.speed = 0;
    ant_builder.type = BUILDER;
    ant_builder.body = '0';
}

Fighter::Fighter()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(13,28);
    struct ant_setting ant_fighter;
    ant_fighter.x = dist(gen);
    ant_fighter.y = dist(gen);
    ant_fighter.color = YELLOW;
    ant_fighter.speed = 0;
    ant_fighter.type = FIGHTER;
    ant_fighter.body = '0';
}
