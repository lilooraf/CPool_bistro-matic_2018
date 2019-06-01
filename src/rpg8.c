/*
** EPITECH PROJECT, 2019
** rpg8
** File description:
** rpg8
*/

#include "my.h"
#include "struct.h"

void cut_pnj_sprite(st_t *st, int index)
{
    sfIntRect rect;

    rect.top = st->pnj[index]->y * 32;
    rect.left = st->pnj[index]->x * 32;
    rect.height = 32;
    rect.width = 32;
    sfSprite_setTextureRect(st->pnj[index]->sprite, rect);
}

void pnj_sprite(st_t *st, int index)
{
    cut_pnj_sprite(st, index);
    sfRenderWindow_drawSprite(st->wi, st->pnj[index]->sprite, NULL);
    sfSprite_setPosition(st->pnj[index]->sprite,
    vector(st->pnj[index]->px - 6, st->pnj[index]->py - 12));
}

void init_pnj_struct_bis(pnj_t **pnj)
{
    pnj[0]->py = 256;
    pnj[0]->px = 214;
    pnj[0]->y = pnj[1]->y = 0;
    pnj[0]->x = pnj[1]->x = 7;
    pnj[1]->py = 1812;
    pnj[1]->px = 686;
    pnj[2]->py = 478;
    pnj[2]->px = 498;
    pnj[2]->y = 0;
    pnj[2]->x = 1;
    pnj[3]->py = 1003;
    pnj[3]->px = 266;
    pnj[3]->y = 2;
    pnj[3]->x = 0;
    pnj[4]->py = 1422;
    pnj[4]->px = 2326;
    pnj[4]->y = pnj[5]->y = 1;
    pnj[4]->x = pnj[5]->x = 1;
    pnj[5]->py = 2149;
    pnj[5]->px = 1834;
}

void init_pnj_struct(st_t *st)
{
    pnj_t **pnj = my_calloc(sizeof(pnj_t *), 6);

    for (int count = 0; count < 6; count++) {
        pnj[count] = my_calloc(sizeof(st_t), 1);
        pnj[count]->sprite = create_sprite("src/img/player/player.png");
        sfSprite_scale(pnj[count]->sprite, vector(0.5, 0.5));
    }
    init_pnj_struct_bis(pnj);
    st->pnj = pnj;
}

void display_pnj(st_t *st)
{
    for (int index = 0; index < 6; index++)
        pnj_sprite(st, index);
}
