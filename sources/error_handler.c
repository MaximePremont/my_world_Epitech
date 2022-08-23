/*
** EPITECH PROJECT, 2021
** My World
** File description:
** error_handler
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "world.h"

static int file_size(char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    char buff;
    int size = 0;

    if (fd < 0)
        return (OPEN_ERROR);
    for (; read(fd, &buff, 1); size++);
    return (size);
}

int check_file(char *file_path, char **buffer)
{
    int file_desc = open(file_path, O_RDONLY);
    int size = file_size(file_path);
    char *buff;

    if (file_desc < 0)
        return (OPEN_ERROR);
    buff = malloc(sizeof(char) * (size + 1));
    if (buff == NULL)
        return (ALLOC_ERROR);
    buff[size] = '\0';
    if (read(file_desc, buff, size) != size)
        return (READ_ERROR);
    *buffer = buff;
    return (0);
}

static int show_help(char *str)
{
    char *buff;
    char usages[30];
    int size;

    switch (str[1]) {
    case ('h'):
        my_strcpy(usages, "./usages/help.txt");
        break;
    default:
        return (UNKNOWN_OPTION_ERROR);
    }
    size = file_size(usages);
    buff = malloc(sizeof(char) * (size + 1));
    read(open(usages, O_RDONLY), buff, size);
    my_putstr(buff);
    free(buff);
    return (2);
}

int handle_error(int ac, char **av, char **buff)
{
    if (ac > 1 && av[1][0] == '-')
        return (show_help(av[1]));
    if (ac > 2)
        return (NB_ARGS_ERROR);
    else if (ac == 2)
        return (check_file(av[1], buff));
    return (0);
}