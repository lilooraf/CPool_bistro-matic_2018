/*
** EPITECH PROJECT, 2019
** enemy
** File description:
** turn
*/

#include "my.h"

void enemy_fight(stats_t *stats, fight_t *fight, int i)
{
    int crit = 0;
    float def = 1;

    fight->crit = false;
    fight->block = false;
    fight->hp = stats->enemy[i]->hp;
    if ((random() % 10) <= 1) {
        crit = stats->enemy[i]->atk * 0.5;
        fight->crit = true;
    }
    if (stats->player->shield) {
        def = 0.9;
        if ((random() % 10) <= 7) {
            fight->block = true;
            return;
        }
    }
    stats->player->hp -= (stats->enemy[i]->atk + crit) * def;
    if (stats->player->hp <= 0)
        fight->win = true;
}

int enemy_turn2(sfRenderWindow *window, fight_t *fight)
{
    char *tmp = NULL;

    if (fight->block) {
        display_text(window, "> You blocked his attack !", vector(50, 700), 50);
        return (0);
    }
    tmp = my_strcat("> You lose ",
    my_strcat(my_put_nbr_str(fight->lose), " hp !"));
    display_text(window, tmp, vector(50, 700), 40);
    if (fight->win)
        return (2);
    return (0);
}

int enemy_turn1(sfRenderWindow *window, stats_t *stats, fight_t *fight, int i)
{
    char *tmp = NULL;

    move_squares(window, stats->enemy[i], 1, 1);
    !fight->block ? move_squares(window, stats->player, 0, 0) :
        move_squares(window, stats->player, 6, 6);
    display_text(window, "Press Space...", vector(950, 750), 20);
    tmp = my_strcat("> ", my_strcat(stats->enemy[i]->name, " is attacking !"));
    display_text(window, tmp, vector(50, 550), 50);
    free(tmp);
    tmp = NULL;
    fight->crit ? display_text(window, "> He crits !",
    vector(50, 650), 40) : 0;
    free(tmp);
    return (enemy_turn2(window, fight));
}
