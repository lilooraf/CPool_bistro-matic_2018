/*
** EPITECH PROJECT, 2019
** my_exec
** File description:
** shel
*/

#include <stddef.h>
#include <stdlib.h>

char **malloc_tab(char *stock, int *y)
{
    int i;
    int j = 0;
    int s;
    char **tab = NULL;

    for (i = 0; stock[i] != '\0'; i++)
        (stock[i] == ' ') ? (*y)++ : *y;
    tab = malloc(sizeof(char *) * (*y + 1));
    for (i = 0; i <= *y; j++, i++) {
        for (s = 0; stock[j] != '\0' && stock[j] != ' '; s++, j++);
        tab[i] = malloc(sizeof(char) * (s + 1));
    }
    tab[i] = NULL;
    return (tab);
}

char **char_d(char *stock)
{
    int i = 0;
    int x = 0;
    int y = 0;
    int j = 0;
    char **tab = malloc_tab(stock, &y);

    for (i = 0; i <= y; i++, j++)
        for (x = 0; stock[j] != '\0' && stock[j] != ' '; j++, x++)
            tab[i][x] = stock[j];
    return (tab);
}