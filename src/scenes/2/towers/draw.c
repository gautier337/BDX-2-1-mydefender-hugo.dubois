/*
** EPITECH PROJECT, 2022
** draw_towers
** File description:
** draw
*/

#include "header.h"

int draw_circles(data_t *data, int i)
{
    if (data->towers->show_circle == 1) {
        if (sfCircleShape_getPosition(
            data->towers->simple_tower->circle[i]).y < 600)
            sfRenderWindow_drawCircleShape(data->window,
                data->towers->simple_tower->circle[i], NULL);
        if (sfCircleShape_getPosition(
            data->towers->medium_tower->circle[i]).y < 600)
            sfRenderWindow_drawCircleShape(data->window,
                data->towers->medium_tower->circle[i], NULL);
        if (sfCircleShape_getPosition(
            data->towers->advanced_tower->circle[i]).y < 600)
            sfRenderWindow_drawCircleShape(data->window,
                data->towers->advanced_tower->circle[i], NULL);
        if (sfCircleShape_getPosition(
            data->towers->hardcore_tower->circle[i]).y < 600)
            sfRenderWindow_drawCircleShape(data->window,
                data->towers->hardcore_tower->circle[i], NULL);
    }
    return 0;
}

int draw_towers(data_t *data)
{
    for (int i = 0; data->towers->simple_tower->tower[i]
        != NULL; i++) {
        sfRenderWindow_drawSprite(data->window,
            data->towers->simple_tower->tower[i], NULL);
        sfRenderWindow_drawSprite(data->window,
            data->towers->medium_tower->tower[i], NULL);
        sfRenderWindow_drawSprite(data->window,
            data->towers->advanced_tower->tower[i], NULL);
        sfRenderWindow_drawSprite(data->window,
            data->towers->hardcore_tower->tower[i], NULL);
        draw_circles(data, i);
    }
    return 0;
}
