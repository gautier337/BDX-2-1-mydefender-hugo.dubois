/*
** EPITECH PROJECT, 2022
** set_pos
** File description:
** set_pos
*/

#include "header.h"

int set_pos(float x, float y, sfSprite *sprite)
{
    sfVector2f my_pos = {x, y};

    sfSprite_setPosition(sprite, my_pos);
    return 0;
}
