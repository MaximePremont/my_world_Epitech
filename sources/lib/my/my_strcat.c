/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** function that concatenates two strings
*/

#include <stdlib.h>

int my_strlen(char const *src);

char *my_strcat(char const *src1, char const *src2)
{
    int len = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(src1) + my_strlen(src2) + 1));

    for (int i = 0; src1[i]; i += 1)
        dest[len++] = src1[i];
    for (int i = 0; src2[i]; i += 1)
        dest[len++] = src2[i];
    dest[len] = '\0';
    return (dest);
}