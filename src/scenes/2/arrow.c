/*
** EPITECH PROJECT, 2022
** arrow
** File description:
** arrow
*/

#include "header.h"

int hide_arrow(data_t *data, int contains)
{
    sfVector2f hide = {-500, -500};

    if (contains == 0) {
        for (int i = 0; data->basement->boolean[i] != -1; i++)
            data->basement->boolean[i] = (data->basement->boolean[i] != 2)
                ? 0 : 2;
        sfSprite_setPosition(data->basement->basement_indicator, hide);
    }
    return 0;
}

int change_values_boolean(data_t *data, int i, int contains)
{
    for (int y = 0; data->basement->boolean[y] != -1; y++) {
        if (data->basement->boolean[y] != 2)
            data->basement->boolean[y] = 0;
    }
    if (data->basement->boolean[i] != 2)
        data->basement->boolean[i] = 1;
    return 0;
}

int check_wrong_conditon(data_t *data, sfVector2f pos)
{
    if (pos.y > 630 && !(pos.x < 567 || pos.x > 1304 || pos.y > 830))
        return 1;
    if (data->pause_two == 1)
        return 1;
    return 0;
}

int check_click_basement(data_t *data, sfVector2f pos, sfFloatRect rect)
{
    sfVector2f position;
    int contains = 0;

    if (check_wrong_conditon(data, pos) == 1)
        return 0;
    for (int i = 0; i < 23; i++) {
        position = sfSprite_getPosition(data->basement->basement[i]);
        position.y = position.y - 60;
        position.x = position.x + 3;
        rect = sfSprite_getGlobalBounds(data->basement->basement[i]);
        if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
            sfSound_play(data->reload);
            contains = 1;
            change_values_boolean(data, i, contains);
            sfSprite_setPosition(data->basement->basement_indicator,
                position);
        }
    }
    hide_arrow(data, contains);
    return 0;
}
