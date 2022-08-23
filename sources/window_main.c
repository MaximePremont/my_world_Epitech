/*
** EPITECH PROJECT, 2021
** My World
** File description:
** window_main
*/

#include "world.h"
#include <SFML/Window.h>

static void create_window(infos_t *infos)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BPP};

    infos->window = sfRenderWindow_create(
        mode, "My World", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(infos->window, 60);
    create_global_objects(infos);
    create_mainme_objects(infos);
    create_editor_objects(infos);
}

static void manage_game(infos_t *infos)
{
    switch (infos->state) {
    case (STATE_MENU):
        return (use_window_menu(infos));
    case (STATE_EDITOR):
        return (use_editor(infos));
    }
}

void start_system(infos_t *infos)
{
    create_window(infos);
    sfSound_play(infos->res->sounds->music);
    while (sfRenderWindow_isOpen(infos->window)) {
        sfRenderWindow_clear(infos->window, sfBlack);
        manage_game(infos);
        execute_global_animations(infos);
        sfRenderWindow_display(infos->window);
    }
    sfSound_stop(infos->res->sounds->music);
    delete_global_objects(infos);
    delete_editor_objects(infos);
    delete_mainme_objects(infos);
    sfRenderWindow_destroy(infos->window);
}