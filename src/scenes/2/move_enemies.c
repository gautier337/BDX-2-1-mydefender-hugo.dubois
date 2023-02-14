/*
** EPITECH PROJECT, 2022
** move_enemies
** File description:
** move_enemies
*/

#include "header.h"

int algo_move_enemies(data_t *data, int bool)
{
    sfIntRect rect_one = {28, 13, 72, 93};
    sfIntRect rect_two = {156, 13, 72, 93};

    for (int i = 5; i < 51; i++) {
        if (bool == 1) {
            sfSprite_setTextureRect(data->scene[1]->sprite[i], rect_one);
            data->game_info->rect_bool = 1;
        } else {
            sfSprite_setTextureRect(data->scene[1]->sprite[i], rect_two);
            data->game_info->rect_bool = 0;
        }
    }
    return 0;
}

int move_enemies_rect(data_t *data)
{
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(data->game_info->timer_enemies)) > 0.08) {
        if (data->game_info->rect_bool == 0)
            algo_move_enemies(data, 1);
        else
            algo_move_enemies(data, 0);
        sfClock_restart(data->game_info->timer_enemies);
    }
    return 0;
}

sfVector2f check_condition_one(sfSprite *sprite, sfVector2f pos, int speed)
{
    if (pos.x < 482)
        pos.x = pos.x + speed;
    if ((pos.x >= 482 && pos.x <= 500) && (pos.y == 550 || pos.y == 480)) {
        sfSprite_setRotation(sprite, 180);
        pos.x = 550;
    }
    if (pos.x == 550 && pos.y > 395)
        pos.y = pos.y - speed;
    if (pos.y != 378)
        if (pos.x == 550 && (pos.y > 350 && pos.y < 420)) {
            sfSprite_setRotation(sprite, -90);
            pos.x = 500;
            pos.y = 378;
        }
    if (pos.y == 378 && pos.x < 1345)
        pos.x = pos.x + speed;
    if ((pos.x >= 1340 && pos.x <= 1415) && pos.y == 378)
        pos.y = 320;
    return pos;
}

sfVector2f check_condition_two(sfSprite *sprite, sfVector2f pos,
                                int speed, data_t *data)
{
    if ((pos.x >= 1340 && pos.x <= 1355) && pos.y < 475) {
        sfSprite_setRotation(sprite, 0);
        pos.y = pos.y + speed;
    }
    if ((pos.y >= 460 && pos.y <= 485) && (pos.x >= 1340
        && pos.x <= 1550) && pos.y != 481) {
        pos.y = 481;
        pos.x = 1420;
    }
    if (pos.x >= 1340 && pos.y == 481) {
        pos.x = pos.x + speed;
        sfSprite_setRotation(sprite, 90);
    }
    if (pos.x >= 1625) {
        change_status(data, -1);
        pos.x = -380;
        pos.y = 550;
        sfSprite_setRotation(sprite, -90);
    }
    return pos;
}

int move_enemies_position(data_t *data, int i, int speed)
{
    sfSprite *sprite = data->scene[1]->sprite[i];
    sfVector2f pos = sfSprite_getPosition(sprite);

    if (pos.y > 200) {
        if (sfTime_asSeconds(
            sfClock_getElapsedTime(data->game_info->timer_enemies)) > 0.02) {
            pos = check_tower_end_life(data, i, pos, sprite);
            pos = check_condition_one(sprite, pos, speed);
            pos = check_condition_two(sprite, pos, speed, data);
            sfSprite_setPosition(sprite, pos);
            return 0;
        }
    }
    return 0;
}
