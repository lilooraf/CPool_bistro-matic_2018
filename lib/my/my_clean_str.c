/*
** EPITECH PROJECT, 2018
** clean
** File description:
** clean
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

char *cl_str(char *st, char c)
{
    int size = my_strlen(st) + 1;
    int b = 0;
    char *new = malloc(sizeof(char) * size);

    for (int i = 0; i <= size; i++, new[i] = '\0');
    for (int i = 0; st[i] != '\0'; i++)
        if (st[i] == '\t' || st[i] == '\n' || st[i] == c)
            st[i] = ' ';
    for (int i = 0, j = 0; st[i] != '\0'; i++) {
        if (st[i] != ' ') {
            new[j] = st[i];
            j++;
            b = 0;
        } else if (b == 0 && st[i + 1] != '\0' && st[i + 1] != ' ' && j != 0) {
            new[j] = st[i];
            j++;
            b = 1;
        }
    }
    return (new);
}