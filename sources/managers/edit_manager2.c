/*
** EPITECH PROJECT, 2021
** My World
** File description:
** edit_manager
*/

#include "world.h"

int use_corner_mode(infos_t *infos, int vals[6])
{
    if (is_in_range(infos->correct_map[vals[1]][vals[2]], vals[3], vals[4])) {
        infos->map_data->relief[vals[1]][vals[2]] += vals[5];
        infos->modified = 1;
        return (1);
    }
    return (0);
}

static int calcul_edge(infos_t *infos, int vals[6])
{
    sfVertexArray *arr;
    sfFloatRect rect;
    int i = vals[1];
    int j = vals[2];

    if (j + 1 < vals[0]) {
        arr = create_line(&infos->correct_map[j][i],
        &infos->correct_map[j + 1][i]);
        rect = sfVertexArray_getBounds(arr);
        if (sfFloatRect_contains(&rect, vals[3], vals[4])) {
            infos->map_data->relief[j][i] += vals[5];
            infos->map_data->relief[j + 1][i] += vals[5];
            infos->modified = 1;
            sfVertexArray_destroy(arr);
            return (1);
        }
        sfVertexArray_destroy(arr);
    }
    return (0);
}

int use_edge_mode(infos_t *infos, int vals[6])
{
    sfVertexArray *arr;
    sfFloatRect rect;
    int i = vals[1];
    int j = vals[2];

    if (i + 1 < vals[0]) {
        arr = create_line(&infos->correct_map[j][i],
        &infos->correct_map[j][i + 1]);
        rect = sfVertexArray_getBounds(arr);
        if (sfFloatRect_contains(&rect, vals[3], vals[4])) {
            infos->map_data->relief[j][i] += vals[5];
            infos->map_data->relief[j][i + 1] += vals[5];
            infos->modified = 1;
            sfVertexArray_destroy(arr);
            return (1);
        }
        sfVertexArray_destroy(arr);
    }
    return (calcul_edge(infos, vals));
}

static void calcul_face(sfConvexShape *shape, sfVector2f **cm, int vals[6])
{
    sfVector2f ps[4];
    int i = vals[1];
    int j = vals[2];

    ps[0] = (sfVector2f) {cm[j][i].x, cm[j][i].y};
    ps[1] = (sfVector2f) {cm[j][i + 1].x, cm[j][i + 1].y};
    ps[2] = (sfVector2f) {cm[j + 1][i + 1].x, cm[j + 1][i + 1].y};
    ps[3] = (sfVector2f) {cm[j + 1][i].x, cm[j + 1][i].y};
    sfConvexShape_setPointCount(shape, 4);
    sfConvexShape_setPoint(shape, 0, ps[0]);
    sfConvexShape_setPoint(shape, 1, ps[1]);
    sfConvexShape_setPoint(shape, 2, ps[2]);
    sfConvexShape_setPoint(shape, 3, ps[3]);
}

int use_face_mode(infos_t *infos, int vals[6])
{
    sfConvexShape *shape = sfConvexShape_create();
    sfFloatRect rect;
    sfVector2f **cm = infos->correct_map;
    int j = vals[2];
    material_t mat;

    if (vals[1] + 1 < vals[0] && j + 1 < vals[0]) {
        calcul_face(shape, cm, vals);
        rect = sfConvexShape_getGlobalBounds(shape);
        if (sfFloatRect_contains(&rect, vals[3], vals[4])) {
            mat = infos->map_data->materials[vals[1] * vals[0] + j];
            mat = (mat > STONE_MATERIAL) ? GRASS_MATERIAL : mat;
            mat = (mat == STONE_MATERIAL) ? GRASS_MATERIAL : (mat + 1);
            infos->map_data->materials[vals[1] * vals[0] + j] = mat;
            sfConvexShape_destroy(shape);
            return (1);
        }
    }
    sfConvexShape_destroy(shape);
    return (0);
}