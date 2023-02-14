/*
** EPITECH PROJECT, 2022
** score
** File description:
** show_score
*/

#include "header.h"

char *convert_int(int nb)
{
    char *str = malloc(lenght_int(nb));
    int i = 1;
    int j = 0;

    if (nb < 0) {
        str[0] = ('-');
        convert_int(nb * -1);
        return 0;
    }
    for (int a = nb; a > 9;) {
        a = a / 10;
        i = i * 10;
    }
    while (i >= 1) {
        str[j] = (((nb / i) % 10) + '0');
        i = i / 10;
        j += 1;
    }
    str[j] = '\0';
    return str;
}

char *int_in_string(int nbr)
{
    return convert_int(nbr);
}

int update_score(data_t *data)
{
    sfText *text = data->game_info->text;
    sfFont *font = data->game_info->font;
    sfVector2f my_pos = {1500, 32};
    sfClock *timer = data->game_info->timer_score;

    if (sfTime_asSeconds(
        sfClock_getElapsedTime(timer)) > 0.1) {
        data->game_info->score = data->game_info->score + 5;
        sfText_setColor(text, sfWhite);
        sfText_setString(text, my_strcat(
            "SCORE: ", int_in_string(data->game_info->score)));
        sfText_setFont(text, font);
        sfText_setCharacterSize(text, 45);
        sfText_setPosition(text, my_pos);
        sfClock_restart(timer);
    }
    check_game_status(data);
    return 0;
}
