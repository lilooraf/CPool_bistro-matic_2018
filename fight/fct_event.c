/*
** EPITECH PROJECT, 2019
** events
** File description:
** events
*/

#include "my.h"

void event_window(sfRenderWindow *window, var_t *var)
{
    sfEvent events;

    while (sfRenderWindow_pollEvent(window, &events)) {
        if (events.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (events.type == sfEvtKeyPressed && events.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
        if (events.type == sfEvtKeyPressed && events.key.code == sfKeySpace) {
            ++var->i;
            var->b = false;
        }
    }
}
