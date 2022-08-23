/*
** EPITECH PROJECT, 2021
** My World
** File description:
** loader
*/

#include <stdlib.h>
#include "world.h"

static void gen_textures(textures_t *tex)
{
    int size = WINDOW_WIDTH * WINDOW_HEIGHT * WINDOW_BPP / 8 - 1;
    sfUint8 *pixels = malloc(size + 1);
    sfUint8 *pi_sky = malloc(size + 1);
    sfUint8 *pi_blo = malloc(size + 1);

    gen_pixels(pixels, pi_sky, pi_blo, size);
    tex->fader = sfTexture_create(WINDOW_WIDTH, WINDOW_HEIGHT);
    sfTexture_updateFromPixels(
        tex->fader, pixels, WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
    tex->sky = sfTexture_create(WINDOW_WIDTH, WINDOW_HEIGHT);
    sfTexture_updateFromPixels(
        tex->sky, pi_sky, WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
    tex->blow = sfTexture_create(WINDOW_WIDTH, WINDOW_HEIGHT);
    sfTexture_updateFromPixels(
        tex->blow, pi_blo, WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
    free(pixels);
    free(pi_sky);
    free(pi_blo);
}

static void load_text_buttons(ressources_t *res)
{
    textures_t *tex = res->tex;

    res->buttons = malloc(sizeof(butt_textures_t) * NB_TEXT_BUTTONS);
    res->buttons[0] = (butt_textures_t) {res->tex->but_main_basic,
        res->tex->but_main_hov, res->tex->but_main_click};
    res->buttons[1] = (butt_textures_t) {res->tex->but_sq_basic,
        res->tex->but_sq_hov, res->tex->but_sq_click};
    tex->close = sfTexture_createFromFile(ICONS_PATH, &CLOSE_RECT);
    tex->paint = sfTexture_createFromFile(ICONS_PATH, &PAINT_RECT);
    tex->num_box = sfTexture_createFromFile(NUM_BOX_PATH, NULL);
    tex->text_box = sfTexture_createFromFile(TEXT_BOX_PATH, NULL);
    tex->sand = sfTexture_createFromFile(SAND_PATH, NULL);
    tex->stone = sfTexture_createFromFile(STONE_PATH, NULL);
    tex->title = sfTexture_createFromFile(TITLE_PATH, NULL);
}

static void load_textures(ressources_t *res)
{
    textures_t *tex = malloc(sizeof(textures_t));

    gen_textures(tex);
    tex->but_main_basic = sfTexture_createFromFile(
        MAIN_BUTTONS_PATH, &MAIN_BASIC_RECT);
    tex->but_main_hov = sfTexture_createFromFile(
        MAIN_BUTTONS_PATH, &MAIN_HOV_RECT);
    tex->but_main_click = sfTexture_createFromFile(
        MAIN_BUTTONS_PATH, &MAIN_CLICK_RECT);
    tex->grass = sfTexture_createFromFile(GRASS_PATH, NULL);
    tex->but_sq_basic = sfTexture_createFromFile(
        SQ_BUTTONS_PATH, &SQ_BASIC_RECT);
    tex->but_sq_hov = sfTexture_createFromFile(SQ_BUTTONS_PATH, &SQ_HOV_RECT);
    tex->but_sq_click = sfTexture_createFromFile(
        SQ_BUTTONS_PATH, &SQ_CLICK_RECT);
    tex->mode_corner = sfTexture_createFromFile(ICONS_PATH, &CORNER_RECT);
    tex->mode_edge = sfTexture_createFromFile(ICONS_PATH, &EDGE_RECT);
    tex->save = sfTexture_createFromFile(ICONS_PATH, &SAVE_RECT);
    res->tex = tex;
}

static void load_fonts(ressources_t *res, infos_t *infos)
{
    fonts_t *fo = malloc(sizeof(fonts_t));

    fo->basic = sfFont_createFromFile(BASIC_FONT_PATH);
    fo->alphakind = sfFont_createFromFile(TEXT_FONT_PATH);
    res->fonts = fo;
    infos->mouse = (sfVector2f) {0, 0};
    infos->error = 0;
    infos->buttons = NULL;
    infos->map_2d = NULL;
    infos->ordered_map = NULL;
    infos->correct_map = NULL;
    infos->modified = 1;
    infos->select_size = 20;
    infos->size = 20;
    infos->select_mat = SAND_MATERIAL;
    infos->ancient_size = 20;
}

infos_t *load_game(char *buff, char *path)
{
    infos_t *infos = malloc(sizeof(infos_t));
    ressources_t *res = malloc(sizeof(ressources_t));

    load_textures(res);
    infos->state = STATE_MENU;
    infos->res = res;
    infos->buttons = NULL;
    infos->mainme_sys = NULL;
    if (buff != NULL)
        infos->map_data = load_map(buff, path);
    infos->editor_sys = NULL;
    infos->global_sys = NULL;
    infos->mode = MODE_CORNER;
    load_fonts(res, infos);
    load_text_buttons(res);
    load_sounds(res);
    return (infos);
}