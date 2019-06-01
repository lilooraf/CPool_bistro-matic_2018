/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"
#include "struct.h"
#include "fight.h"

void check_win(st_t *st)
{
    if (st->geme == st->geme_nb) {
        st->win = true;
        st->b = false;
    }
    if (st->life <= 0) {
        st->win = false;
        st->b = false;
    }
    if (st->inv.boots)
        st->speed = 3;
}

void disp_all(st_t *st)
{
    anim_player(st);
    display_pnj(st);
    check_action(st);
    check_win(st);
    draw_inventory(&st->inv, st);
}

bool game(st_t *st)
{
    sfVertexArray *map[st->map_nb];
    sfVertexArray *house[2];

    st->b = display_menu(st->wi);
    for (int i = 0; i <= st->map_nb; i++)
        map[i] = init_map(st->mapi[i], st->size, st->size);
    for (int i = 0; i <= 2; i++)
        house[i] = init_house(st->house[i], 14, 14);
    for (st->move = -1 ;sfRenderWindow_isOpen(st->wi) && st->b; st->move = -1) {
        event(st);
        key_event(st, map[1]);
        sfView_setCenter(st->view, vec(st->x, st->y));
        sfRenderWindow_setView(st->wi, st->view);
        sfRenderWindow_clear(st->wi, sfBlack);
        disp_map(st, map, house);
        disp_all(st);
        sfRenderWindow_display(st->wi);
    }
    return (st->win);
}

int main(int ac, char **av)
{
    st_t st;
    sfMusic *music;

    if (ac != 1)
        return 84;
    st = init_st(1200, 800, 0.28);
    music = music_p("src/music/music_rpg.wav");
    if (game(&st))
        disp_win(st.wi, 1);
    else if (st.life == 0)
        disp_win(st.wi, 0);
    sfRenderWindow_destroy(st.wi);
    sfMusic_stop(music);
    sfMusic_destroy(music);
    return 0;
}