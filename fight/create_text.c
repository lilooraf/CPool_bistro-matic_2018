/*
** EPITECH PROJECT, 2019
** create
** File description:
** text
*/

#include "my.h"

sfText *create_text(char *str,  sfVector2f vect, int size)
{
    sfFont *fnt = sfFont_createFromFile("src/font/Pixellari.ttf");
    sfText *text = sfText_create();

    sfText_setFont(text, fnt);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, vect);
    sfText_setColor(text, sfBlack);
    return (text);
}
