/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include <string.h>
#include <time.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

char *my_read(int fd, char *buf, char *stock)
{
    while (read(fd, buf, 1000) != 0)
        stock = my_strcat(stock, buf);
    return (stock);
}

char **malloc_tab(char *stock, int *y)
{
    int i = 0;
    int j = 0;
    int s = 0;
    char **tab = NULL;

    for (i = 0; stock[i] != '\0'; i++) {
        if (stock[i] == '\n')
            (*y)++;
    }
    tab = my_calloc(sizeof(char *), (*y + 2));
    for (i = 0; i <= *y; j++, i++) {
        for (s = 0; stock[j] != '\0' && stock[j] != '\n'; s++, j++);
        tab[i] = my_calloc(sizeof(char), (s + 1));
    }
    tab[i] = NULL;
    return (tab);
}

char **char_double(char *stock)
{
    int i = 0;
    int x = 0;
    int y = 0;
    int j = 0;
    char **tab = malloc_tab(stock, &y);

    for (i = 0; i <= y; i++, j++) {
        for (x = 0; stock[j] != '\0' && stock[j] != '\n'; j++, x++)
            tab[i][x] = stock[j];
    }
    return (tab);
}

char **get_next_tab(int fd)
{
    int i = 0;
    char *buf = my_calloc(sizeof(char), (10000 + 1));
    char *stock = my_calloc(sizeof(char), (1 + 1));
    static char **tab;

    if (fd == 0 || fd == -1)
        return (NULL);
    if (fd != 0) {
        stock = my_read(fd, buf, stock);
        tab = char_double(stock);
    }
    return (tab);
}

char **open_tab(char *str)
{
    char **tab = NULL;
    int fd = 0;
    int i = 0;

    fd = open(str, O_RDONLY);
    tab = get_next_tab(fd);
    close(fd);
    return (tab);
}