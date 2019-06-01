/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"
#include "struct.h"
#include "fight.h"

void select_text(st_t *st, int i)
{
    if (i <= 16 && i >= 10) {
    sfSprite_setPosition(st->text_zone, vec(st->x - 120, st->y - 110));
    sfRenderWindow_drawSprite(st->wi, st->text_zone, NULL);
    }
    if (i == 10) {
        st->inv.boots = true;
        sfRenderWindow_drawText(st->wi, st->text[0], NULL);
    }
    (i == 11) ? sfRenderWindow_drawText(st->wi, st->text[1], NULL) : 0;
    (i == 12) ? sfRenderWindow_drawText(st->wi, st->text[2], NULL) : 0;
    (i == 13) ? sfRenderWindow_drawText(st->wi, st->text[3], NULL) : 0;
    (i == 14) ? sfRenderWindow_drawText(st->wi, st->text[4], NULL) : 0;
    (i == 15) ? sfRenderWindow_drawText(st->wi, st->text[5], NULL) : 0;
    if (i == 16) {
        st->inv.shield = true;
        sfRenderWindow_drawText(st->wi, st->text[6], NULL);
    }
}

void action5(st_t *st, int i)
{
    if (i == 5) {
        sfRenderWindow_setView(st->wi, st->view1);
        st->fight[i] = fight_scene(st->wi, st->stats, 3);
        init_stat(st->stats, st->var, st->fight1, *st);
        sfRenderWindow_setView(st->wi, st->view);
        if (st->fight[i]) {
            st->geme += 1;
        }
        else
            st->life -= 1;
    }
}

void action6(st_t *st, int i)
{
    if (i == 6) {
        sfRenderWindow_setView(st->wi, st->view1);
        st->fight[i] = fight_scene(st->wi, st->stats, 0);
        init_stat(st->stats, st->var, st->fight1, *st);
        sfRenderWindow_setView(st->wi, st->view);
        if (st->fight[i]) {
            st->geme += 1;
            st->inv.sword = true;
        }
        else
            st->life -= 1;
    }
}

void action7(st_t *st, int i)
{
    if (i == 7) {
        sfRenderWindow_setView(st->wi, st->view1);
        st->fight[i] = fight_scene(st->wi, st->stats, 1);
        init_stat(st->stats, st->var, st->fight1, *st);
        sfRenderWindow_setView(st->wi, st->view);
        if (st->fight[i]) {
            st->geme += 1;
        }
        else
            st->life -= 1;
    }
}

void action8(st_t *st, int i)
{
    if (i == 8) {
        sfRenderWindow_setView(st->wi, st->view1);
        st->fight[i] = fight_scene(st->wi, st->stats, 2);
        init_stat(st->stats, st->var, st->fight1, *st);
        sfRenderWindow_setView(st->wi, st->view);
        if (st->fight[i]) {
            st->geme += 1;
        }
        else
            st->life -= 1;
    }
}