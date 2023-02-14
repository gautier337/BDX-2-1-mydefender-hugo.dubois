/*
** EPITECH PROJECT, 2022
** settings
** File description:
** settings
*/

#include "header.h"

int show_settings_two(data_t *data)
{
    sfVector2f pos = {-10, -2000};
    sfVector2f fps_first = {380, 200};
    sfVector2f fps_two = {1080, 200};

    sfSprite_setPosition(data->scene[0]->sprite[6], fps_first);
    sfSprite_setPosition(data->scene[0]->sprite[7], fps_two);
    return 0;
}

int hide_settings_two(data_t *data)
{
    sfVector2f hide = {-1200, 0};

    sfSprite_setPosition(data->scene[0]->sprite[6], hide);
    sfSprite_setPosition(data->scene[0]->sprite[7], hide);
    return 0;
}

int settings_menu_two(data_t *data)
{
    sfVector2f settings = {865, 600};
    sfVector2f hide = {-1700, -75};

    if (data->settings_two == 0) {
        show_settings_two(data);
        unpause(data);
        sfSprite_setPosition(data->scene[1]->sprite[3], hide);
        sfSprite_setPosition(data->scene[1]->sprite[4], settings);
        data->settings_two = 1;
    } else {
        hide_settings_two(data);
        on_pause(data);
        data->settings_two = 0;
    }
    return 0;
}
