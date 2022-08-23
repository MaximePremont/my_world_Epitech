/*
** EPITECH PROJECT, 2021
** My World
** File description:
** editor_window
*/

#include "world.h"

static void execute_events(infos_t *infos)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(infos->window, &event)) {
        execute_global_events(event, infos);
        execute_editor_events(event, infos);
    }
}

void use_editor(infos_t *infos)
{
    editor_system_t *edit = infos->editor_sys;

    execute_events(infos);
    sfRenderWindow_drawSprite(infos->window, edit->background, NULL);
    draw_2d_map(infos);
    render_buttons(infos);
    sfRenderWindow_drawSprite(infos->window, edit->mode, NULL);
    sfRenderWindow_drawSprite(infos->window, edit->save, NULL);
    sfRenderWindow_drawSprite(infos->window, edit->close, NULL);
}