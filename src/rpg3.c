/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"
#include "struct.h"
#include "fight.h"

int **init_mapi(char *file, int size, int map_nb)
{
    char **map = open_tab(file);
    int a = 0;
    int c = 0;
    int **mapi = malloc(sizeof(unsigned int *) * (map_nb + 1));

    for (int i = 0; i <= map_nb; i++)
        mapi[i] = malloc(sizeof(unsigned int *) * (size * size) + 1);
    for (int i = 0; map[i]; i++) {
        if (map[i][0] == 'a') {
            a++;
            c = 0;
        } else
            mapi[a] = fill_map(mapi[a], map[i], c, size);
            c += size;
    }
    return (mapi);
}

sfSprite *print_img(const char *name, sfTexture **texture, sfSprite *sprite)
{
    *texture = sfTexture_createFromFile(name, NULL);
    sprite = sfSprite_create();
    sfTexture_setRepeated(*texture, sfTrue);
    sfSprite_setTexture(sprite, *texture, 0);
    return (sprite);
}

sfIntRect create_rect(int top, int left, int height, int width)
{
    sfIntRect tmp;

    tmp.top = top * 16;
    tmp.left = left * 16;
    tmp.height = (tmp.top / 16 + height) * 16;
    tmp.width = (tmp.left / 16 + width) * 16;
    return tmp;
}

void zone_interact(st_t *st)
{
    st->act_nb = 17;
    st->act = malloc(sizeof(sfIntRect) * st->act_nb);
    st->actb = my_calloc(sizeof(bool), st->act_nb);
    st->fight = my_calloc(sizeof(bool), st->act_nb);
    st->act[0] = create_rect(35, 129, 1, 1);
    st->act[1] = create_rect(80, 153, 1, 1);
    st->act[2] = create_rect(149, 89, 4, 4);
    st->act[3] = create_rect(113, 120, 2, 4);
    st->act[4] = create_rect(136, 29, 2, 4);
    st->act[5] = create_rect(132, 113, 4, 4);
    st->act[6] = create_rect(28, 28, 3, 5);
    st->act[7] = create_rect(61, 15, 3, 3);
    st->act[8] = create_rect(87, 144, 4, 3);
    st->act[9] = create_rect(10, 172, 1, 2);
    st->act[10] = create_rect(51, 62, 2, 2);
    st->act[11] = create_rect(28, 57, 4, 4);
    st->act[12] = create_rect(28, 12, 3, 3);
    st->act[13] = create_rect(36, 36, 3, 3);
    st->act[14] = create_rect(1, 167, 14, 14);
    st->act[15] = create_rect(14, 12, 4, 3);
    st->act[16] = create_rect(112, 42, 4, 4);
}

void init_text(st_t *st)
{
    st->text[0] = create_text_map("Oh! I found some boots.",
    vec(st->x - 20, st->y + 100), 32);
    st->text[1] = create_text_map("Wait! Don't forget to look in the bushes!",
    vec(st->x - 20, st->y + 100), 32);
    st->text[2] = create_text_map("Look carefully at the rocks!",
    vec(st->x - 20, st->y + 100), 32);
    st->text[3] = create_text_map("If you win a fight you'll receive a Gem",
    vec(st->x - 20, st->y + 100), 32);
    st->text[4] = create_text_map("Wow! Where am I? Let's look outside!",
    vec(st->x - 20, st->y + 200), 32);
    st->text[5] = create_text_map(
    "Hey! You have to find 9 Gems to escape the world.",
    vec(st->x - 20, st->y + 100), 32);
    st->text[6] = create_text_map(
    "Hello! Take that Shield for your next fights.",
    vec(st->x - 20, st->y + 100), 32);
}
