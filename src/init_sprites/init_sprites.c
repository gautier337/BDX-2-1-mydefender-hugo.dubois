/*
** EPITECH PROJECT, 2022
** init_sprites
** File description:
** init_sprites
*/

#include "header.h"

int init_sprites_one(data_t *data)
{
    int nbr_sprites = 8;

    data->scene[0]->sprite = malloc(sizeof(sfSprite *) * nbr_sprites + 1);
    data->scene[0]->sprite[0] = create_sprite(BACKGROUND_1, 275, 75, 0);
    data->scene[0]->sprite[1] = create_sprite(SCENE_1, 275, 75, 1);
    data->scene[0]->sprite[2] = create_sprite(SCENE_1, 550, 500, 1);
    data->scene[0]->sprite[3] = create_sprite(SCENE_1, 350, 95, 1);
    data->scene[0]->sprite[4] = create_sprite(SCENE_1, 1100, 190, 1);
    data->scene[0]->sprite[5] = create_sprite(SCENE_1, 1200, 600, 1);
    data->scene[0]->sprite[6] = create_sprite(SCENE_1, -1200, -600, 1);
    data->scene[0]->sprite[7] = create_sprite(SCENE_1, -1200, -600, 1);
    data->scene[0]->sprite[8] = NULL;
    for (int i = 0; i < 8; i++)
        if (data->scene[0]->sprite[i] == NULL)
            return 84;
    return 0;
}

int init_sprites_part_two(data_t *data)
{
    if (init_sprites_two(data) == 84) {
        my_putstr(ERROR_FILE);
        data->error = 84;
        return 84;
    }
    if (init_chest(data) == 84) {
        my_putstr(ERROR_FILE);
        data->error = 84;
        return 84;
    }
    if (init_info_towers_sprites(data) == 84) {
        my_putstr(ERROR_FILE);
        data->error = 84;
        return 84;
    }
    return 0;
}

int init_sprites(data_t *data)
{
    if (init_fps_sprite(data) == 84) {
        my_putstr(ERROR_FILE);
        data->error = 84;
        return 84;
    }
    if (init_sprites_one(data) == 84) {
        my_putstr(ERROR_FILE);
        data->error = 84;
        return 84;
    }
    if (init_game_status(data) == 84) {
        my_putstr(ERROR_FILE);
        data->error = 84;
        return 84;
    }
    if (init_sprites_part_two(data) == 84)
        return 84;
    return 0;
}
