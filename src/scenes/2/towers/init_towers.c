/*
** EPITECH PROJECT, 2022
** init_tower
** File description:
** init_towers
*/

#include "header.h"

int init_towers_two(data_t *data)
{
    data->towers->advanced_tower->circle = malloc(sizeof(sfCircleShape *) * 22);
    data->towers->advanced_tower->circle[21] = NULL;
    data->towers->advanced_tower->tower = malloc(sizeof(sfSprite *) * 22);
    data->towers->advanced_tower->tower[21] = NULL;
    if (init_advanced_tower(data) == 84)
        return 84;

    data->towers->hardcore_tower->circle = malloc(sizeof(sfCircleShape *) * 22);
    data->towers->hardcore_tower->circle[21] = NULL;
    data->towers->hardcore_tower->tower = malloc(sizeof(sfSprite *) * 22);
    data->towers->hardcore_tower->tower[21] = NULL;
    if (init_hardcore_tower(data) == 84)
        return 84;
    return 0;
}

int init_medium_towers(data_t *data)
{
    data->towers->medium_tower->circle = malloc(sizeof(sfCircleShape *) * 22);
    data->towers->medium_tower->circle[21] = NULL;
    data->towers->medium_tower->tower = malloc(sizeof(sfSprite *) * 22);
    data->towers->medium_tower->tower[21] = NULL;
    if (init_medium_tower(data) == 84)
        return 84;
    return 0;
}

int init_towers(data_t *data)
{
    data->towers = malloc(sizeof(towers_t));
    data->towers->timer_rect = sfClock_create();
    data->towers->simple_tower = malloc(sizeof(simple_tower_t));
    data->towers->medium_tower = malloc(sizeof(medium_tower_t));
    data->towers->advanced_tower = malloc(sizeof(advanced_tower_t));
    data->towers->hardcore_tower = malloc(sizeof(hardcore_tower_t));
    data->game_info->shooter = sfClock_create();

    data->towers->show_circle = 1;
    data->towers->simple_tower->circle = malloc(sizeof(sfCircleShape *) * 22);
    data->towers->simple_tower->circle[21] = NULL;
    data->towers->simple_tower->tower = malloc(sizeof(sfSprite *) * 22);
    data->towers->simple_tower->tower[21] = NULL;
    if (init_simple_towers(data) == 84)
        return 84;
    init_medium_towers(data);
    if (init_towers_two(data) == 84)
        return 84;
    return 0;
}
