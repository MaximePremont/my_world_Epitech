/*
** EPITECH PROJECT, 2021
** My World
** File description:
** editor_objects
*/

#include <stdlib.h>
#include "world.h"

static void create_buttons(editor_system_t *edit, textures_t *texs)
{
    sfVector2f mode_pos = {CHANGE_MODE_EDITOR_BUTTON.x,
        CHANGE_MODE_EDITOR_BUTTON.y};
    sfVector2f save_pos = {SAVE_BUTTON.x, SAVE_BUTTON.y};
    sfVector2f close_pos = {EXIT_EDITOR_BUTTON.x, EXIT_EDITOR_BUTTON.y};

    edit->mode = sfSprite_create();
    sfSprite_setTexture(edit->mode, texs->mode_corner, sfTrue);
    sfSprite_setPosition(edit->mode, mode_pos);
    edit->save = sfSprite_create();
    sfSprite_setTexture(edit->save, texs->save, sfTrue);
    sfSprite_setPosition(edit->save, save_pos);
    edit->close = sfSprite_create();
    sfSprite_setTexture(edit->close, texs->close, sfTrue);
    sfSprite_setPosition(edit->close, close_pos);
}

void create_editor_objects(infos_t *infos)
{
    editor_system_t *edit;
    textures_t *texs = infos->res->tex;

    if (infos->editor_sys != NULL)
        return;
    edit = malloc(sizeof(editor_system_t));
    edit->xy_angle = 40;
    edit->z_angle = 30;
    edit->xy_scale = 40;
    edit->z_scale = 10;
    edit->background = sfSprite_create();
    sfSprite_setTexture(edit->background, infos->res->tex->sky, sfTrue);
    infos->editor_sys = edit;
    create_button(infos, EXIT_EDITOR_BUTTON, infos->res->buttons[1]);
    create_button(infos, SAVE_BUTTON, infos->res->buttons[1]);
    create_button(infos, CHANGE_MODE_EDITOR_BUTTON, infos->res->buttons[1]);
    create_buttons(edit, texs);
}

void delete_editor_objects(infos_t *infos)
{
    editor_system_t *edit = infos->editor_sys;

    if (edit == NULL)
        return;
    sfSprite_destroy(edit->mode);
    sfSprite_destroy(edit->background);
    sfSprite_destroy(edit->save);
    sfSprite_destroy(edit->close);
    free(edit);
    infos->editor_sys = NULL;
}