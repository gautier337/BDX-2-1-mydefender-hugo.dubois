/*
** EPITECH PROJECT, 2022
** change_circle_pos
** File description:
** change_circle_pos
*/

#include "header.h"

int check_circle_hide(data_t *data)
{
    if (data->towers->show_circle == 0)
        data->towers->show_circle = 1;
    else {
        data->towers->show_circle = 0;
    }
    return 0;
}

int change_circle_pos(data_t *data, sfSprite *basement, int circle, int i)
{
    sfVector2f pos = sfSprite_getPosition(basement);
    pos.x -= 95;
    pos.y -= 85;

    if (circle == 0)
        sfCircleShape_setPosition(data->towers->simple_tower->circle[i], pos);
    if (circle == 1)
        sfCircleShape_setPosition(data->towers->medium_tower->circle[i], pos);
    if (circle == 2)
        sfCircleShape_setPosition(
            data->towers->advanced_tower->circle[i], pos);
    if (circle == 3)
        sfCircleShape_setPosition(
            data->towers->hardcore_tower->circle[i], pos);
    return 0;
}
