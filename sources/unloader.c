/*
** EPITECH PROJECT, 2021
** My World
** File description:
** unloader
*/

#include <stdlib.h>
#include "world.h"

static void delete_texs(textures_t *tex)
{
    sfTexture_destroy(tex->but_sq_click);
    sfTexture_destroy(tex->mode_corner);
    sfTexture_destroy(tex->mode_edge);
    sfTexture_destroy(tex->grass);
    sfTexture_destroy(tex->blow);
    sfTexture_destroy(tex->save);
    sfTexture_destroy(tex->close);
    sfTexture_destroy(tex->paint);
    sfTexture_destroy(tex->num_box);
    sfTexture_destroy(tex->text_box);
    sfTexture_destroy(tex->stone);
    sfTexture_destroy(tex->sand);
}

static void unload_textures(ressources_t *res)
{
    textures_t *tex = res->tex;

    sfTexture_destroy(tex->fader);
    sfTexture_destroy(tex->sky);
    sfTexture_destroy(tex->but_main_basic);
    sfTexture_destroy(tex->but_main_hov);
    sfTexture_destroy(tex->but_main_click);
    sfTexture_destroy(tex->but_sq_basic);
    sfTexture_destroy(tex->but_sq_hov);
    delete_texs(tex);
    free(tex);
}

static void unload_fonts_sounds(ressources_t *res)
{
    fonts_t *fo = res->fonts;
    sounds_t *so = res->sounds;

    sfFont_destroy(fo->basic);
    free(fo);
    sfSound_destroy(so->click);
    sfSound_destroy(so->music);
    sfSoundBuffer_destroy(so->buff_click);
    sfSoundBuffer_destroy(so->buff_music);
    free(so);
}

void unload_game(infos_t *infos)
{
    ressources_t *res = infos->res;

    delete_buttons(infos);
    unload_textures(res);
    unload_fonts_sounds(res);
    free(res->buttons);
    free(res);
    free_map_2d(infos->map_2d, infos->map_data->x);
    free(infos->ordered_map);
    free_map_2d(infos->correct_map, infos->map_data->x);
    free(infos->map_data);
    free(infos);
}