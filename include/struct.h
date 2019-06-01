/*
** EPITECH PROJECT, 2019
** struct
** File description:
** struct
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "fight.h"

#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct inv
{
    sfTexture *i_t;
    sfSprite *i_s;
    sfTexture *sword_t;
    sfSprite *sword_s;
    sfTexture *shield_t;
    sfSprite *shield_s;
    sfTexture *boots_t;
    sfSprite *boots_s;
    bool boots;
    bool sword;
    bool shield;
}inv_t;

typedef struct bt
{
    sfTexture *tex_bt;
    sfSprite *sp_bt;
    sfTexture *tex_bt1;
    sfSprite *sp_bt1;
    sfTexture *tex_bt2;
    sfSprite *sp_bt2;
    int x;
    int y;
    int size_x;
    int size_y;
    int status;
}bt_t;

typedef struct pnj_s
{
    sfSprite *sprite;
    int px;
    int py;
    int x;
    int y;
}pnj_t;

typedef struct st
{
    sfFloatRect rect;
    sfView *view;
    sfView *view1;
    sfRenderWindow *wi;
    sfEvent ev;    
    sfSprite *player;
    sfTexture *tex;
    sfClock *c;
    sfIntRect *act;
    sfText **text;
    sfRenderStates *rstate;
    sfRenderStates *rstate_house;
    sfVector2i tmp2;
    sfVector2i m;
    sfVector2i pm;
    sfVector2i pm2;
    pnj_t **pnj;
    int **mapi;
    int **house;
    int map_nb;
    int size;
    int delay;
    int delay1;
    int delay2;
    int delay3;
    int px;
    int py;
    int move;
    int text_nb;
    int act_nb;
    int mouse;
    int select;
    int x;
    int y;
    int speed;
    bool b;
    bool *actb;
    bool *fight;
    bool *b_geme;
    int geme;
    int geme_nb;
    int life;
    bool win;
    stats_t *stats;
    fight_t *fight1;
    var_t *var;
    inv_t inv;
    sfSprite *life_zone;
    sfSprite *text_zone;
}st_t;

#endif
