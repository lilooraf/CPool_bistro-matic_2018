/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** putsrt
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    int adresse = 0;

    while (str[adresse] != '\0') {
        my_putchar(str[adresse]);
        adresse++;
    }
}
