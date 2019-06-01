/*
** EPITECH PROJECT, 2019
** check_flags
** File description:
** check_flags
*/

int chek_flag(char c, char *str)
{
    for (int i = 0; str[i] != 0; i++)
        if (str[i] == c)
            return (1);
    return (0);
}