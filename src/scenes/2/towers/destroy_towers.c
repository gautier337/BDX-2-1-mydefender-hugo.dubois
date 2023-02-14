/*
** EPITECH PROJECT, 2022
** destroy_towers
** File description:
** destroy_towers
*/

#include "header.h"

int destroy_towers(data_t *data)
{
    for (int i = 0; data->towers->simple_tower->tower[i]
        != NULL; i++) {
        sfSprite_destroy(data->towers->simple_tower->tower[i]);
        sfSprite_destroy(data->towers->medium_tower->tower[i]);
        sfSprite_destroy(data->towers->advanced_tower->tower[i]);
        sfSprite_destroy(data->towers->hardcore_tower->tower[i]);
        sfCircleShape_destroy(data->towers->simple_tower->circle[i]);
        sfCircleShape_destroy(data->towers->medium_tower->circle[i]);
        sfCircleShape_destroy(data->towers->advanced_tower->circle[i]);
        sfCircleShape_destroy(data->towers->hardcore_tower->circle[i]);
    }
    free(data->towers->simple_tower);
    free(data->towers->medium_tower);
    free(data->towers->advanced_tower);
    free(data->towers->hardcore_tower);
    free(data->towers);
    return 0;
}
