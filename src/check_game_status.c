/*
** EPITECH PROJECT, 2022
** check_win_lose
** File description:
** check_game_status
*/

#include "header.h"

int check_skip_button(data_t *data, sfVector2f pos)
{
    if (data->game_info->win_or_lose == 0)
        return 0;
    sfFloatRect rect = sfSprite_getGlobalBounds(data->game_info->skip_sprite);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue) {
        chest_helper(data);
        data->game_info->skip = 1;
        sfSound_play(data->sound_play_button);
        return 0;
    }
    return 0;
}

int draw_status_sprites(data_t *data)
{
    if (data->game_info->win_or_lose == 1) {
        sfRenderWindow_drawSprite(data->window,
            data->game_info->win_status, NULL);
        sfRenderWindow_drawSprite(data->window,
            data->game_info->skip_sprite, NULL);
    } else if (data->game_info->win_or_lose == -1) {
        sfRenderWindow_drawSprite(data->window,
            data->game_info->lose_status, NULL);
        sfRenderWindow_drawSprite(data->window,
            data->game_info->skip_sprite, NULL);
    }
    return 0;
}

int draw_status(data_t *data)
{
    sfVector2f hide = {-1200, -1200};

    if (sfTime_asSeconds(sfClock_getElapsedTime
        (data->game_info->timer_screen_status)) > 10
        || data->game_info->skip == 1) {
        if (data->game_info->skip != 1)
            chest_helper(data);
        data->game_info->win_or_lose = 0;
        sfMusic_play(data->music);
        sfSprite_setPosition(data->game_info->skip_sprite, hide);
        return 0;
    }
    draw_status_sprites(data);
    return 0;
}

int change_status(data_t *data, int win_or_lose)
{
    sfVector2f show_skip = {1400, 700};

    destroy(data, 0);
    if (init(data) == 84) {
        my_putstr("Error in reinitialization.\n");
        data->error = 84;
        return 84;
    }
    if (win_or_lose == 1)
        data->game_info->win_or_lose = 1;
    else
        data->game_info->win_or_lose = -1;
    sfSprite_setPosition(data->game_info->skip_sprite, show_skip);
    sfMusic_stop(data->music);
    sfClock_restart(data->game_info->timer_screen_status);
    chest_helper(data);
    return 0;
}

int check_game_status(data_t *data)
{
    if (data->game_info->score >= 10000)
        change_status(data, 1);
    return 0;
}
