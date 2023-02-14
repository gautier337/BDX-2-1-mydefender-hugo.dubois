/*
** EPITECH PROJECT, 2022
** init_fps_sprite
** File description:
** init_fps_sprite
*/

#include "header.h"

int init_fps_sprite(data_t *data)
{
    sfIntRect fps_60 = {1450, 1322, 489, 270};
    sfIntRect fps_120 = {1450, 1627, 489, 270};

    data->fps_60 = create_sprite(SCENE_1, -1200, -600, 1);
    data->fps_120 = create_sprite(SCENE_1, -1200, -600, 1);

    if (!data->fps_60 || !data->fps_120)
        return 84;
    sfSprite_setTextureRect(data->fps_120, fps_120);
    sfSprite_setTextureRect(data->fps_60, fps_60);
    return 0;
}
