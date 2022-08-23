/*
** EPITECH PROJECT, 2021
** My World
** File description:
** buttons_manager2
*/

#include "world.h"

void delete_buttons(infos_t *infos)
{
    button_t *next = infos->buttons;
    button_t *cur;

    while (next != NULL) {
        cur = next;
        next = next->next;
        free(cur);
    }
    infos->buttons = NULL;
}

static void set_texture(button_t *but, infos_t *infos)
{
    if (infos->state == but->state && but->clock == NULL)
        sfSprite_setTexture(but->button, but->basic_tex, sfTrue);
}

void hover_buttons(infos_t *infos)
{
    button_t *but = infos->buttons;
    sfColor hov_color = {255, 255, 255, 0};

    while (but != NULL) {
        hov_color.a = 0;
        if (infos->state == but->state && is_button_hovered(but, infos)
            && but->clock == NULL) {
            sfSprite_setTexture(but->button, but->hover_tex, sfTrue);
            hov_color.a = 255;
        } else if (infos->state == but->state &&
            is_button_hovered(but, infos)) {
            hov_color.a = 255;
        } else
            set_texture(but, infos);
        sfText_setColor(but->hover_text, hov_color);
        but = but->next;
    }
}

void render_buttons(infos_t *infos)
{
    button_t *but = infos->buttons;

    while (but != NULL) {
        if (but->state == infos->state) {
            sfRenderWindow_drawSprite(infos->window, but->button, NULL);
            sfRenderWindow_drawText(infos->window, but->hover_text, NULL);
            sfRenderWindow_drawText(infos->window, but->text, NULL);
        }
        but = but->next;
    }
}