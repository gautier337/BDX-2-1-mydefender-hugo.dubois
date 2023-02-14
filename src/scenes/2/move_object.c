/*
** EPITECH PROJECT, 2022
** move_enemies
** File description:
** move_enemies
*/

#include "header.h"

int get_last_index_bool(data_t *data)
{
    sfClock *global_timer = data->global_timer;
    float global_seconds = sfTime_asSeconds(
        sfClock_getElapsedTime(global_timer));
    int x = 1;
    int speed_spawn = 5;

    data->game_info->enemies_bool[0] = 1;
    if (global_seconds > speed_spawn) {
        for (; data->game_info->enemies_bool[x - 1] == 1
            && data->game_info->enemies_bool[x] != -1 && x < 46; x++);
        data->game_info->enemies_bool[x - 1] = 1;
        sfClock_restart(global_timer);
    }
    return 0;
}

int move_enemiesall(data_t *data, int i)
{
    move_enemies_rect(data);
    if (i >= (31 + 4) || i == 7 || i == 15) {
        move_enemies_position(data, i + 4, 5);
        move_enemies_life(data, i, i + 4);
        return 0;
    }
    move_enemies_position(data, i + 4, 3);
    move_enemies_life(data, i, i + 4);
    return 0;
}

int move_objects(data_t *data, sfClock *clock)
{
    float seconds = sfTime_asSeconds(
        sfClock_getElapsedTime(clock));

    if (seconds > 0.02) {
        get_last_index_bool(data);
        for (int i = 0; data->game_info->enemies_bool[i] != -1
            && data->game_info->enemies_bool[i] == 1; i++)
            move_enemiesall(data, i);
        sfClock_restart(clock);
    }
    check_damage(data);
    money(data);
    move_rect_towers(data);
    move_money_rect(data);
    return 0;
}
