/*
** EPITECH PROJECT, 2022
** my defender
** File description:
** analyse events
*/

#include "header.h"

int check_rect_click(data_t *data, sfEvent event)
{
    int nbr_scene = 0;

    if (data->game_info->money <= 0)
        data->game_info->money = 0;
    for (; data->list_scenes[nbr_scene] != 1; nbr_scene++);
    if (data->list_scenes[0] == 1) {
        check_scene_one(data, 0);
        return 0;
    }
    if (data->list_scenes[1] == 1) {
        if (check_scene_two(data) == 84)
            return 84;
    }
    return 0;
}

int analyse_events(data_t *data)
{
    sfEvent event;
    int status = 0;

    if (!data)
        return 84;
    while (sfRenderWindow_pollEvent(data->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        if (event.type == sfEvtKeyPressed &&
            event.key.code == sfKeyEscape)
            sfRenderWindow_close(data->window);
        if (event.type == sfEvtMouseButtonPressed)
            status = check_rect_click(data, event);
        if (data->list_scenes[1] == 1)
            pause_space_button(data, event);
        if (event.type == sfEvtKeyPressed &&
            event.key.code == sfKeyH)
            check_circle_hide(data);
    }
    return status;
}
