/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"
#include "struct.h"
#include "fight.h"

void action9(st_t *st, int i)
{
    if (i == 9) {
        st->x = 19 * 16;
        st->y = 19 * 16;
    }
}

void action0(st_t *st, int i)
{
    if (i == 0 && !st->b_geme[0]) {
        st->geme += 1;
        st->b_geme[0] = true;
    }
    if (i == 1 && !st->b_geme[1]) {
        st->geme += 1;
        st->b_geme[1] = true;
    }
    if (i == 2 && !st->b_geme[2]) {
        st->geme += 1;
        st->b_geme[2] = true;
    }
    if (i == 3 && !st->b_geme[3]) {
        st->geme += 1;
        st->b_geme[3] = true;
    }
    if (i == 4 && !st->b_geme[4]) {
        st->geme += 1;
        st->b_geme[4] = true;
    }
}

void actions(st_t *st, int i)
{
    action5(st, i);
    action6(st, i);
    action7(st, i);
    action8(st, i);
    action9(st, i);
    action0(st, i);
}

void check_action(st_t *st)
{
    for (int i = 0; i < st->act_nb; i++) {
        if ((st->y >= st->act[i].top && st->y <= st->act[i].height)
        && (st->x >= st->act[i].left && st->x <= st->act[i].width)
        && !st->actb[i] && !st->fight[i]) {
            st->actb[i] = true;
            actions(st, i);
        }
        if ((st->y < st->act[i].top || st->y > st->act[i].height ||
        st->x < st->act[i].left || st->x > st->act[i].width) && !st->fight[i])
            st->actb[i] = false;
    }
    set_pos_text(st);
    for (int i = 10; i < 17; i++) {
        if (st->actb[i])
            select_text(st, i);
    }
}

void disp_map(st_t *st, sfVertexArray **map, sfVertexArray **house)
{
    sfIntRect rect;
    sfText *life = create_text_map(int_to_str(st->life),
    vec(st->x + 155, st->y + 93), 40);
    sfText *geme = create_text_map(int_to_str(st->geme),
    vec(st->x + 155, st->y + 83), 40);

    for (int i = 0; i < st->map_nb; i++)
        sfRenderWindow_drawVertexArray(st->wi, map[i], st->rstate);
    sfRenderWindow_drawVertexArray(st->wi, house[0], st->rstate_house);
    sfSprite_setPosition(st->life_zone, vec(st->x + 135, st->y + 79));
    sfRenderWindow_drawSprite(st->wi, st->life_zone, NULL);
    sfRenderWindow_drawText(st->wi, life, NULL);
    sfRenderWindow_drawText(st->wi, geme, NULL);
}
