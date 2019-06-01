/*
** EPITECH PROJECT, 2019
** enemy
** File description:
** struct
*/

#include "my.h"

void enemy1(entity_t *enemy)
{
    cl_t *cl = my_calloc(sizeof(cl_t), 1);

    init_clock_enemy(cl);
    enemy->clock = cl;
    enemy->sprite = create_sprite("fight/img/enemy.png");
    sfSprite_scale(enemy->sprite, vector(4, 4));
    enemy->name = "LittleEnemy";
    enemy->atk = 25;
    enemy->hp = 3000;
    enemy->speed = 25;
    enemy->sword = 0;
    enemy->shield = 0;
}

void enemy2(entity_t *enemy)
{
    cl_t *cl = my_calloc(sizeof(cl_t), 1);

    init_clock_enemy(cl);
    enemy->clock = cl;
    enemy->sprite = create_sprite("fight/img/enemy.png");
    sfSprite_scale(enemy->sprite, vector(4, 4));
    enemy->name = "NormalEnemy";
    enemy->atk = 50;
    enemy->hp = 5000;
    enemy->speed = 25;
    enemy->sword = 0;
    enemy->shield = 0;
}

void enemy3(entity_t *enemy)
{
    cl_t *cl = my_calloc(sizeof(cl_t), 1);

    init_clock_enemy(cl);
    enemy->clock = cl;
    enemy->sprite = create_sprite("fight/img/enemy.png");
    sfSprite_scale(enemy->sprite, vector(4, 4));
    enemy->name = "BigEnemy";
    enemy->atk = 75;
    enemy->hp = 7000;
    enemy->speed = 25;
    enemy->sword = 0;
    enemy->shield = 0;
}

void enemy4(entity_t *enemy)
{
    cl_t *cl = my_calloc(sizeof(cl_t), 1);

    init_clock_enemy(cl);
    enemy->clock = cl;
    enemy->sprite = create_sprite("fight/img/enemy.png");
    sfSprite_scale(enemy->sprite, vector(4, 4));
    enemy->name = "ZeFatMonst3r";
    enemy->atk = 100;
    enemy->hp = 8000;
    enemy->speed = 1000;
    enemy->sword = 0;
    enemy->shield = 0;
}

void init_enemy_struct(entity_t **enemy)
{
    for (int count = 0; count < 4; count++)
        enemy[count] = my_calloc(sizeof(entity_t), 1);
    enemy1(enemy[0]);
    enemy2(enemy[1]);
    enemy3(enemy[2]);
    enemy4(enemy[3]);
}
