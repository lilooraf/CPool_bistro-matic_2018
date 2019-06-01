/*
** EPITECH PROJECT, 2019
** strcpy_end
** File description:
** strcpy_end
*/

#include <stdlib.h>
#include <stdio.h>

char *strcpy_end(char *dest, char *src)
{
    int dest_len;
    int i = 0;

    if (src == NULL)
        return (dest);
    for (dest_len = 0; dest[dest_len] != 0; dest_len++);
    while (src[i] != 0) {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return (dest);
}