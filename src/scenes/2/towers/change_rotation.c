/*
** EPITECH PROJECT, 2022
** change_rotation
** File description:
** change_rotation
*/

#include "header.h"

int change_twenty(sfSprite *sprite, sfSprite *sprite_basement,
    int basement_selected)
{
    sfVector2f position = sfSprite_getPosition(sprite_basement);

    if (basement_selected == 20) {
        position.y = position.y + 103;
        position.x = position.x - 40;
        sfSprite_setRotation(sprite, 270);
        sfSprite_setPosition(sprite, position);
    }
    return 0;
}

int change_rotation(sfSprite *sprite, sfSprite *sprite_basement,
    int basement_selected)
{
    sfVector2f position = sfSprite_getPosition(sprite_basement);

    if (basement_selected >= 8 && basement_selected <= 18
        || basement_selected == 20) {
        position.y = position.y + 106;
        position.x = position.x + 100;
        sfSprite_setRotation(sprite, 180);
        sfSprite_setPosition(sprite, position);
    }
    if (basement_selected == 19 || basement_selected == 7) {
        position.y = position.y - 25;
        position.x = position.x + 102;
        sfSprite_setRotation(sprite, 90);
        sfSprite_setPosition(sprite, position);
    }
    change_twenty(sprite, sprite_basement, basement_selected);
    return 0;
}
