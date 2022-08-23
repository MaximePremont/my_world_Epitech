/*
** EPITECH PROJECT, 2021
** My World
** File description:
** main
*/

#include <stdlib.h>
#include "world.h"

void load_sounds(ressources_t *res)
{
    sounds_t *so = malloc(sizeof(sounds_t));

    so->buff_click = sfSoundBuffer_createFromFile(CLICK_SOUND_PATH);
    so->buff_music = sfSoundBuffer_createFromFile(MUSIC_SOUND_PATH);
    so->click = sfSound_create();
    so->music = sfSound_create();
    sfSound_setBuffer(so->click, so->buff_click);
    sfSound_setBuffer(so->music, so->buff_music);
    sfSound_setLoop(so->music, sfTrue);
    sfSound_setVolume(so->music, 30);
    res->sounds = so;
}

void gen_pixels(sfUint8 *pixels, sfUint8 *pi_sky, sfUint8 *pi_blo, int size)
{
    for (int i = 0; i < size; i++)
        pixels[i] = ((i + 1) % 4 == 0) ? 255 : 0;
    for (int i = 0; i < size; i += 4) {
        pi_sky[i] = 148;
        pi_sky[i + 1] = 185;
        pi_sky[i + 2] = 227;
        pi_sky[i + 3] = 255;
    }
    for (int i = 0; i < size; i++)
        pi_blo[i] = ((i + 1) % 4 == 0) ? 100 : 255;
}

int main(int argc, char **argv)
{
    char *buff = NULL;
    int error = handle_error(argc, argv, &buff);
    infos_t *infos;

    if (error == 2)
        return (0);
    if (error != 0)
        return (84);
    infos = load_game(buff, argv[1]);
    if (argc < 2)
        infos->map_data = gen_default_map(infos->size, BASIC_BIOME, "unnamed");
    if (argc >= 2)
        infos->state = STATE_EDITOR;
    start_system(infos);
    unload_game(infos);
    return (0);
}