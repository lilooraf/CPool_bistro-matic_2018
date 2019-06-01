/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"
#include "struct.h"
#include "fight.h"

void manage_sprites(inv_t *inv)
{
    inv->i_t = sfTexture_createFromFile("src/img/inventory/inventory.png",
    NULL);
    inv->sword_t = sfTexture_createFromFile("src/img/inventory/sword.png",
    NULL);
    inv->shield_t = sfTexture_createFromFile("src/img/inventory/shield.png",
    NULL);
    inv->boots_t = sfTexture_createFromFile("src/img/inventory/boots.png",
    NULL);
    inv->i_s = sfSprite_create();
    inv->sword_s = sfSprite_create();
    inv->shield_s = sfSprite_create();
    inv->boots_s = sfSprite_create();
    sfSprite_setTexture(inv->i_s, inv->i_t, sfTrue);
    sfSprite_setTexture(inv->sword_s, inv->sword_t, sfTrue);
    sfSprite_setTexture(inv->shield_s, inv->shield_t, sfTrue);
    sfSprite_setTexture(inv->boots_s, inv->boots_t, sfTrue);
    sfSprite_setScale(inv->i_s, vec(0.4, 0.4));
    sfSprite_setScale(inv->sword_s, vec(0.65, 0.65));
    sfSprite_setScale(inv->shield_s, vec(0.4, 0.4));
    sfSprite_setScale(inv->boots_s, vec(0.65, 0.65));
}

void init_inv(inv_t *inv)
{
    inv->sword = false;
    inv->shield = false;
    inv->boots = false;
    manage_sprites(inv);
}

void draw_inventory(inv_t *inv, st_t *st)
{
    sfSprite_setPosition(inv->i_s, vec(st->x - 23, st->y + 95));
    sfSprite_setPosition(inv->sword_s, vec(st->x - 5, st->y + 100));
    sfSprite_setPosition(inv->shield_s, vec(st->x + 8, st->y + 100));
    sfSprite_setPosition(inv->boots_s, vec(st->x - 17, st->y + 99.5));
    sfRenderWindow_drawSprite(st->wi, inv->i_s, NULL);
    if (inv->sword == true)
        sfRenderWindow_drawSprite(st->wi, inv->sword_s, NULL);
    if (inv->shield == true)
        sfRenderWindow_drawSprite(st->wi, inv->shield_s, NULL);
    if (inv->boots == true)
        sfRenderWindow_drawSprite(st->wi, inv->boots_s, NULL);
}

sfText *create_text_map(char *str, sfVector2f vect, int size)
{
    sfFont *fnt = sfFont_createFromFile("src/font/police.ttf");
    sfText *text = sfText_create();

    sfText_setFont(text, fnt);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, vect);
    sfText_setColor(text, sfBlack);
    sfText_scale(text, vec(0.25, 0.25));
    return (text);
}

char *int_to_str(int nb)
{
    int tmp = nb;
    int size = 0;
    char *str = NULL;

    if (nb == 0)
        size = 1;
    else
        for (; tmp != 0; size++)
            tmp /= 10;
    str = my_calloc(sizeof(char), size + 1);
    for (int count = 0; count != size; nb /= 10, count++)
        str[count] = nb % 10 + 48;
    return (my_revstr(str));
}
