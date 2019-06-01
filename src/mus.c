/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** csfml
*/

#include "my.h"

sfMusic* music_p(char *str)
{
    sfMusic* music = sfMusic_createFromFile(str);

    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return (music);
}