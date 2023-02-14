/*
** EPITECH PROJECT, 2022
** check_money
** File description:
** check_money
*/

#include "header.h"

int change_money(data_t *data, int tower)
{
    if (tower == 0) {
        data->game_info->money -= 50;
        return 1;
    }
    if (tower == 1) {
        data->game_info->money -= 100;
        return 1;
    }
    if (tower == 2) {
        data->game_info->money -= 150;
        return 1;
    }
    if (tower == 3) {
        data->game_info->money -= 250;
        return 1;
    }
    return 0;
}

int money_sound(data_t *data)
{
    if (!data->coins_fubb) {
        sfSoundBuffer_destroy(data->coins_fubb);
        sfSound_destroy(data->money_sound);
        return 84;
    }
    sfSound_play(data->money_sound);
    return 0;
}
