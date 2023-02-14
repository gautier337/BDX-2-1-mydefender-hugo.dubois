/*
** EPITECH PROJECT, 2022
** init_sprites_two
** File description:
** init_sprites_two
*/

#include "header.h"

int init_enemies_sprites(data_t *data)
{
    int i = 5;
    sfVector2f scale = {0.75, 0.75};
    sfIntRect rect = {28, 13, 72, 93};

    for (; i < 51; i++) {
        if (i < 35 && i != 11 && i != 19)
            data->scene[1]->sprite[i] = create_sprite(ENEMY1, -700, 550, 1);
        else
            data->scene[1]->sprite[i] = create_sprite(ENEMYRED, -180, 550, 1);
        if (!data->scene[1]->sprite[i])
            return 84;
        sfSprite_setTextureRect(data->scene[1]->sprite[i], rect);
        sfSprite_setRotation(data->scene[1]->sprite[i], -90);
        sfSprite_setScale(data->scene[1]->sprite[i], scale);
    }
    return 0;
}

int set_scale_rect(data_t *data)
{
    sfVector2f pause = {0.35, 0.35};
    sfVector2f pause_menu = {0.5, 0.5};
    sfVector2f uu = {0.40, 0.4};
    sfVector2f menu = {0.65, 0.65};
    sfIntRect sprite_one = {1450, 720, 500, 260};
    sfIntRect sprite_two = {100, 1374, 305, 298};
    sfIntRect sprite_three = {404, 1372, 316, 296};
    sfIntRect sprite_four = {720, 1379, 300, 300};

    sfSprite_setScale(data->scene[1]->sprite[1], pause_menu);
    sfSprite_setScale(data->scene[1]->sprite[2], uu);
    sfSprite_setScale(data->scene[1]->sprite[3], pause);
    sfSprite_setScale(data->scene[1]->sprite[4], menu);
    sfSprite_setTextureRect(data->scene[1]->sprite[1], sprite_one);
    sfSprite_setTextureRect(data->scene[1]->sprite[2], sprite_two);
    sfSprite_setTextureRect(data->scene[1]->sprite[3], sprite_three);
    sfSprite_setTextureRect(data->scene[1]->sprite[4], sprite_four);
    return 0;
}

int init_button(data_t *data)
{
    data->scene[1]->sprite[0] = create_sprite(BG_SCENEONE, 275, 75, 0);
    data->scene[1]->sprite[1] = create_sprite(SCENE_1, -1700, -500, 1);
    data->scene[1]->sprite[2] = create_sprite(SCENE_1, -1700, -500, 1);
    data->scene[1]->sprite[3] = create_sprite(SCENE_1, 20, 20, 1);
    data->scene[1]->sprite[4] = create_sprite(SCENE_1, -1700, -500, 1);
    return 0;
}

int init_sprites_two(data_t *data)
{
    int nbr_sprites = 51;

    if (init_money_sprite(data) == 84 ||
        init_basement_sprite(data) == 84 ||
        init_towers(data) == 84)
        return 84;
    data->scene[1]->sprite = malloc(sizeof(sfSprite *) * nbr_sprites + 1);
    init_button(data);
    if (init_enemies_sprites(data) == 84)
        return 84;
    data->scene[1]->sprite[nbr_sprites] = NULL;
    for (int i = 0; i < nbr_sprites; i++)
        if (data->scene[1]->sprite[i] == NULL)
            return 84;
    set_scale_rect(data);
    if (init_sprites_life(data, 46) == 84)
        return 84;
    return 0;
}
