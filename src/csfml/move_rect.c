/*
** EPITECH PROJECT, 2022
** move_rect
** File description:
** move_rect
*/

#include "header.h"

void move_rect(sfSprite *sprite, int offset, int max_value)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);
    if (rect.left >= max_value - offset)
        rect.left = 0;
    else
        rect.left += offset;
    sfSprite_setTextureRect(sprite, rect);
}
