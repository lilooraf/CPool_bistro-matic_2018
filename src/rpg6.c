/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"
#include "struct.h"
#include "fight.h"

bool check_wall(sfVertexArray *m, int x, int y, int size)
{
    sfVertex *tmp = sfVertexArray_getVertex(m,
    ((x / 16) + (y / 16) * size) * 4);

    if ((int)tmp[0].texCoords.x == 0)
        if (tmp[0].texCoords.x == tmp[0].texCoords.y)
            return true;
        else
            return false;
    else
        return false;
}

sfVector2f vec(float x, float y)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return (vec);
}

void pos_vertex(int b, int i, int nb, sfVertex *quad)
{
    if (nb == -1) {
        quad[0].texCoords = vec(0, 0);
        return;
    }
    quad[0].position = vec(b * 16, i * 16);
    quad[1].position = vec((b + 1) * 16, i * 16);
    quad[2].position = vec((b + 1) * 16, (i + 1) * 16);
    quad[3].position = vec(b * 16, (i + 1) * 16);
    quad[0].texCoords = vec((nb % 54) * 16, (nb / 54) * 16);
    quad[1].texCoords = vec(((nb % 54) + 1) * 16, (nb / 54) * 16);
    quad[2].texCoords = vec(((nb % 54) + 1) * 16, ((nb / 54) + 1) * 16);
    quad[3].texCoords = vec((nb % 54) * 16, ((nb / 54) + 1) * 16);
}

void pos_vertex_house(int b, int i, int nb, sfVertex *quad)
{
    if (nb == -1) {
        quad[0].texCoords = vec(0, 0);
        return;
    }
    quad[0].position = vec(b * 16, i * 16);
    quad[1].position = vec((b + 1) * 16, i * 16);
    quad[2].position = vec((b + 1) * 16, (i + 1) * 16);
    quad[3].position = vec(b * 16, (i + 1) * 16);
    quad[0].texCoords = vec((nb % 192) * 16, (nb / 192) * 16);
    quad[1].texCoords = vec(((nb % 192) + 1) * 16, (nb / 192) * 16);
    quad[2].texCoords = vec(((nb % 192) + 1) * 16, ((nb / 192) + 1) * 16);
    quad[3].texCoords = vec((nb % 192) * 16, ((nb / 192) + 1) * 16);
}

sfVertexArray *init_house(int *mapi, int x, int y)
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
    while (i != y) {
        while (b != x) {
            nb = mapi[b + i * x] - 1;
            vertex = sfVertexArray_getVertex(case_map, (b + i * x) * 4);
            pos_vertex_house(b + 180 - 14, i + 1, nb, vertex);
            b++;
        }
        b = 0;
        i++;
    }
    return (case_map);
}
