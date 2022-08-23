/*
** EPITECH PROJECT, 2021
** My World
** File description:
** window_menu
*/

#include "world.h"

static void execute_events(infos_t *infos)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(infos->window, &event)) {
        execute_global_events(event, infos);
        execute_mainme_events(event, infos);
    }
}

static void render_sprite(infos_t *infos, main_menu_system_t *menu,
editor_system_t *edit, char **buff)
{
    sfRenderWindow_drawSprite(infos->window, edit->background, NULL);
    draw_2d_map(infos);
    sfRenderWindow_drawSprite(infos->window, menu->background, NULL);
    sfRenderWindow_drawSprite(infos->window, infos->mainme_sys->title, NULL);
    sfRenderWindow_drawSprite(infos->window, infos->mainme_sys->num_box,
        NULL);
    sfRenderWindow_drawSprite(infos->window, infos->mainme_sys->text_box,
        NULL);
    render_buttons(infos);
    sfRenderWindow_drawText(infos->window, infos->mainme_sys->text, NULL);
    *buff = my_nbr_to_str(infos->select_size);
    sfText_setString(infos->mainme_sys->pos_text, *buff);
    sfRenderWindow_drawText(infos->window, infos->mainme_sys->pos_text, NULL);
}

void use_window_menu(infos_t *infos)
{
    char *buff;

    execute_events(infos);
    if (sfClock_getElapsedTime(infos->mainme_sys->rotate_block).microseconds
    / 1000 > 35) {
        infos->editor_sys->xy_angle -= 1;
        infos->modified = 1;
        sfClock_restart(infos->mainme_sys->rotate_block);
    }
    render_sprite(infos, infos->mainme_sys, infos->editor_sys, &buff);
    free(buff);
}