/*
** EPITECH PROJECT, 2022
** socle
** File description:
** socle
*/

#include "header.h"

int draw_basement(data_t *data)
{
    for (int i = 0; i < 23; i++)
        sfRenderWindow_drawSprite(data->window,
            data->basement->basement[i], NULL);
    return 0;
}

int init_basement_sprites(data_t *data)
{
    sfIntRect basement = {0, 250, 106, 102};
    sfVector2f scale = {0.75, 0.75};

    data->basement->basement = malloc(sizeof(sfSprite *) * 24);
    for (int i = 0; i < 23; i++) {
        data->basement->basement[i] = create_basement(
            data->basement->texture, -500, -500, 1);
        if (!data->basement->basement[i])
            return 84;
        sfSprite_setTextureRect(data->basement->basement[i], basement);
        sfSprite_setScale(data->basement->basement[i], scale);
    }
    data->basement->basement[23] = NULL;
    return 0;
}

int init_basement_indicator(data_t *data)
{
    sfVector2f scale_indicator = {0.05, 0.05};
    sfVector2f my_pos = {-500, -500};

    data->basement->texture_indicator =
        sfTexture_createFromFile(ARROW, NULL);
    if (!data->basement->texture_indicator)
        return 84;
    data->basement->basement_indicator = sfSprite_create();
    sfSprite_setTexture(data->basement->basement_indicator,
        data->basement->texture_indicator, sfTrue);
    sfSprite_setPosition(data->basement->basement_indicator,
        my_pos);
    sfSprite_setScale(data->basement->basement_indicator, scale_indicator);
    return 0;
}

int init_basement_sprite(data_t *data)
{
    data->basement = malloc(sizeof(basement_t));
    data->basement->texture = sfTexture_createFromFile(BASEMENT, NULL);
    data->basement->boolean = malloc(sizeof(int) * 23);
    for (int i = 0; i < 22; i++)
        data->basement->boolean[i] = 0;
    data->basement->boolean[22] = -1;
    if (!data->basement->boolean)
        return 84;
    if (init_basement_indicator(data) == 84)
        return 84;
    if (init_basement_sprites(data) == 84)
        return 84;
    set_basement_position(data);
    return 0;
}
