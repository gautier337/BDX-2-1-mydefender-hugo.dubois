/*
** EPITECH PROJECT, 2022
** main
** File description:
** mainfunction
*/

#include "header.h"

int main(int argc, char **argv, char **env)
{
    if (!argv || check_env(env) == 84)
        return 84;
    return my_defender(argc, argv);
}
