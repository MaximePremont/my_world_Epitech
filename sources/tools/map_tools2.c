/*
** EPITECH PROJECT, 2021
** My World
** File description:
** map_tools
*/

#include <math.h>
#include <stdlib.h>
#include "world.h"

void free_map_2d(sfVector2f **map, int size)
{
    if (map == NULL)
        return;
    for (int i = 0; i < size; i++)
        free(map[i]);
    free(map);
    map = NULL;
}

static sfVector2f project_iso_point(int x, int y, int z, infos_t *infos)
{
    float xy_angle = RADS(infos->editor_sys->xy_angle);
    float z_angle = RADS(infos->editor_sys->z_angle);
    float x_point;
    float y_point;
    sfVector2f vec;
    editor_system_t *edit = infos->editor_sys;

    x = (x - infos->map_data->x / 2) * edit->xy_scale;
    y = (y - infos->map_data->y / 2) * edit->xy_scale;
    z *= edit->z_scale;
    x_point = x * cos(xy_angle) - y * sin(xy_angle);
    y_point = x * sin(xy_angle) * sin(z_angle) + y *
        cos(xy_angle) * sin(z_angle);
    vec = (sfVector2f) {x_point + WINDOW_WIDTH / 2,
        y_point + WINDOW_HEIGHT / 1.8};
    return (vec);
}

sfVector2f **create_2d_map(int **map, infos_t *infos, int size)
{
    sfVector2f **res = malloc(sizeof(sfVector2f*) * size);
    sfVector2f current;
    int cursor;

    for (int i = 0; i < size; i++) {
        res[i] = malloc(sizeof(sfVector2f) * size);
        cursor = 0;
        for (int j = 0; j < size; j++) {
            current = project_iso_point(i, j, map[j][i], infos);
            res[i][cursor].x = current.x;
            res[i][cursor].y = current.y;
            cursor++;
        }
    }
    return (res);
}