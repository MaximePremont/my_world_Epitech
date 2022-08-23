/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myworld-david.gozlan
** File description:
** scenes_manager_2
*/

#include "world.h"

void changeto_mainme(infos_t *infos)
{
    start_fade_animation(infos, &endto_mainme);
}

void changeto_editor(infos_t *infos)
{
    start_fade_animation(infos, &endto_editor);
}

void changeto_exit(infos_t *infos)
{
    sfRenderWindow_close(infos->window);
}

void save_button(infos_t *infos)
{
    save_map(*infos->map_data);
}