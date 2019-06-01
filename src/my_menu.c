/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

void event_menu(st_t *st)
{
    static int b = 0;

    while (sfRenderWindow_pollEvent(st->wi, &st->ev)) {
        if (st->ev.type == sfEvtClosed)
            sfRenderWindow_close(st->wi);
        st->pm2 = sfMouse_getPositionRenderWindow(st->wi);
        if (st->ev.type == sfEvtMouseButtonPressed)
            st->pm = sfMouse_getPositionRenderWindow(st->wi);
        else
            st->pm.x = st->pm.y = 0;
    }
}

st_t init_st_menu(sfRenderWindow *wi)
{
    st_t st;
    sfVideoMode mode = {1200, 800, 32};

    st.tmp2.x = 0;
    st.tmp2.y = 0;
    st.wi = wi;
    return (st);
}

bool display_menu(sfRenderWindow *wi)
{
    st_t st = init_st_menu(wi);
    bt_t *bt = init_struct_menu();
    sfTexture *te_bg;
    sfSprite *sf_bg = print_img("src/img/background/bg.png", &te_bg, sf_bg);

    sfRenderWindow_setFramerateLimit(st.wi, 60);
    while (sfRenderWindow_isOpen(st.wi) && !bt[1].status && !bt[0].status) {
        event_menu(&st);
        sfRenderWindow_clear(st.wi, sfBlack);
        sfRenderWindow_drawSprite(st.wi, sf_bg, NULL);
        for (int i = 0; i <= 1; i++)
            set_bt(&bt[i], st.wi, &st.pm, &st.pm2);
        sfRenderWindow_display(st.wi);
    }
    sfTexture_destroy(te_bg);
    sfSprite_destroy(sf_bg);
    if (bt[1].status == 1)
        return (false);
    else
        return (true);
}
