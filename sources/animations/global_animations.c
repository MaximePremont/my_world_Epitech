/*
** EPITECH PROJECT, 2021
** My World
** File description:
** global_animations
*/

#include "world.h"

void start_fade_animation(infos_t *infos, void (*fade_func)(infos_t*))
{
    global_system_t *gls = infos->global_sys;

    if (gls == NULL || gls->fade_clock != NULL)
        return;
    gls->fade_clock = sfClock_create();
    gls->fade_func = fade_func;
}

static void execute_fade_anim(infos_t *infos)
{
    global_system_t *gls = infos->global_sys;
    sfColor color;

    if (sfClock_getElapsedTime(gls->fade_clock).microseconds > 1000) {
        color = sfSprite_getColor(gls->fader);
        if (gls->anim_fade == 0 && color.a >= 243) {
            gls->anim_fade = 1;
            gls->fade_func(infos);
        } else if (gls->anim_fade == 0)
            color.a += 12;
        if (gls->anim_fade == 1 && color.a <= 12) {
            gls->anim_fade = 0;
            sfClock_destroy(gls->fade_clock);
            gls->fade_clock = NULL;
        } else if (gls->anim_fade == 1)
            color.a -= 12;
        sfSprite_setColor(gls->fader, color);
        if (gls->fade_clock != NULL)
            sfClock_restart(gls->fade_clock);
    }
    sfRenderWindow_drawSprite(infos->window, gls->fader, NULL);
}

void execute_global_animations(infos_t *infos)
{
    if (infos->global_sys != NULL && infos->global_sys->fade_clock != NULL)
        execute_fade_anim(infos);
    hover_buttons(infos);
    execute_buttons(infos);
}