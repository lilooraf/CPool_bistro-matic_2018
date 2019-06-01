/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"
#include "struct.h"
#include "fight.h"

void set_pos_text(st_t *st)
{
    sfText_setPosition(st->text[0], vec(st->x - 50, st->y - 100));
    sfText_setPosition(st->text[1], vec(st->x - 75, st->y - 100));
    sfText_setPosition(st->text[2], vec(st->x - 57, st->y - 100));
    sfText_setPosition(st->text[3], vec(st->x - 75, st->y - 100));
    sfText_setPosition(st->text[4], vec(st->x - 80, st->y - 100));
    sfText_setPosition(st->text[5], vec(st->x - 97, st->y - 100));
    sfText_setPosition(st->text[6], vec(st->x - 90, st->y - 100));
}

void init_pl2(st_t *st)
{
    st->geme_nb = 9;
    st->b_geme = my_calloc(sizeof(bool), st->geme_nb);
    stats_t *stats = my_calloc(sizeof(stats_t), 1);
    st->stats = stats;
    fight_t *fight = my_calloc(sizeof(fight_t), 1);
    var_t *var = my_calloc(sizeof(var_t), 1);
    st->var = var;
    st->fight1 = fight;
    init_stat(st->stats, st->var, st->fight1, *st);
    inv_t inv;
    init_inv(&inv);
    st->inv = inv;
    st->text_zone = create_sprite("src/img/text_life_zone/tab1.png");
    st->life_zone = create_sprite("src/img/text_life_zone/box.png");
}

void init_pl(st_t *st)
{
    st->player = print_img("src/img/player/player.png", &st->tex, st->player);
    sfSprite_scale(st->player, vec(0.5, 0.5));
    st->c = sfClock_create();
    st->delay = 50000;
    st->px = 288;
    st->py = 0;
    init_pnj_struct(st);
    zone_interact(st);
    st->rstate = init_states("src/img/map/tileset.png");
    st->rstate_house = init_states("src/img/map/tileset_house.png");
    st->win = false;
    st->geme = 0;
    st->life = 4;
    init_pl2(st);
}

st_t init_st2(st_t st, float zoom, sfVideoMode mode)
{
    st.view = sfView_createFromRect(st.rect);
    st.view1 = sfView_createFromRect(st.rect);
    st.speed = 2;
    st.wi = NULL;
    st.x = 174 * 16;
    st.y = 3 * 16;
    st.text_nb = 7;
    st.text = malloc(sizeof(sfText *) * st.text_nb);
    init_text(&st);
    st.wi = sfRenderWindow_create(mode, "Escape", sfTitlebar | sfClose, NULL);
    sfView_zoom(st.view, zoom);
    sfRenderWindow_setFramerateLimit(st.wi, 60);
    return (st);
}

st_t init_st(int size_x, int size_y, float zoom)
{
    st_t st;

    sfVideoMode mode = {size_x, size_y, 32};
    st.size = 180;
    st.map_nb = 9;
    st.mapi = init_mapi("src/map/map.txt", st.size, st.map_nb);
    st.house = init_mapi("src/map/house.txt", 14, 2);
    init_pl(&st);
    st.rect.top = 0;
    st.rect.left = 0;
    st.rect.height = size_y;
    st.rect.width = size_x;
    st = init_st2(st, zoom, mode);
    return (st);
}
