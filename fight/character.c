/*
** EPITECH PROJECT, 2019
** set char
** File description:
** character
*/

#include "my.h"

sfVector2f vector(float x, float y)
{
    sfVector2f vect;

    vect.x = x;
    vect.y = y;
    return (vect);
}

void cut_sprite(entity_t *player)
{
    sfIntRect rect;

    rect.top = player->clock->y;
    rect.left = player->clock->x;
    rect.height = 64;
    rect.width = 64;
    sfSprite_setTextureRect(player->sprite, rect);
}

void move_squares(sfRenderWindow *window, entity_t *player, int start, int end)
{
    sfTime time = sfClock_getElapsedTime(player->clock->clock);

    if (time.microseconds > player->clock->delay) {
        if (player->clock->x >= 64 * end)
            player->clock->x = 64 * start;
        else
            player->clock->x = player->clock->x + 64;
        sfClock_restart(player->clock->clock);
    }
    cut_sprite(player);
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
    sfSprite_setPosition(player->sprite, vector(player->clock->pos_x,
    player->clock->pos_y));
}
