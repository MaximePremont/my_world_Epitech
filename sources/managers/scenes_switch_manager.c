/*
** EPITECH PROJECT, 2021
** My World
** File description:
** scenes_manager
*/

#include "world.h"

void endto_mainme(infos_t *infos)
{
    infos->state = STATE_MENU;
    infos->editor_sys->xy_angle = 40;
    infos->editor_sys->z_angle = 30;
    infos->editor_sys->xy_scale = 40;
    infos->editor_sys->z_scale = 10;
    infos->modified = 1;
}

void endto_editor(infos_t *infos)
{
    infos->state = -1;
    free_map_data(infos->map_data);
    infos->ordered_map = NULL;
    infos->correct_map = NULL;
    infos->ordered_map = NULL;
    infos->size = infos->select_size;
    if (*infos->mainme_sys->str)
        my_strcpy(infos->map_data->save_name, infos->mainme_sys->str);
    infos->map_data = gen_default_map(infos->size,
        BASIC_BIOME, infos->map_data->save_name);
    infos->modified = 1;
    infos->state = STATE_EDITOR;
    infos->editor_sys->xy_angle = 40;
    infos->modified = 1;
}