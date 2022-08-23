/*
** EPITECH PROJECT, 2021
** My World
** File description:
** edit_manager
*/

#include "world.h"

static int parse_mode(infos_t *infos, int vals[6])
{
    if (infos->mode == MODE_CORNER) {
        return (use_corner_mode(infos, vals));
    } else if (infos->mode == MODE_EDGE) {
        return (use_edge_mode(infos, vals));
    } else {
        return (use_face_mode(infos, vals));
    }
    return (0);
}

static int manage_point(infos_t *infos, int vals[6], int *cursor)
{
    if (infos->map_2d[vals[1]][vals[2]].y == infos->ordered_map[*cursor].y) {
        if (parse_mode(infos, vals))
            return (1);
        *cursor -= 1;
    }
    return (0);
}

static int parcour_map_y(infos_t *infos, int vals[6], int *cursor)
{
    for (int j = 0; j < vals[0]; j++) {
        vals[2] = j;
        if (manage_point(infos, vals, cursor))
            return (1);
    }
    return (0);
}

static int parcour_map_x(infos_t *infos, int vals[6], int *cursor)
{
    for (int i = 0; i < vals[0]; i++) {
        vals[1] = i;
        if (parcour_map_y(infos, vals, cursor))
            return (1);
    }
    return (0);
}

void use_edit_click(infos_t *infos, int x, int y, int add)
{
    int vals[6];
    int cursor;

    vals[0] = infos->map_data->x;
    cursor = vals[0] * vals[0] - 1;
    vals[3] = x;
    vals[4] = y;
    vals[5] = add;
    while (cursor >= 0) {
        if (parcour_map_x(infos, vals, &cursor))
            return;
    }
}