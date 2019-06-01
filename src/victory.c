/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** csfml
*/

#include "my.h"

int event_r(sfRenderWindow *wi, int exit)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(wi, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(wi);
        if (event.type == sfEvtKeyPressed)
           exit = 1;
        if (exit)
            return (exit);
    }
}

void disp_win(sfRenderWindow *wi, int b)
{
    int exit = 0;
    sfTexture *t_game = NULL;
    sfSprite *s_game = NULL;

    sfRenderWindow_clear(wi, sfBlack);
    if (b == 1)
        s_game = print_img("src/img/win_lose/win.png", &t_game, s_game);
    else
        s_game = print_img("src/img/win_lose/lose.png", &t_game, s_game);
    while (exit != 1 && sfRenderWindow_isOpen(wi)) {
        exit = event_r(wi, exit);
        sfRenderWindow_drawSprite(wi, s_game, NULL);
        sfRenderWindow_display(wi);
    }
}