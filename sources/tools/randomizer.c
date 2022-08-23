/*
** EPITECH PROJECT, 2021
** randomizer
** File description:
** random generator
*/

#include <math.h>
#include <stdlib.h>
#include "world.h"

static sfBool random_check(FILE *file)
{
    unsigned int seed;

    if (!file)
        return (0);
    if (fread(&seed, sizeof(seed), 1, file) == 1) {
        srand(seed);
        fclose(file);
        return (1);
    }
    show_error("Error: Can't read file\n");
    return (0);
}

void random_seed(void)
{
    if (random_check(fopen("/dev/random", "r")))
        return;
    if (random_check(fopen("/dev/urandom", "r")))
        return;
    if (random_check(fopen("/dev/arandom", "r")))
        return;
    show_error("Error: No /dev/random files\n");
}

int mrand(void)
{
    random_seed();
    return (rand());
}