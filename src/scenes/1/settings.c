/*
** EPITECH PROJECT, 2022
** settings
** File description:
** settings
*/

#include "header.h"

int show_settings(data_t *data)
{
    sfVector2f pos = {-10, -2000};
    sfVector2f fps_first = {450, 200};
    sfVector2f fps_two = {450, 500};

    sfSprite_setPosition(data->scene[0]->sprite[2], pos);
    sfSprite_setPosition(data->scene[0]->sprite[3], pos);
    sfSprite_setPosition(data->scene[0]->sprite[5], pos);
    sfSprite_setPosition(data->scene[0]->sprite[6], fps_first);
    sfSprite_setPosition(data->scene[0]->sprite[7], fps_two);
    return 0;
}

int hide_settings(data_t *data)
{
    sfVector2f two = {550, 500};
    sfVector2f three = {350, 95};
    sfVector2f four = {1100, 190};
    sfVector2f five = {1200, 600};
    sfVector2f hide = {-1200, 0};

    sfSprite_setPosition(data->scene[0]->sprite[2], two);
    sfSprite_setPosition(data->scene[0]->sprite[3], three);
    sfSprite_setPosition(data->scene[0]->sprite[4], four);
    sfSprite_setPosition(data->scene[0]->sprite[5], five);
    sfSprite_setPosition(data->scene[0]->sprite[6], hide);
    sfSprite_setPosition(data->scene[0]->sprite[7], hide);
    return 0;
}

int settings_menu(data_t *data)
{
    if (data->settings == 0) {
        show_settings(data);
        data->settings = 1;
    } else {
        hide_settings(data);
        data->settings = 0;
    }
    return 0;
}
