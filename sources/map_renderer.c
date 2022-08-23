/*
** EPITECH PROJECT, 2021
** My World
** File description:
** map_render
*/

#include <math.h>
#include "my.h"
#include "world.h"

static void parcour_map_y(infos_t *infos, int vals[3],
int *sc, sfVector2f **map)
{
    for (int j = 0; j < vals[0]; j++) {
        if (map[j][vals[1]].y == infos->ordered_map[*sc].y) {
            vals[2] = j;
            execute_draw(infos, infos->correct_map, vals[0], vals);
            *sc += 1;
        }
    }
}

static void parcour_map_x(infos_t *infos, int vals[3],
int *sc, sfVector2f **map)
{
    for (int i = 0; i < vals[0]; i++) {
        vals[1] = i;
        parcour_map_y(infos, vals, sc, map);
    }
}

void draw_2d_map(infos_t *infos)
{
    int vals[3];
    int show_cursor = 0;
    vals[0] = infos->map_data->x;
    sfVector2f **map = infos->map_2d;

    if (infos->modified) {
        infos->modified = 0;
        regen_2d_map(infos);
        map = infos->map_2d;
        regen_ordered_map(infos, map, vals[0]);
        regen_correct_map(infos, map, vals[0]);
        if (infos->ancient_size != infos->size)
            infos->ancient_size = infos->size;
    }
    while (show_cursor < (vals[0] * vals[0]))
        parcour_map_x(infos, vals, &show_cursor, map);
}