/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"
#include "struct.h"
#include "fight.h"

sfRenderStates *init_states(char *file)
{
    sfRenderStates *states = malloc(sizeof(sfRenderStates));

    states->blendMode = sfBlendAlpha;
    states->transform = sfTransform_fromMatrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
    states->texture = sfTexture_createFromFile(file, NULL);
    states->shader = NULL;
    return (states);
}

sfVertexArray *init_map(int *mapi, int x, int y)
{
    int i = 0;
    int b = 0;
    int nb = 0;
    sfVertexArray *case_map = NULL;
    sfVertexArray **map = NULL;
    sfVertex *vertex = NULL;

    case_map = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(case_map, sfQuads);
    sfVertexArray_resize(case_map, x * y * 4);
    while (i < y) {
        while (b < x) {
            nb = mapi[b + i * x] - 1;
            vertex = sfVertexArray_getVertex(case_map, (b + i * x) * 4);
            pos_vertex(b, i, nb, vertex);
            b++;
        }
        b = 0;
        i++;
    }
    return (case_map);
}

int *fill_map(int *mapi, char *map, int c, int size)
{
    for (int j = 0, s = 0; s < size - 1; c++, j++, s++) {
        mapi[c] = my_getnbr(&map[j]);
        for (; map[j] != ',' && map[j + 1] != 0; j++);
    }
    return (mapi);
}

void key_event(st_t *st, sfVertexArray *m)
{
    if (st->ev.type == sfEvtKeyPressed && st->ev.key.code == sfKeyUp &&
        check_wall(m, st->x, st->y - st->speed, st->size)) {
        st->y -= st->speed;
        st->move = 3;
    } else if (st->ev.type == sfEvtKeyPressed && st->ev.key.code == sfKeyDown
        && check_wall(m, st->x, st->y + st->speed, st->size)) {
        st->y += st->speed;
        st->move = 0;
    }
    if (st->ev.type == sfEvtKeyPressed && st->ev.key.code == sfKeyLeft &&
        check_wall(m, st->x - st->speed, st->y, st->size)) {
        st->x -= st->speed;
        st->move = 1;
    } else if (st->ev.type == sfEvtKeyPressed && st->ev.key.code == sfKeyRight
        && check_wall(m, st->x + st->speed, st->y, st->size)) {
        st->x += st->speed;
        st->move = 2;
    }
}

void event(st_t *st)
{
    static int b = 0;

    while (sfRenderWindow_pollEvent(st->wi, &st->ev)) {
        st->ev = st->ev;
        if (st->ev.type == sfEvtClosed)
            sfRenderWindow_close(st->wi);
        if (st->ev.type == sfEvtKeyPressed && st->ev.key.code == sfKeyEscape) {
            sfRenderWindow_setView(st->wi, st->view1);
            st->b = display_menu(st->wi);
            sfRenderWindow_setView(st->wi, st->view);
        }
    }
}