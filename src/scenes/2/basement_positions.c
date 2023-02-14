/*
** EPITECH PROJECT, 2022
** set_basement_position
** File description:
** basement_positions
*/

#include "header.h"

int set_low_basement(data_t *data)
{
    sfVector2f one = {610, 400};
    sfVector2f two = {710, 400};
    sfVector2f three = {810, 400};
    sfVector2f four = {910, 400};
    sfVector2f five = {1010, 400};
    sfVector2f six = {1110, 400};
    sfVector2f seven = {1210, 400};

    sfSprite_setPosition(data->basement->basement[0], one);
    sfSprite_setPosition(data->basement->basement[1], two);
    sfSprite_setPosition(data->basement->basement[2], three);
    sfSprite_setPosition(data->basement->basement[4], four);
    sfSprite_setPosition(data->basement->basement[5], five);
    sfSprite_setPosition(data->basement->basement[6], six);
    sfSprite_setPosition(data->basement->basement[7], seven);
    return 0;
}

int set_high_basement(data_t *data)
{
    sfVector2f eight = {610, 220};
    sfVector2f nine = {710, 220};
    sfVector2f ten = {810, 220};
    sfVector2f eleven = {910, 220};
    sfVector2f twelve = {1010, 220};
    sfVector2f thirteen = {1110, 220};
    sfVector2f fourteen = {1210, 220};
    sfVector2f fifteen = {1310, 220};
    sfVector2f sixteen = {510, 220};

    sfSprite_setPosition(data->basement->basement[8], eight);
    sfSprite_setPosition(data->basement->basement[9], nine);
    sfSprite_setPosition(data->basement->basement[10], ten);
    sfSprite_setPosition(data->basement->basement[11], eleven);
    sfSprite_setPosition(data->basement->basement[12], twelve);
    sfSprite_setPosition(data->basement->basement[13], thirteen);
    sfSprite_setPosition(data->basement->basement[14], fourteen);
    sfSprite_setPosition(data->basement->basement[15], fifteen);
    sfSprite_setPosition(data->basement->basement[16], sixteen);
    return 0;
}

int sides_basement(data_t *data)
{
    sfVector2f seventeen = {390, 360};
    sfVector2f eighteen = {300, 360};
    sfVector2f nineteen = {390, 270};
    sfVector2f twenty = {1450, 360};
    sfVector2f twentyone = {-1450, 270};

    sfSprite_setPosition(data->basement->basement[17], seventeen);
    sfSprite_setPosition(data->basement->basement[18], eighteen);
    sfSprite_setPosition(data->basement->basement[19], nineteen);
    sfSprite_setPosition(data->basement->basement[20], twenty);
    sfSprite_setPosition(data->basement->basement[21], twentyone);
    return 0;
}

int set_basement_position(data_t *data)
{
    set_low_basement(data);
    set_high_basement(data);
    sides_basement(data);
    return 0;
}
