/*
** EPITECH PROJECT, 2022
** money
** File description:
** money
*/

#include "header.h"

int init_money_sprite(data_t *data)
{
    sfIntRect money = {0, 0, 203, 170};
    sfVector2f scale = {0.35, 0.35};

    data->money = create_sprite(COIN, 1015, 38, 1);
    if (!data->money)
        return 84;
    sfSprite_setTextureRect(data->money, money);
    sfSprite_setScale(data->money, scale);
    data->game_info->timer_rect_money = sfClock_create();
    data->game_info->money_number = sfText_create();
    data->game_info->money = MONEY_START;
    return 0;
}

int move_money_rect(data_t *data)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(
        data->game_info->timer_rect_money)) > 0.08) {
        move_rect(data->money, 203, 1000);
        sfClock_restart(data->game_info->timer_rect_money);
    }
    return 0;
}

int money(data_t *data)
{
    sfText *text = data->game_info->money_number;
    sfFont *font = data->game_info->font;
    sfVector2f my_pos = {960, 50};

    sfText_setColor(text, sfWhite);
    sfText_setString(text, int_in_string(data->game_info->money));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setOrigin(text,
        (sfVector2f) {sfText_getGlobalBounds(text).width / 2,
        sfText_getGlobalBounds(text).height / 2});
    sfText_setPosition(text, my_pos);
    return 0;
}
