/*
** EPITECH PROJECT, 2021
** My World
** File description:
** global_objects
*/

#include "world.h"

void create_global_objects(infos_t *infos)
{
    global_system_t *gls;
    sfColor color;

    if (infos->global_sys != NULL)
        return;
    gls = malloc(sizeof(global_system_t));
    gls->fader = sfSprite_create();
    sfSprite_setTexture(gls->fader, infos->res->tex->fader, sfTrue);
    color = sfSprite_getColor(gls->fader);
    color.a = 0;
    sfSprite_setColor(gls->fader, color);
    gls->fade_clock = NULL;
    gls->anim_fade = 0;
    infos->global_sys = gls;
}

void delete_global_objects(infos_t *infos)
{
    global_system_t *gls = infos->global_sys;

    if (gls == NULL)
        return;
    sfSprite_destroy(gls->fader);
    if (gls->fade_clock != NULL)
        sfClock_destroy(gls->fade_clock);
    free(gls);
    infos->global_sys = NULL;
}