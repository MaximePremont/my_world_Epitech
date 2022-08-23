/*
** EPITECH PROJECT, 2021
** My World
** File description:
** map_renderer2
*/

#include <math.h>
#include "my.h"
#include "world.h"

static void swap_ifrequired(infos_t *infos, int i, int *cursor)
{
    sfVector2f swap;

    if (infos->ordered_map[i].y < infos->ordered_map[i - 1].y) {
        swap = infos->ordered_map[i - 1];
        infos->ordered_map[i - 1] = infos->ordered_map[i];
        infos->ordered_map[i] = swap;
        *cursor = 0;
    }
}

void regen_ordered_map(infos_t *infos, sfVector2f **map, int size)
{
    int cursor = 0;

    if (infos->ordered_map != NULL)
        free(infos->ordered_map);
    infos->ordered_map = malloc(sizeof(sfVector2f) * size * size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            infos->ordered_map[cursor] = map[j][i];
            cursor++;
        }
    }
    cursor = 0;
    while (!cursor) {
        cursor = 1;
        for (int i = 1; i < (size * size); i++)
            swap_ifrequired(infos, i, &cursor);
    }
}

void regen_correct_map(infos_t *infos, sfVector2f **map, int size)
{
    if (infos->correct_map != NULL) {
        free_map_2d(infos->correct_map, infos->ancient_size);
        infos->correct_map = NULL;
    }
    infos->correct_map = malloc(sizeof(sfVector2f*) * size);
    for (int i = 0; i < size; i++) {
        infos->correct_map[i] = malloc(sizeof(sfVector2f) * size);
        for (int j = 0; j < size; j++) {
            infos->correct_map[i][j].x = map[i][j].x;
            infos->correct_map[i][j].y = map[i][j].y -
            infos->map_data->relief[i][j] * infos->editor_sys->z_scale
            * cos(RADS(infos->editor_sys->z_angle));
        }
    }
}

void regen_2d_map(infos_t *infos)
{
    if (infos->map_2d != NULL)
        free_map_2d(infos->map_2d, infos->ancient_size);
    infos->map_2d = create_2d_map(infos->map_data->relief,
        infos, infos->map_data->x);
}