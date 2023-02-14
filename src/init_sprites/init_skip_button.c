/*
** EPITECH PROJECT, 2022
** init_skip_button
** File description:
** init_skip_button
*/

#include "header.h"

int init_skip_button(data_t *data)
{
    sfVector2f hide = {-1200, -1200};
    sfVector2f scale = {0.25, 0.25};

    data->game_info->skip_sprite = sfSprite_create();
    data->game_info->skip_texture = sfTexture_createFromFile(SKIP, NULL);
    if (!data->game_info->skip_texture)
        return 84;
    sfSprite_setTexture(data->game_info->skip_sprite,
        data->game_info->skip_texture, sfTrue);
    sfSprite_setPosition(data->game_info->skip_sprite, hide);
    sfSprite_setScale(data->game_info->skip_sprite, scale);
    return 0;
}

int destroy_game_status(data_t *data)
{
    sfTexture_destroy(data->game_info->win_status_tx);
    sfTexture_destroy(data->game_info->lose_status_tx);
    sfSprite_destroy(data->game_info->win_status);
    sfSprite_destroy(data->game_info->lose_status);
    sfTexture_destroy(data->game_info->skip_texture);
    sfSprite_destroy(data->game_info->skip_sprite);
    return 0;
}

int init_game_status(data_t *data)
{
    sfVector2f pos = {0, 0};

    data->game_info->win_status = sfSprite_create();
    data->game_info->lose_status = sfSprite_create();
    data->game_info->win_status_tx =
        sfTexture_createFromFile(WIN_SCREEN, NULL);
    data->game_info->lose_status_tx =
        sfTexture_createFromFile(LOSE_SCREEN, NULL);
    if (!data->game_info->win_status_tx || !data->game_info->lose_status_tx
        || init_skip_button(data) == 84)
        return 84;
    sfSprite_setTexture(data->game_info->win_status,
        data->game_info->win_status_tx, sfFalse);
    sfSprite_setTexture(data->game_info->lose_status,
        data->game_info->lose_status_tx, sfFalse);
    sfSprite_setPosition(data->game_info->win_status, pos);
    sfSprite_setPosition(data->game_info->lose_status, pos);
    return 0;
}
