/*
** EPITECH PROJECT, 2019
** my_clear_str
** File description:
** my_clear_str
*/

#include <stddef.h>
#include <stdlib.h>

char *my_strdup(char const *src);
void *my_calloc(size_t elem_size, size_t elems);
int my_strlen(char const *str);

char *my_clear_str(char *str)
{
    int i = 0;
    int j = 0;
    char *tmp = my_calloc(sizeof(char), my_strlen(str));
    char *dest = my_strdup(str);

    for (i = 0; dest[i] != 0; i++)
        if (dest[i] == '\r' || dest[i] == '\n' || dest[i] == '\t')
            dest[i] = ' ';
    for (i = 0; dest[i] == ' ' && dest[i] != 0; i++);
    for (; dest[i] != 0; i++)
        if (dest[i] == ' ');
        else {
            tmp[j] = dest[i];
            j++;
        }
    if (tmp[j - 1] == ' ')
        tmp[j - 1] = '\0';
    free (dest);
    dest = my_strdup(tmp);
    free(tmp);
    return (dest);
}
