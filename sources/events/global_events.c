/*
** EPITECH PROJECT, 2021
** My World
** File description:
** global_events
*/

#include "world.h"

void execute_global_events(sfEvent event, infos_t *infos)
{
    sfVector2i pos;

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(infos->window);
    if (event.type == sfEvtMouseMoved) {
        pos.x = event.mouseMove.x;
        pos.y = event.mouseMove.y;
        infos->mouse = sfRenderWindow_mapPixelToCoords(
            infos->window, pos, sfRenderWindow_getDefaultView(infos->window));
    }
    if (event.type == sfEvtMouseButtonPressed)
        click_buttons(infos);
}