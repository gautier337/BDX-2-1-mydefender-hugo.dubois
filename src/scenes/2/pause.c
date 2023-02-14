/*
** EPITECH PROJECT, 2022
** pause
** File description:
** pause
*/

#include "header.h"

int unpause(data_t *data)
{
    sfVector2f hide = {-1700, -10000};
    sfVector2f show_pause = {25, 20};

    sfSprite_setPosition(data->scene[1]->sprite[1], hide);
    sfSprite_setPosition(data->scene[1]->sprite[2], hide);
    sfSprite_setPosition(data->scene[1]->sprite[3], show_pause);
    sfSprite_setPosition(data->scene[1]->sprite[4], hide);
    sfSprite_setPosition(data->scene[0]->sprite[3], hide);
    return 0;
}

int on_pause(data_t *data)
{
    sfVector2f exit_vector = {835, 175};
    sfVector2f pause_img = {900, 400};
    sfVector2f hide = {-1700, -75};
    sfVector2f settings = {865, 600};
    sfVector2f exit_all = {20, 20};
    sfVector2f vector_exit_all = {0.5, 0.5};

    sfSprite_setScale(data->scene[0]->sprite[3], vector_exit_all);
    sfSprite_setPosition(data->scene[0]->sprite[3], exit_all);
    sfSprite_setPosition(data->scene[1]->sprite[1], exit_vector);
    sfSprite_setPosition(data->scene[1]->sprite[2], pause_img);
    sfSprite_setPosition(data->scene[1]->sprite[3], hide);
    sfSprite_setPosition(data->scene[1]->sprite[4], settings);
    return 0;
}

int call_pause(data_t *data)
{
    if (data->pause_two == 0) {
        sfMusic_pause(data->music_game);
        on_pause(data);
        data->pause_two = 1;
    } else {
        unpause(data);
        sfMusic_play(data->music_game);
        sfClock_restart(data->game_info->timer_score);
        sfClock_restart(data->global_timer);
        data->pause_two = 0;
    }
    return 0;
}

int draw_pause(data_t *data)
{
    for (int i = 1; i < 5; i++)
        sfRenderWindow_drawSprite(
            data->window, data->scene[1]->sprite[i], NULL);
    sfRenderWindow_drawSprite(data->window, data->scene[0]->sprite[3], NULL);
    return 0;
}
