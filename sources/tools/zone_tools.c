/*
** EPITECH PROJECT, 2021
** My World
** File description:
** zone_tools
*/

#include "world.h"

static int is_in_zone(int x, int y, sfFloatRect rect)
{
    if (x >= rect.left && x <= rect.left + rect.width) {
        if (y <= rect.top + rect.height && y >= rect.top)
            return (1);
    }
    return (0);
}

int is_button_hovered(button_t *but, infos_t *infos)
{
    return (is_in_zone(infos->mouse.x,
        infos->mouse.y, sfSprite_getGlobalBounds(but->button)));
}

int is_in_range(sfVector2f point, int x, int y)
{
    if ((x - 5) <= point.x && (x + 5) >= point.x &&
        (y - 5) <= point.y && (y + 5) >= point.y)
        return (1);
    return (0);
}