/*
** EPITECH PROJECT, 2022
** rect_and_scale
** File description:
** rect_scale
*/

#include "header.h"

int set_scale(float x, float y, sfSprite *sprite)
{
    sfVector2f scale = {x, y};

    sfSprite_setScale(sprite, scale);
    return 0;
}
