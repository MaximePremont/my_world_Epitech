/*
** EPITECH PROJECT, 2021
** My World
** File description:
** map_tools
*/

#include <math.h>
#include "my.h"
#include "world.h"

void free_map_data(map_data_t *data)
{
    free(data->materials);
    for (int i = 0; i < data->x; i++)
        free(data->relief[i]);
    free(data->relief);
}

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfWhite};
    sfVertex vertex2 = {.position = *point2, .color = sfWhite};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

static void draw_lines(sfRenderWindow *window, sfVector2f **map,
int size, int *vals)
{
    sfVertexArray *arr1;
    sfVertexArray *arr2;
    int i = vals[1];
    int j = vals[2];

    if (i + 1 < size) {
        arr1 = create_line(&map[j][i], &map[j][i + 1]);
        sfRenderWindow_drawVertexArray(window, arr1, NULL);
        sfVertexArray_destroy(arr1);
    }
    if (j + 1 < size) {
        arr2 = create_line(&map[j][i], &map[j + 1][i]);
        sfRenderWindow_drawVertexArray(window, arr2, NULL);
        sfVertexArray_destroy(arr2);
    }
}

static void calcul_convex_shape(sfConvexShape *shape, sfVector2f ps[4],
sfVector2f **map, int *vals)
{
    int i = vals[1];
    int j = vals[2];

    ps[0] = (sfVector2f) {map[j][i].x, map[j][i].y};
    ps[1] = (sfVector2f) {map[j][i + 1].x, map[j][i + 1].y};
    ps[2] = (sfVector2f) {map[j + 1][i + 1].x, map[j + 1][i + 1].y};
    ps[3] = (sfVector2f) {map[j + 1][i].x, map[j + 1][i].y};
    sfConvexShape_setPointCount(shape, 4);
    sfConvexShape_setPoint(shape, 0, ps[0]);
    sfConvexShape_setPoint(shape, 1, ps[1]);
    sfConvexShape_setPoint(shape, 2, ps[2]);
    sfConvexShape_setPoint(shape, 3, ps[3]);
}

void execute_draw(infos_t *infos, sfVector2f **map, int size, int *vals)
{
    int i = vals[1];
    int j = vals[2];
    sfVector2f ps[4];
    sfConvexShape *shape = sfConvexShape_create();
    sfTexture *tex = infos->res->tex->grass;
    material_t mat;

    if (i + 1 < size && j + 1 < size) {
        mat = infos->map_data->materials[i * size + j];
        tex = (mat == SAND_MATERIAL) ? infos->res->tex->sand :
            ((mat == STONE_MATERIAL) ? infos->res->tex->stone : tex);
        calcul_convex_shape(shape, ps, map, vals);
        sfConvexShape_setTexture(shape, tex, sfFalse);
        sfRenderWindow_drawConvexShape(infos->window, shape, NULL);
    }
    draw_lines(infos->window, map, size, vals);
    sfConvexShape_destroy(shape);
}