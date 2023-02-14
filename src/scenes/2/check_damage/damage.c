/*
** EPITECH PROJECT, 2022
** damage
** File description:
** damage
*/

#include "header.h"

sfVector2f check_tower_end_life(data_t *data, int i, sfVector2f pos,
                                    sfSprite *sprite)
{
    if (data->game_info->life_enemies[i - 4] <= 0) {
        data->game_info->life_enemies[i - 4] = 100;
        pos.x = -580;
        pos.y = 550;
        sfSprite_setRotation(sprite, -90);
        data->game_info->money += 25;
    }
    if (pos.x <= 0)
        data->game_info->life_enemies[i - 4] = 100;
    return pos;
}

sfFloatRect get_circle(int tower_nbr, int y, data_t *data)
{
    sfFloatRect rect_circle;

    if (tower_nbr == 0)
        rect_circle = sfCircleShape_getGlobalBounds(
        data->towers->simple_tower->circle[y]);
    if (tower_nbr == 1)
        rect_circle = sfCircleShape_getGlobalBounds(
        data->towers->medium_tower->circle[y]);
    if (tower_nbr == 2)
        rect_circle = sfCircleShape_getGlobalBounds(
        data->towers->advanced_tower->circle[y]);
    if (tower_nbr == 3)
        rect_circle = sfCircleShape_getGlobalBounds(
        data->towers->hardcore_tower->circle[y]);
    return rect_circle;
}

int give_damage(data_t *data, sfFloatRect rect_circle, int i,
                    int idx_circle)
{
    sfFloatRect rect_sprites = sfSprite_getGlobalBounds(
        data->scene[1]->sprite[i]);
    if (sfFloatRect_intersects(&rect_circle, &rect_sprites, NULL) == sfTrue) {
        if (idx_circle == 0)
            data->game_info->life_enemies[i - 4] -= 3.75;
        if (idx_circle == 1)
            data->game_info->life_enemies[i - 4] -= 12.25;
        if (idx_circle == 2)
            data->game_info->life_enemies[i - 4] -= 18.25;
        if (idx_circle == 3)
            data->game_info->life_enemies[i - 4] -= 22.5;
        data->shooted = 1;
    }
    return 0;
}

int check_towers_damage(data_t *data, int y)
{
    data->shooted = 0;
    sfFloatRect rect_sprites;
    sfFloatRect rect_circle;

    for (int idx_circle = 0; idx_circle < 4; idx_circle++) {
        rect_circle = get_circle(idx_circle, y, data);
        data->shooted = 0;
        for (int i = 5; i < 51 && data->shooted == 0; i++)
            give_damage(data, rect_circle, i, idx_circle);
    }
    return 0;
}

int check_damage(data_t *data)
{
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(data->game_info->shooter)) > 0.25) {
        for (int y = 0; y < 21; y++) {
            check_towers_damage(data, y);
        }
        sfClock_restart(data->game_info->shooter);
    }
    return 0;
}
