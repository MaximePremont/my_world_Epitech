/*
** EPITECH PROJECT, 2021
** My World
** File description:
** files_manager
*/

#include "world.h"

static void write_file(int fd, char *str, int allocated, char separator)
{
    write(fd, str, my_strlen(str));
    write(fd, &separator, 1);
    if (allocated)
        free(str);
}

static int skip(char *buffer, char skip, int *i)
{
    int value = my_getnbr(buffer + *i);

    for (; buffer[*i] != skip && buffer[*i + 1] != '\0'; *i += 1);
    *i += 1;
    return (value);
}

static char *file_name(char *path)
{
    int i = 0;

    for (; path[i] != '\0'; i++);
    for (; path[i] != '/' && i != 0; i--);
    return (path + i + 1);
}

map_data_t *load_map(char *buff, char *path)
{
    map_data_t *data = malloc(sizeof(map_data_t));
    int i = 0;

    data->x = skip(buff, ',', &i);
    data->y = skip(buff, '\n', &i);
    data->relief = malloc(sizeof(int *) * data->y);
    data->save_name = file_name(path);
    for (int y = 0; y < data->y; y++) {
        data->relief[y] = malloc(sizeof(int) * data->x);
        for (int x = 0; x < data->x - 1; x++)
            data->relief[y][x] = skip(buff, ',', &i);
        data->relief[y][data->x - 1] = skip(buff, ';', &i);
    }
    i += 1;
    data->materials = malloc(sizeof(int) * (((my_strlen(buff) - i) / 2) + 1));
    for (int j = 0; buff[i] != '\0'; j += 1)
        data->materials[j] = skip(buff, ',', &i);
    data->materials[(my_strlen(buff) - i) / 2] = '\0';
    free(buff);
    return (data);
}

void save_map(map_data_t map_data)
{
    char *path = my_strcat(SAVE_PATH, map_data.save_name);
    int fd;

    path = my_strcat(path, ".legend");
    fd = open(path, O_CREAT | O_RDWR | O_TRUNC, 0777);
    write_file(fd, my_nbr_to_str(map_data.x), 1, ',');
    write_file(fd, my_nbr_to_str(map_data.y), 1, '\n');
    for (int y = 0; y < map_data.y; y++) {
        for (int x = 0; x < map_data.x - 1; x++)
            write_file(fd, my_nbr_to_str(map_data.relief[y][x]), 1, ',');
        write_file
            (fd, my_nbr_to_str(map_data.relief[y][map_data.x - 1]), 1, ';');
    }
    write(fd, "\n", 1);
    for (int i = 0; map_data.materials[i]; i += 1)
        write_file(fd, my_nbr_to_str(map_data.materials[i]), 1, ',');
    free(path);
    close(fd);
}