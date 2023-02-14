/*
** EPITECH PROJECT, 2022
** analyse_event
** File description:
** analyse_event
*/

#include "header.h"

int pause_space_button(data_t *data, sfEvent event)
{
    if (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeySpace)
        call_pause(data);
    return 0;
}

int check_settings_two(data_t *data, sfFloatRect rect, sfVector2f pos)
{
    rect = sfSprite_getGlobalBounds(data->scene[1]->
    sprite[4]);
    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue) {
        sfSound_play(data->sound_play_button);
        settings_menu_two(data);
        return 0;
    }
    return 0;
}

int check_pause_sprite_click(data_t *data, sfVector2f pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(data->scene[1]->
        sprite[3]);
    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue) {
        sfSound_play(data->sound_play_button);
        call_pause(data);
        return 0;
    }
    rect = sfSprite_getGlobalBounds(data->scene[1]->
    sprite[2]);
    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue) {
        sfSound_play(data->sound_play_button);
        call_pause(data);
        return 0;
    }
    check_settings_two(data, rect, pos);
    return 0;
}

int check_fps_two(data_t *data, sfFloatRect rect, sfVector2f pos)
{
    rect = sfSprite_getGlobalBounds(data->scene[0]->sprite[6]);
    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue) {
        sfSound_play(data->sound_play_button);
        data->game_info->fps = 60.0;
        return 0;
    }
    rect = sfSprite_getGlobalBounds(data->scene[0]->sprite[7]);
    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue) {
        sfSound_play(data->sound_play_button);
        data->game_info->fps = 120.0;
        return 0;
    }
    rect = sfSprite_getGlobalBounds(data->scene[0]->sprite[3]);
    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue) {
        sfSound_play(data->sound_play_button);
        sfRenderWindow_close(data->window);
        return 0;
    }
    return 0;
}

int check_scene_two(data_t *data)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(data->window);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(data->window, mouse, NULL);
    sfFloatRect rect = sfSprite_getGlobalBounds(data->scene[1]->
        sprite[1]);

    if (sfFloatRect_contains(&rect, pos.x, pos.y) == sfTrue) {
        sfSound_play(data->sound_play_button);
        destroy(data, 0);
        if (init(data) == 84) {
            my_putstr("Error in reinitialization.\n");
            return 84;
        }
        return 0;
    }
    check_fps_two(data, rect, pos);
    check_pause_sprite_click(data, pos);
    check_click_basement(data, pos, rect);
    check_click_towers(data, pos);
    return 0;
}
