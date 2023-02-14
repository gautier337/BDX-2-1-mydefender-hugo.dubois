/*
** EPITECH PROJECT, 2022
** main_tower_init
** File description:
** init_towers_main
*/

#include "header.h"

sfCircleShape *set_circle(float x, float y, int opacity)
{
    sfVector2f pos = {x, y};
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setFillColor(circle, sfColor_fromRGBA(255, 125, 0, 50));
    sfCircleShape_setRadius(circle, 130);
    sfCircleShape_setOutlineThickness(circle, 5);
    sfCircleShape_setOutlineColor(circle, sfColor_fromRGBA(255, 0, 0, opacity));
    return circle;
}

int init_hardcore_tower(data_t *data)
{
    sfIntRect rect = {0, 0, 125, 125};

    data->towers->hardcore_tower->texture =
        sfTexture_createFromFile(HARDCORE, NULL);
    if (!data->towers->hardcore_tower->texture)
        return 84;
    for (int i = 0; i < 21; i++) {
        data->towers->hardcore_tower->circle[i] = set_circle(1180, 650, 255);
        data->towers->hardcore_tower->tower[i] = create_towers(
            data->towers->hardcore_tower->texture, 1180, 650, rect);
        if (!data->towers->hardcore_tower->tower[i])
            return 84;
    }
    data->towers->hardcore_tower->tower[21] = NULL;
    return 0;
}

int init_advanced_tower(data_t *data)
{
    sfIntRect rect = {0, 0, 125, 125};

    data->towers->advanced_tower->texture =
        sfTexture_createFromFile(ADVANCED, NULL);
    if (!data->towers->advanced_tower->texture)
        return 84;
    for (int i = 0; i < 21; i++) {
        data->towers->advanced_tower->circle[i] = set_circle(980, 650, 180);
        data->towers->advanced_tower->tower[i] = create_towers(
            data->towers->advanced_tower->texture, 980, 650, rect);
        if (!data->towers->advanced_tower->tower[i])
            return 84;
    }
    data->towers->advanced_tower->tower[21] = NULL;
    return 0;
}

int init_medium_tower(data_t *data)
{
    sfIntRect rect = {0, 0, 125, 130};

    data->towers->medium_tower->texture =
        sfTexture_createFromFile(MEDIUM, NULL);
    if (!data->towers->medium_tower->texture)
        return 84;
    for (int i = 0; i < 21; i++) {
        data->towers->medium_tower->circle[i] = set_circle(780, 650, 120);
        data->towers->medium_tower->tower[i] = create_towers(
            data->towers->medium_tower->texture, 780, 650, rect);
        if (!data->towers->medium_tower->tower[i])
            return 84;
    }
    data->towers->medium_tower->tower[21] = NULL;
    return 0;
}

int init_simple_towers(data_t *data)
{
    sfIntRect rect = {0, 0, 125, 130};

    data->towers->simple_tower->texture =
        sfTexture_createFromFile(SIMPLE, NULL);
    if (!data->towers->simple_tower->texture)
        return 84;
    for (int i = 0; i < 21; i++) {
        data->towers->simple_tower->circle[i] = set_circle(580, 650, 50);
        data->towers->simple_tower->tower[i] = create_towers(
            data->towers->simple_tower->texture, 580, 650, rect);
        if (!data->towers->simple_tower->tower[i])
            return 84;
    }
    data->towers->simple_tower->tower[21] = NULL;
    return 0;
}
