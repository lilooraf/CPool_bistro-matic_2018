/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** my_strcat
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char const *str);

void *my_calloc(size_t elem_size, size_t elems);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    char *tmp = my_calloc(sizeof(char), my_strlen(dest) + my_strlen(src) + 1);

    for (i = 0; dest[i]; i++)
        tmp[i] = dest[i];
    for (int j = 0; src[j]; i++, j++)
        tmp[i] = src[j];
    return (tmp);
}
