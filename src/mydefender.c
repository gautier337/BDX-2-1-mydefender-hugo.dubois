/*
** EPITECH PROJECT, 2022
** name_formatter
** File description:
** main
*/

#include "header.h"

int create_window(data_t *data)
{
    sfVideoMode df = {1920, 1080, 32};

    data->window = sfRenderWindow_create(df,
        NAME_WINDOW, sfResize | sfNone | sfTitlebar | sfClose, NULL);
    return 0;
}

int check_clock(data_t *data)
{
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(data->timer)) > 1 / data->game_info->fps) {
        sfRenderWindow_clear(data->window, sfBlack);
        draw(data);
        sfRenderWindow_display(data->window);
        sfClock_restart(data->timer);
    }
    return 0;
}

int my_defender(int argc, char **argv)
{
    int to_return = 0;
    data_t *data = malloc(sizeof(data_t));

    sfClock *clock = sfClock_create();
    create_window(data);
    init(data);
    while (sfRenderWindow_isOpen(data->window) && data->error != 84) {
        if (data->list_scenes[1] == 1 && data->pause_two != 1) {
            update_score(data);
            move_objects(data, clock);
        }
        if (analyse_events(data) == 84)
            data->error == 84;
        check_clock(data);
    }
    to_return = data->error;
    destroy(data, 1);
    free(data);
    return to_return;
}
