/*
** EPITECH PROJECT, 2019
** init_struct
** File description:
** init_struct
*/

#include "my.h"
#include "struct.h"

void init_var(var_t *var)
{
    var->i = -1;
    var->b = true;
    var->bg = create_sprite("fight/img/background/fightbg.png");
    sfSprite_scale(var->bg, vector(1.5, 1.6666667));
}

void init_fight(fight_t *fight)
{
    fight->hp = 0;
    fight->crit = 0;
    fight->lose = 0;
    fight->block = 0;
    fight->win = 0;
}

void init_stat(stats_t *stats, var_t *var, fight_t *fight, st_t st)
{
    entity_t *player = my_calloc(sizeof(entity_t), 1);
    entity_t **enemy = my_calloc(sizeof(entity_t *), 4);

    init_player_struct(player, st.inv.sword, st.inv.shield);
    init_enemy_struct(enemy);
    init_fight(fight);
    init_var(var);
    stats->player = player;
    stats->enemy = enemy;
    stats->var = var;
    stats->fight = fight;
}
