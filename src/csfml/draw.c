/*
** EPITECH PROJECT, 2022
** draw
** File description:
** draw
*/

#include "header.h"

int draws_towers(data_t *data)
{
    draw_towers(data);
    draw_info_towers(data);
    return 0;
}

int check_settings_draw(data_t *data)
{
    if (data->settings_two == 1) {
        sfRenderWindow_drawSprite(data->window,
            data->scene[0]->sprite[6], NULL);
        sfRenderWindow_drawSprite(data->window,
            data->scene[0]->sprite[7], NULL);
    }
    return 0;
}

int draw_game(data_t *data)
{
    sfRenderWindow_drawText(data->window, data->game_info->text, NULL);
    for (int i = 0; i < 46; i++)
        sfRenderWindow_drawText(data->window,
            data->game_info->text_life[i], NULL);
    sfRenderWindow_drawSprite(data->window, data->money, NULL);
    sfRenderWindow_drawText(data->window,
        data->game_info->money_number, NULL);
    draw_basement(data);
    draws_towers(data);
    sfRenderWindow_drawSprite(data->window,
        data->basement->basement_indicator, NULL);
    if (data->pause_two == 1)
        draw_pause(data);
    check_settings_draw(data);
    return 0;
}

int draw(data_t *data)
{
    int nbr_scene = 0;

    for (; data->list_scenes[nbr_scene] != 1; nbr_scene++);
    for (int y = 0; data->scene[nbr_scene]->sprite[y] != NULL; y++)
        sfRenderWindow_drawSprite(data->window,
            data->scene[nbr_scene]->sprite[y], NULL);
    if (data->helper == 1)
        sfRenderWindow_drawSprite(data->window, data->how_to_play, NULL);
    if (data->list_scenes[1] == 1) {
        draw_game(data);
    }
    if (data->game_info->win_or_lose != 0)
        draw_status(data);
    return 0;
}
