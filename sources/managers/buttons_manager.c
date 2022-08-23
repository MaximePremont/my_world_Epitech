/*
** EPITECH PROJECT, 2021
** My World
** File description:
** buttons_manager
*/

#include "world.h"

static void define_button_texs(button_t *new, butt_textures_t textures)
{
    new->basic_tex = textures.basic_tex;
    new->hover_tex = textures.hover_tex;
    new->click_tex = textures.click_tex;
    new->clock = NULL;
}

static void create_button_text(infos_t *infos, butt_data_t data,
button_t *new, sfVector2f pos)
{
    new->text = create_text(infos->res->fonts->alphakind,
    sfWhite, 40, data.text);
    pos.x += sfSprite_getGlobalBounds(new->button).width / 2
        - sfText_getGlobalBounds(new->text).width / 2;
    sfText_setPosition(new->text, pos);
}

void create_button(infos_t *infos, butt_data_t data, butt_textures_t textures)
{
    button_t *new = malloc(sizeof(button_t));
    sfColor white = {255, 255, 255, 0};
    sfVector2f pos = {data.x, data.y};

    define_button_texs(new, textures);
    new->button = sfSprite_create();
    sfSprite_setTexture(new->button, new->basic_tex, sfTrue);
    new->hover_text = create_text(
        infos->res->fonts->basic, white, 20, data.hover_text);
    sfSprite_setPosition(new->button, pos);
    create_button_text(infos, data, new, pos);
    pos.y += sfSprite_getGlobalBounds(new->button).height;
    pos.x += sfSprite_getGlobalBounds(new->button).width / 2
        - sfText_getGlobalBounds(new->hover_text).width / 2;
    sfText_setPosition(new->hover_text, pos);
    new->state = data.state;
    new->enabled = data.enabled;
    new->call_func = data.call_func;
    new->next = infos->buttons;
    infos->buttons = new;
}

void click_buttons(infos_t *infos)
{
    button_t *but = infos->buttons;

    while (but != NULL) {
        if (sfText_getColor(but->hover_text).a == 255 && but->clock == NULL) {
            sfSound_play(infos->res->sounds->click);
            but->clock = sfClock_create();
            sfSprite_setTexture(but->button, but->click_tex, sfFalse);
            return;
        }
        but = but->next;
    }
}

void execute_buttons(infos_t *infos)
{
    button_t *but = infos->buttons;

    while (but != NULL) {
        if (but->clock != NULL &&
            (sfClock_getElapsedTime(but->clock).microseconds / 1000) > 200) {
            but->call_func(infos);
            sfClock_destroy(but->clock);
            but->clock = NULL;
        }
        but = but->next;
    }
}