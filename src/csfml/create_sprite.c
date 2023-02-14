/*
** EPITECH PROJECT, 2022
** my_csfmllib
** File description:
** create sprite
*/

#include "header.h"

sfSprite *create_basement(sfTexture *texture, int x, int y, int pos_bool)
{
    sfVector2f my_pos = {x, y};
    sfSprite *sprite = sfSprite_create();

    if (!texture)
        return NULL;
    sfSprite_setTexture(sprite, texture, sfTrue);
    if (pos_bool == 1)
        sfSprite_setPosition(sprite, my_pos);
    return sprite;
}

sfSprite *create_towers(sfTexture *texture, int x, int y, sfIntRect rect)
{
    sfVector2f my_pos = {x, y};
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, my_pos);
    return sprite;
}

sfSprite *create_sprite(char *path, int x, int y, int pos_bool)
{
    sfVector2f my_pos = {x, y};
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    if (!texture)
        return NULL;
    sfSprite_setTexture(sprite, texture, sfTrue);
    if (pos_bool == 1)
        sfSprite_setPosition(sprite, my_pos);
    return sprite;
}
