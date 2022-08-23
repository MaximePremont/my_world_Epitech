/*
** EPITECH PROJECT, 2021
** gen_map
** File description:
** Generate all stuff around maps
*/

#include <math.h>
#include <stdlib.h>
#include "world.h"

static void gen_relief(map_data_t *map, int x, int y,
sfVector2f param)
{
    if (param.x < 0)
        return;
    map->relief[y][x] += param.x * param.y / 2;
    param.x -= 10;
    if (y - 1 >= 0)
        gen_relief(map, x, y - 1, param);
    if (x - 1 >= 0)
        gen_relief(map, x - 1, y, param);
    if (y + 1 < map->y)
        gen_relief(map, x, y + 1, param);
    if (x + 1 < map->x)
        gen_relief(map, x + 1, y, param);
}

static void gen_material(map_data_t *map, int x, int y,
sfVector2i param)
{
    if (param.x < 0)
        return;
    if (map->relief[x][y] < 4)
        map->materials[x + y * map->x] = param.y;
    param.x -= 1;
    if (y - 1 >= 0)
        gen_material(map, x, y - 1, param);
    if (x - 1 >= 0)
        gen_material(map, x - 1, y, param);
    if (y + 1 < map->y)
        gen_material(map, x, y + 1, param);
    if (x + 1 < map->x)
        gen_material(map, x + 1, y, param);
}

void gen_custom_map(map_data_t *map, int size, gen_data_t data)
{
    for (int i = 0; i < size * data.relief_ratio; i += 1)
        gen_relief(map, mrand() % size, mrand() % size,
            (sfVector2f){mrand() % data.max_height, data.rigidity});
    for (int i = 0; i < size * data.relief_ratio; i += 1)
        gen_relief(map, mrand() % size, mrand() % size,
        (sfVector2f){10, data.rigidity});
    for (int i = 0; i < size * data.relief_ratio; i += 1)
        gen_relief(map, mrand() % size, mrand() % size,
        (sfVector2f){10, data.hole_ratio});
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            map->materials[i + j * size] = (map->relief[i][j] < 4) + 3;
    for (int i = 0; i < size / 3; i += 1)
        gen_material(map, mrand() % size, mrand() % size,
            (sfVector2i){mrand() % data.max_material + 2, SAND_MATERIAL});
}

map_data_t *gen_default_map(int size, gen_data_t data, char *save_name)
{
    map_data_t *map = malloc(sizeof(map_data_t));

    map->relief = malloc(sizeof(int *) * size);
    map->materials = malloc(sizeof(int) * size * size);
    map->save_name = malloc(sizeof(char) * 32);
    my_strcpy(map->save_name, save_name);
    for (int i = 0; i < size; i++) {
        map->materials[i] = GRASS_MATERIAL;
        map->relief[i] = malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++)
            map->relief[i][j] = 0;
    }
    map->x = size;
    map->y = size;
    gen_custom_map(map, size, data);
    return (map);
}
