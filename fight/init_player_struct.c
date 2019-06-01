/*
** EPITECH PROJECT, 2019
** player
** File description:
** struct
*/

#include "my.h"

sfSprite *create_sprite(char *file_path)
{
    sfTexture *texture;
    sfSprite *back_ground;

    texture = sfTexture_createFromFile(file_path, NULL);
    sfTexture_setRepeated(texture, sfTrue);
    back_ground = sfSprite_create();
    sfSprite_setTexture(back_ground, texture, 0);
    return (back_ground);
}

void init_clock_player(cl_t *clock)
{
    clock->clock = sfClock_create();
    clock->delay = 55000;
    clock->x = 64 * 0;
    clock->y = 64 * 0;
    clock->pos_x = 50;
    clock->pos_y = 350;
}

void init_clock_enemy(cl_t *clock)
{
    clock->clock = sfClock_create();
    clock->delay = 55000;
    clock->x = 64 * 0;
    clock->y = 64 * 0;
    clock->pos_x = 1000;
    clock->pos_y = 350;
}

void init_player_struct(entity_t *player, bool sword, bool shield)
{
    cl_t *cl = my_calloc(sizeof(cl_t), 1);

    init_clock_player(cl);
    player->clock = cl;
    player->sprite = create_sprite("fight/img/player.png");
    sfSprite_scale(player->sprite, vector(4, 4));
    player->name = "XxBGdu31xX";
    player->atk = 150;
    player->hp = 3000;
    player->speed = 75;
    player->sword = sword;
    player->shield = shield;
}
