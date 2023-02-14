/*
** EPITECH PROJECT, 2022
** move_rect_towers
** File description:
** move_rect
*/

#include "header.h"

int check_condition_rect(data_t *data, int i, int idx_circle)
{
    sfFloatRect rect_sprites;
    sfFloatRect rect_circle;

    rect_circle = get_circle(idx_circle, i, data);
    for (int i = 5; i < 51; i++) {
        rect_sprites = sfSprite_getGlobalBounds(
        data->scene[1]->sprite[i]);
        if (sfFloatRect_intersects(
            &rect_sprites, &rect_circle, NULL) == sfTrue)
            return 1;
    }
    return 0;
}

int check_towerrs_position(data_t *data, int i)
{
    if (check_condition_rect(data, i, 0) == 1)
        move_rect(data->towers->simple_tower->tower[i], 128, 1024);
    if (check_condition_rect(data, i, 1) == 1)
        move_rect(data->towers->medium_tower->tower[i], 128, 1024);
    if (check_condition_rect(data, i, 2) == 1)
        move_rect(data->towers->advanced_tower->tower[i], 128, 1408);
    if (check_condition_rect(data, i, 3) == 1)
        move_rect(data->towers->hardcore_tower->tower[i], 128, 1408);
    return 0;
}

int move_rect_towers(data_t *data)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(
        data->towers->timer_rect)) > 0.08) {
        for (int i = 0; i < 21; i++)
            check_towerrs_position(data, i);
        sfClock_restart(data->towers->timer_rect);
    }
    return 0;
}
