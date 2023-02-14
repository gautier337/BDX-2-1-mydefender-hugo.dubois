/*
** EPITECH PROJECT, 2022
** check_click_towers
** File description:
** check_click_towers
*/

#include "header.h"

int check_hardcore(data_t *data, int i, sfVector2f pos, int selected)
{
    sfVector2f position;
    sfSprite *tower = data->towers->hardcore_tower->tower[i];
    sfFloatRect rect = sfSprite_getGlobalBounds(tower);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue
        && data->game_info->money >= 250) {
        position = sfSprite_getPosition(data->basement->basement[selected]);
        position.x = position.x - 28;
        position.y = position.y - 28;
        change_circle_pos(data, data->basement->basement[selected], 3, i);
        sfSprite_setPosition(tower, position);
        change_rotation(tower, data->basement->basement[selected], selected);
        sfSound_play(data->reload);
        hide_arrow(data, 0);
        data->basement->boolean[selected] = 2;
        return change_money(data, 3);
    } else if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue
        && data->basement->boolean[selected] != 2)
        money_sound(data);
    return 0;
}

int check_advanced(data_t *data, int i, sfVector2f pos, int selected)
{
    sfVector2f position;
    sfSprite *tower = data->towers->advanced_tower->tower[i];
    sfFloatRect rect = sfSprite_getGlobalBounds(tower);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue
        && data->game_info->money >= 150) {
        position = sfSprite_getPosition(data->basement->basement[selected]);
        position.x = position.x - 28;
        position.y = position.y - 28;
        change_circle_pos(data, data->basement->basement[selected], 2, i);
        sfSprite_setPosition(tower, position);
        change_rotation(tower, data->basement->basement[selected], selected);
        sfSound_play(data->reload);
        hide_arrow(data, 0);
        data->basement->boolean[selected] = 2;
        return change_money(data, 2);
    } else if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue
        && data->basement->boolean[selected] != 2)
        money_sound(data);
    return 0;
}

int check_medium(data_t *data, int i, sfVector2f pos, int selected)
{
    sfVector2f position;
    sfSprite *tower = data->towers->medium_tower->tower[i];
    sfFloatRect rect = sfSprite_getGlobalBounds(tower);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue
        && data->game_info->money >= 100) {
        position = sfSprite_getPosition(data->basement->basement[selected]);
        position.x = position.x - 28;
        position.y = position.y - 28;
        change_circle_pos(data, data->basement->basement[selected], 1, i);
        sfSprite_setPosition(tower, position);
        change_rotation(tower, data->basement->basement[selected], selected);
        sfSound_play(data->reload);
        hide_arrow(data, 0);
        data->basement->boolean[selected] = 2;
        return change_money(data, 1);
    } else if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue
        && data->basement->boolean[selected] != 2)
        money_sound(data);
    return 0;
}

int check_simple(data_t *data, int i, sfVector2f pos, int selected)
{
    sfVector2f position;
    sfSprite *tower = data->towers->simple_tower->tower[i];
    sfFloatRect rect = sfSprite_getGlobalBounds(tower);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue
        && data->game_info->money >= 50) {
        position = sfSprite_getPosition(data->basement->basement[selected]);
        position.x = position.x - 28;
        position.y = position.y - 28;
        change_circle_pos(data, data->basement->basement[selected], 0, i);
        sfSprite_setPosition(tower, position);
        change_rotation(tower, data->basement->basement[selected], selected);
        sfSound_play(data->reload);
        hide_arrow(data, 0);
        data->basement->boolean[selected] = 2;
        return change_money(data, 0);
    } else if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue
        && data->basement->boolean[selected] != 2)
        money_sound(data);
    return 0;
}

int check_click_towers(data_t *data, sfVector2f pos)
{
    int selected = 0;

    for (; data->basement->boolean[selected - 1] != 1
        && data->basement->boolean[selected] != -1; selected++);
    selected = selected - 1;
    if (data->pause_two == 1)
        return 0;
    if (selected == 21)
        return 0;
    for (int i = 0; i < 21; i++) {
        if (check_simple(data, i, pos, selected) == 1)
            return 0;
        if (check_medium(data, i, pos, selected) == 1)
            return 0;
        if (check_advanced(data, i, pos, selected) == 1)
            return 0;
        if (check_hardcore(data, i, pos, selected) == 1)
            return 0;
    }
    return 0;
}
