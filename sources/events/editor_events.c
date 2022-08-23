/*
** EPITECH PROJECT, 2021
** My World
** File description:
** editor_events
*/

#include <stdio.h>
#include "my.h"
#include "world.h"

static void process_click(int key, editor_system_t *edit, infos_t *infos)
{
    if (key == 71)
        edit->xy_angle += 1;
    if (key == 55 && edit->xy_scale < 90) {
        edit->xy_scale += 5;
        edit->z_scale += 1;
    }
    if (key == 56 && edit->xy_scale > 10) {
        edit->xy_scale -= 5;
        edit->z_scale -= 1;
    }
    if ((key >= 71 && key <= 75) ||
        (key == 55 || key == 56))
        infos->modified = 1;
}

void execute_editor_events(sfEvent event, infos_t *infos)
{
    editor_system_t *edit = infos->editor_sys;

    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == 74 && edit->z_angle < 50)
            edit->z_angle += 1;
        if (event.key.code == 73 && edit->z_angle > 5)
            edit->z_angle -= 1;
        if (event.key.code == 72)
            edit->xy_angle -= 1;
        process_click(event.key.code, edit, infos);
    }
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.button == sfMouseLeft)
            use_edit_click(infos, infos->mouse.x, infos->mouse.y, 3);
        else if (event.mouseButton.button == sfMouseRight)
            use_edit_click(infos, infos->mouse.x, infos->mouse.y, -3);
    }
}