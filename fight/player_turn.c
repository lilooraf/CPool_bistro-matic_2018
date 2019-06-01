/*
** EPITECH PROJECT, 2019
** fight
** File description:
** fight
*/

#include "my.h"

void display_text(sfRenderWindow *window, char *str, sfVector2f vect, int size)
{
    sfText *text;

    text = create_text(str, vect, size);
    sfRenderWindow_drawText(window, text, NULL);
}

void player_fight(stats_t *stats, fight_t *fight, int i)
{
    int chance = 0;
    int crit = 2;

    fight->crit = false;
    fight->hp = stats->player->hp;
    if (stats->player->sword)
        chance = 8;
    if ((random() % 10) <= chance) {
        crit = stats->player->atk * 0.5;
        fight->crit = true;
    }
    stats->enemy[i]->hp -= stats->player->atk + crit;
    fight->lose = stats->player->atk + crit;
    if (stats->enemy[i]->hp <= 0)
        fight->win = true;
}

int player_turn(sfRenderWindow *window, stats_t *stats, fight_t *fight, int i)
{
    char *tmp = NULL;

    move_squares(window, stats->player, 1, 1);
    move_squares(window, stats->enemy[i], 0, 0);
    display_text(window, "Press Space...", vector(950, 750), 20);
    display_text(window, "> It's your turn !", vector(50, 550), 60);
    fight->crit ? display_text(window, "> You make a critical hit !",
    vector(50, 650), 40) : 0;
    free(tmp);
    tmp = NULL;
    tmp = my_strcat("> Your enemy loses ",
    my_strcat(my_put_nbr_str(fight->lose), "hp"));
    display_text(window, tmp, vector(50, 700), 40);
    if (fight->win)
        return (1);
    return (0);
}
