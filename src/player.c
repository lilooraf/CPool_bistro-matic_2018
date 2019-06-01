/*
** EPITECH PROJECT, 2018
** player
** File description:
** csfml
*/

#include "my.h"
#include "struct.h"

void set_player(st_t *st)
{
    sfIntRect rect;

    rect.top = st->py;
    rect.left = st->px;
    rect.height = 32;
    rect.width = 32;
    sfSprite_setTextureRect(st->player, rect);
}

void anim_player(st_t *st)
{
    sfTime time = sfClock_getElapsedTime(st->c);

    if (time.microseconds > st->delay && st->move != -1) {
        if (st->px >= 11 * 32)
            st->px = 288;
        else
            st->px = st->px + 32;
        st->py = 32 * st->move;
        sfClock_restart(st->c);
    }
    set_player(st);
    sfRenderWindow_drawSprite(st->wi, st->player, NULL);
    sfSprite_setPosition(st->player, vec(st->x - 6, st->y - 12));
}