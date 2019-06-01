/*
** EPITECH PROJECT, 2019
** get_flags
** File description:
** get_flags
*/

#include <stddef.h>

void *my_calloc(size_t elem_size, size_t elems);
char *strcpy_end(char *dest, char *src);
int my_strlen(char const *str);

char *get_flags(char **av)
{
    int i = 1;
    char *flags = NULL;
    char *tmp = NULL;

    if (av == NULL)
        return (flags);
    while (av[i] != NULL) {
        if (av[i][0] == '-') {
            av[i] = av[i] + 1;
            tmp = my_calloc(sizeof(char), (my_strlen(av[i]) + 1));
            flags = strcpy_end(tmp, flags);
            flags = strcpy_end(flags, av[i]);
        }
        i++;
    }
    return (flags);
}