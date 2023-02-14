/*
** EPITECH PROJECT, 2022
** analyse_event
** File description:
** analyse_event
*/

#include "header.h"

int check_fps_one(data_t *data, int nbr_scene,
                            sfFloatRect rect, sfVector2f pos)
{
    rect = sfSprite_getGlobalBounds(data->scene[nbr_scene]->sprite[6]);
    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue) {
        sfSound_play(data->sound_play_button);
        data->game_info->fps = 60.0;
        return 0;
    }
    rect = sfSprite_getGlobalBounds(data->scene[nbr_scene]->sprite[7]);
    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue) {
        sfSound_play(data->sound_play_button);
        data->game_info->fps = 120.0;
        return 0;
    }
    return check_skip_button(data, pos);
}

int check_scene_one_two(data_t *data, int nbr_scene,
                            sfFloatRect rect, sfVector2f pos)
{
    rect = sfSprite_getGlobalBounds(data->scene[nbr_scene]->sprite[4]);
    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue) {
        sfSound_play(data->sound_play_button);
        settings_menu(data);
        return 0;
    }
    rect = sfSprite_getGlobalBounds(data->scene[nbr_scene]->sprite[2]);
    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue) {
        scene_two(data);
        return 0;
    }
    check_fps_one(data, nbr_scene, rect, pos);
}

int check_scene_one(data_t *data, int nbr_scene)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(data->window);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(data->window,
        mouse, NULL);
    sfFloatRect rect = sfSprite_getGlobalBounds(data->scene[nbr_scene]->
        sprite[3]);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue) {
        sfRenderWindow_close(data->window);
        return 0;
    }
    rect = sfSprite_getGlobalBounds(data->scene[nbr_scene]->sprite[5]);
    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue) {
        sfSound_play(data->sound_play_button);
        chest_helper(data);
        return 0;
    }
    return check_scene_one_two(data, nbr_scene, rect, pos);
}
