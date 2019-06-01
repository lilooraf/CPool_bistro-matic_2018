/*
** EPITECH PROJECT, 2019
** fight
** File description:
** scene
*/

#include "my.h"

void display_stats(sfRenderWindow *window, stats_t *stats, int i)
{
    sfRenderWindow_drawSprite(window, stats->var->bg, NULL);
    display_text(window, stats->player->name, vector(50, 50), 50);
    display_text(window, stats->enemy[i]->name, vector(760, 50), 50);
    display_text(window, my_put_nbr_str(stats->player->hp),
    vector(50, 100), 40);
    display_text(window, my_put_nbr_str(stats->enemy[i]->hp),
    vector(760, 100), 40);
    display_text(window, my_put_nbr_str(stats->player->atk),
    vector(50, 150), 40);
    display_text(window, my_put_nbr_str(stats->enemy[i]->atk),
    vector(760, 150), 40);
}

void normal_char(sfRenderWindow *window, stats_t *stats, int i)
{
    move_squares(window, stats->player, 0, 0);
    move_squares(window, stats->enemy[i], 0, 0);
    display_text(window, "Press Space...", vector(950, 750), 20);
}

bool fight_scene(sfRenderWindow *window, stats_t *stats, int i)
{
    while (42) {
        sfRenderWindow_clear(window, sfBlack);
        event_window(window, stats->var);
        display_stats(window, stats, i);
        if (stats->var->i == -1) {
            !(stats->player->speed > stats->enemy[i]->speed) ?
            stats->var->i = 1 : 0;
            normal_char(window, stats, i);
            sfRenderWindow_display(window);
            continue;
        }
        if (stats->var->i % 2 == 0) {
            !stats->var->b ? stats->var->b = true,
            player_fight(stats, stats->fight, i) : 0;
            if (player_turn(window, stats, stats->fight, i) == 1)
                return true;
        } else {
            !stats->var->b ? stats->var->b = true,
            enemy_fight(stats, stats->fight, i) : 0;
            if (enemy_turn1(window, stats, stats->fight, i) == 2)
                return false;
        }
        sfRenderWindow_display(window);
    }
}

void destroy_window(sfRenderWindow *window, stats_t *stats, int i)
{
    sfSprite_destroy(stats->var->bg);
    sfSprite_destroy(stats->player->sprite);
    sfSprite_destroy(stats->enemy[i]->sprite);
    sfRenderWindow_destroy(window);
}
