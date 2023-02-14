/*
** EPITECH PROJECT, 2022
** destroy
** File description:
** destroy
*/

#include "header.h"

int destroy_scenes(data_t *data)
{
    for (int i = 0; i < NBR_SCENES; i++) {
        for (int y = 0; data->scene[i]->sprite[y] != NULL; y++) {
            sfTexture_destroy(
                (sfTexture *) sfSprite_getTexture(data->scene[i]->sprite[y]));
            sfSprite_destroy(data->scene[i]->sprite[y]);
        }
        free(data->scene[i]);
    }
    return 0;
}

int destroy_two(data_t *data, int close)
{
    sfText_destroy(data->text);
    sfFont_destroy(data->font);
    sfClock_destroy(data->game_info->timer_screen_status);
    sfSprite_destroy(data->how_to_play);
    sfTexture_destroy(data->how_to_play_t);
    destroy_game_status(data);
    destroy_info_towers_sprites(data);
    sfTexture_destroy((sfTexture *) sfSprite_getTexture(data->money));
    sfSprite_destroy(data->money);
    destroy_towers(data);
    sfClock_destroy(data->game_info->timer_rect_money);
    sfClock_destroy(data->towers->timer_rect);
    sfText_destroy(data->game_info->money_number);
    free(data->scene);
    free(data->game_info);
    return 0;
}

int destroy_basement(data_t *data)
{
    sfTexture_destroy(data->basement->texture);
    for (int i = 0; data->basement->basement[i] != NULL; i++)
        sfSprite_destroy(data->basement->basement[i]);
    sfSprite_destroy(data->basement->basement_indicator);
    sfTexture_destroy(data->basement->texture_indicator);
    free(data->basement);
    return 0;
}

int destroy_music_clock(data_t *data)
{
    sfClock_destroy(data->timer);
    sfClock_destroy(data->global_timer);
    if (data->game_bool == 1) {
        sfClock_destroy(data->game_info->timer_enemies);
        sfClock_destroy(data->game_info->timer_score);
        sfFont_destroy(data->game_info->font);
    }
    return 0;
}

int destroy(data_t *data, int close)
{
    if (data->error != 84) {
        destroy_scenes(data);
        destroy_music_clock(data);
        destroy_two(data, close);
        destroy_basement(data);
    }
    destroy_sound(data);
    if (close == 1)
        sfRenderWindow_destroy(data->window);
    return 0;
}
