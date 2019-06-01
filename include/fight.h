/*
** EPITECH PROJECT, 2018
** matrix
** File description:
** matrix
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Graphics/VertexArray.h>
#include <SFML/Graphics/RenderWindow.h>
#include <stdbool.h>

#ifndef __FIGHT_H_
#define __FIGHT_H_

typedef struct s_fight
{
    int hp;
    bool crit;
    int lose;
    int block;
    bool win;
}fight_t;

typedef struct s_cl
{
    sfClock *clock;
    float pos_x;
    float pos_y;
    int x;
    int y;
    int delay;
}cl_t;

typedef struct s_entity
{
    cl_t *clock;
    sfSprite *sprite;
    char *name;
    int atk;
    int hp;
    int speed;
    bool sword;
    bool shield;
}entity_t;

typedef struct s_var
{
    int i;
    bool b;
    sfSprite *bg;
}var_t;

typedef struct s_stats
{
    entity_t *player;
    entity_t **enemy;
    var_t *var;
    fight_t *fight;
    int hp;
}stats_t;

#endif
