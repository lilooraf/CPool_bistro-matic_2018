/*
** EPITECH PROJECT, 2019
** get_args
** File description:
** get_args
*/

#include <stddef.h>

void *my_calloc(size_t elem_size, size_t elems);
int my_strlen(char const *str);

char **get_args(char **av)
{
    int j = 0;
    char **file_dir = NULL;
    char **file_dir_null = my_calloc(sizeof(char *), 1);

    file_dir_null[0] = my_calloc(sizeof(char), 3);
    file_dir_null[0][0] = '.';
    file_dir_null[0][1] = '/';
    if (av[1] == NULL)
        return (file_dir_null);
    file_dir = my_calloc(sizeof(av), 1);
    for (int i = 1; av[i]; i++) {
        if (av[i][0] != '-') {
            file_dir[j] = my_calloc(sizeof(char), (my_strlen(av[i]) + 3));
            file_dir[j] = av[i];
            j++;
        }
    }
    file_dir[j] = NULL;
    if (file_dir[0] == NULL)
        return (file_dir_null);
    return (file_dir);
}