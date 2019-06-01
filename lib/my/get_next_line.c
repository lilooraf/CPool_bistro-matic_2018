/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line
*/

#include "../../include/get_next_line.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int fct(char *c, int x)
{
    int i;

    if (x == 0) {
        if (c == NULL)
            return (0);
        for (i = 0; c[i]; i++);
        return (i);
    }
    for (i = 0; c[i] != 0; i++) {
        if (c[i] == '\n')
            return (1);
    }
    return (0);
}

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

void *my_calloc(size_t elem_size, size_t elems)
{
    size_t alloc_size = elem_size * elems;
    void *block = malloc(alloc_size);
    unsigned char *ptr = block;

    for (; alloc_size; alloc_size--)
        *ptr++ = (unsigned char)(0);
    return block;
}

char *read_next(int fd, char *dest, int *stop, int j)
{
    int i = 0;
    char *buff = NULL;
    char *tmp = NULL;

    while (i != 1) {
        buff = my_calloc(sizeof(char), READ_SIZE + 1);
        j = read(fd, buff, READ_SIZE);
        if (j > 0) {
            tmp = my_calloc(sizeof(char), (j + fct(dest, 0) + 1));
            dest = strcpy_end(tmp, dest);
            dest = strcpy_end(dest, buff);
        }
        if (!fd && !j)
            return (NULL);
        if (j == 0) {
            *stop = 1;
            return (dest);
        }
        i = fct(buff, 1);
    }
    return (dest);
}

char *get_next_line(int fd)
{
    char static *dest = NULL;
    char *result = NULL;
    int static stop = 0;
    int i;
    int j;

    if (stop != 1)
        dest = read_next(fd, dest, &stop, j);
    if (dest == NULL)
        return (NULL);
    if (dest[0] == 0 && stop == 1)
        return (NULL);
    result = my_calloc(sizeof(char), fct(dest, 0));
    for (i = 0; dest[i] != '\n' && dest[i] != 0; i++)
        result[i] = dest[i];
    dest = dest + (i + 1);
    return (result);
}
