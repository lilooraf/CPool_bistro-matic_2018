/*
** EPITECH PROJECT, 2018
** put_nbr_str
** File description:
** evalexpr
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>

char *my_put_nbr_str(int nb)
{
    int tmp = nb;
    int size = 0;
    char *str = NULL;

    if (nb == 0)
        size = 1;
    else
        for (; tmp != 0; size++)
            tmp /= 10;
    str = my_calloc(sizeof(char), size + 1);
    for (int count = 0; count != size; nb /= 10, count++)
        str[count] = nb % 10 + 48;
    return (my_revstr(str));
}