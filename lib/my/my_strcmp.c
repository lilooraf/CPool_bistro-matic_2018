/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_strcmp
*/

#include <stddef.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    if (s1 == NULL || s2 == NULL)
        return (0);
    while (s1[i] != '\0')
        i++;
    while (s2[j] != '\0')
        j++;
    return (i - j);
}
