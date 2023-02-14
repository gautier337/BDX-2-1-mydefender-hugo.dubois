/*
** EPITECH PROJECT, 2022
** check_env
** File description:
** check_env
*/

#include "header.h"

int check_display(char *env)
{
    char *display = "DISPLAY";

    if (!env)
        return 84;
    for (int i = 0; env[i] == display[i]; i++)
        if (display[i] == 'Y')
            return 1;
    return 0;
}

int check_env(char **env)
{
    if (!env)
        return 84;

    for (int i = 0; env[i] != NULL; i++)
        if (check_display(env[i]))
            return 1;
    return 84;
}
