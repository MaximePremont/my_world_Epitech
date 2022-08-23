/*
** EPITECH PROJECT, 2021
** My World
** File description:
** main_menu_objects
*/

#include <stdio.h>
#include <stdlib.h>
#include "world.h"

static void create_mainme_texts(main_menu_system_t *mainme, infos_t *infos)
{
    mainme->text = sfText_create();
    mainme->pos_text = sfText_create();
    sfText_setPosition(mainme->text, (sfVector2f) {470, 350});
    sfText_setFont(mainme->text, infos->res->fonts->basic);
    sfText_setPosition(mainme->pos_text, (sfVector2f) {600, 433});
    sfText_setFont(mainme->pos_text, infos->res->fonts->basic);
    mainme->num_box = sfSprite_create();
    mainme->text_box = sfSprite_create();
    mainme->title = sfSprite_create();
    sfSprite_setTexture(mainme->num_box,
    infos->res->tex->num_box, sfTrue);
    sfSprite_setTexture(mainme->text_box,
    infos->res->tex->text_box, sfTrue);
    sfSprite_setTexture(mainme->title,
    infos->res->tex->title, sfTrue);
    sfSprite_setPosition(mainme->num_box, (sfVector2f) {574, 425});
    sfSprite_setPosition(mainme->text_box, (sfVector2f) {460, 340});
    sfSprite_setPosition(mainme->title, (sfVector2f) {370, 25});
}

void create_mainme_objects(infos_t *infos)
{
    main_menu_system_t *mainme;
    textures_t *texs = infos->res->tex;

    if (infos->mainme_sys != NULL)
        return;
    mainme = malloc(sizeof(main_menu_system_t));
    create_button(infos, CREATE_BUTTON, infos->res->buttons[0]);
    create_button(infos, EXIT_BUTTON, infos->res->buttons[0]);
    mainme->background = sfSprite_create();
    sfSprite_setTexture(mainme->background, texs->blow, sfTrue);
    mainme->rotate_block = sfClock_create();
    create_button(infos, MSIZE_BUTTON, infos->res->buttons[1]);
    create_button(infos, ASIZE_BUTTON, infos->res->buttons[1]);
    infos->mainme_sys = mainme;
    infos->mainme_sys->str[0] = '\0';
    infos->mainme_sys->pos = 0;
    create_mainme_texts(mainme, infos);
}

void delete_mainme_objects(infos_t *infos)
{
    main_menu_system_t *mainme = infos->mainme_sys;

    if (mainme == NULL)
        return;
    sfSprite_destroy(mainme->background);
    sfSprite_destroy(mainme->num_box);
    sfSprite_destroy(mainme->text_box);
    sfText_destroy(mainme->text);
    sfText_destroy(mainme->pos_text);
    sfSprite_destroy(mainme->title);
    free(mainme);
    infos->mainme_sys = NULL;
}