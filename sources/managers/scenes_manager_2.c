/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myworld-david.gozlan
** File description:
** scenes_manager_2
*/

#include "world.h"

void mode_button(infos_t *infos)
{
    editor_system_t *edit = infos->editor_sys;

    if (infos->mode == MODE_CORNER) {
        infos->mode = MODE_EDGE;
        sfSprite_setTexture(edit->mode, infos->res->tex->mode_edge, sfTrue);
    } else if (infos->mode == MODE_EDGE) {
        infos->mode = MODE_FACE;
        sfSprite_setTexture(edit->mode, infos->res->tex->paint, sfTrue);
    } else {
        infos->mode = MODE_CORNER;
        sfSprite_setTexture(edit->mode, infos->res->tex->mode_corner, sfTrue);
    }
}

void changesize_minus(infos_t *infos)
{
    if (infos->select_size - 6 > 0)
        infos->select_size -= 6;
}

void changesize_add(infos_t *infos)
{
    infos->select_size += 6;
}