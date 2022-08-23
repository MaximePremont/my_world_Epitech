/*
** EPITECH PROJECT, 2021
** My World
** File description:
** main_menu_events
*/

#include <stdio.h>
#include "my.h"
#include "world.h"

static void add_str(char letter, char *str, int *pos)
{
    if (('0' > letter || letter > 'Z') &&
        ('a' > letter || letter > 'z') && letter != 8)
        return;
    if (letter != 8 && *pos < 23) {
        str[*pos] = letter;
        str[*pos + 1] = '\0';
        *pos += 1;
    } else if (*pos != 0 && letter == 8) {
        *pos -= 1;
        str[*pos] = '\0';
    }
}

void execute_mainme_events(sfEvent event, infos_t *infos)
{
    if (event.type == sfEvtTextEntered) {
        add_str(event.text.unicode, infos->mainme_sys->str,
            &infos->mainme_sys->pos);
        sfText_setString(infos->mainme_sys->text, infos->mainme_sys->str);
    }
}