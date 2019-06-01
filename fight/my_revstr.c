/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** retourner une str
*/

#include "my.h"

char *my_revstr(char *str)
{
    int size = my_strlen(str) - 1;
    char *tmp = my_calloc(sizeof(char), size + 2);

    for (int count = 0; size + 1 != 0; size--, count++)
        tmp[count] = str[size];
    return (tmp);
}
