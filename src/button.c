/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** button
*/

#include "my.h"
#include "info_struct.h"

void select_state(bt_t *bt, sfRenderWindow *wi, sfVector2i *pm, sfVector2i *pm2)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.height = bt->size_x;
    rect.width = bt->size_y;
    if (bt->status == 1) {
        sfSprite_setTextureRect(bt->sp_bt2, rect);
        sfSprite_setPosition(bt->sp_bt2, vec(bt->x, bt->y));
        sfRenderWindow_drawSprite(wi, bt->sp_bt2, NULL);
    } else if (((pm2->x >= bt->x && pm2->x <= bt->x + bt->size_y) &&
            (pm2->y >= bt->y && pm2->y <= bt->y + bt->size_x))) {
        sfSprite_setTextureRect(bt->sp_bt1, rect);
        sfSprite_setPosition(bt->sp_bt1, vec(bt->x, bt->y));
        sfRenderWindow_drawSprite(wi, bt->sp_bt1, NULL);
    } else {
        sfSprite_setTextureRect(bt->sp_bt, rect);
        sfSprite_setPosition(bt->sp_bt, vec(bt->x, bt->y));
        sfRenderWindow_drawSprite(wi, bt->sp_bt, NULL);
    }
}

void set_bt(bt_t *bt, sfRenderWindow *wi, sfVector2i *pm, sfVector2i *pm2)
{
    if ((pm->x >= bt->x && pm->x <= bt->x + bt->size_y) &&
        (pm->y >= bt->y && pm->y <= bt->y + bt->size_x))
        bt->status = 1;
    else
        bt->status = 0;
    select_state(bt, wi, pm, pm2);
}

bt_t *init_struct_menu(void)
{
    char *img = NULL;
    bt_t *bt = malloc(sizeof(bt_t) * 2);

    for (int i = 0; i <= 1; i++)  {
        img = my_strcat("src/img/idle/", IDLE[i]);
        bt[i].sp_bt = print_img(img, &bt[i].tex_bt, bt[i].sp_bt);
        free(img);
        img = my_strcat("src/img/hover/", HOVER[i]);
        bt[i].sp_bt1 = print_img(img, &bt[i].tex_bt1, bt[i].sp_bt1);
        free(img);
        img = my_strcat("src/img/clicked/", CLICKED[i]);
        bt[i].sp_bt2 = print_img(img, &bt[i].tex_bt2, bt[i].sp_bt2);
        free(img);
        bt[i].x = COORD[i].x;
        bt[i].y = COORD[i].y;
        bt[i].size_y = 610;
        bt[i].size_x = 110;
        bt[i].status = 0;
    }
    return (bt);
}