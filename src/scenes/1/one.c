/*
** EPITECH PROJECT, 2022
** one scene
** File description:
** one
*/

#include "header.h"

int create_music(data_t *data)
{
    sfMusic_setLoop(data->music, sfTrue);
    return 0;
}

int define_rect(data_t *data)
{
    sfIntRect sprite_one = {50, 100, 1300, 890};
    sfIntRect sprite_two = {1450, 92, 480, 265};
    sfIntRect sprite_three = {1450, 400, 500, 265};
    sfIntRect sprite_four = {720, 1379, 300, 300};
    sfIntRect sprite_five = {1035, 1697, 306, 280};

    sfSprite_setTextureRect(data->scene[0]->sprite[1], sprite_one);
    sfSprite_setTextureRect(data->scene[0]->sprite[2], sprite_two);
    sfSprite_setTextureRect(data->scene[0]->sprite[3], sprite_three);
    sfSprite_setTextureRect(data->scene[0]->sprite[4], sprite_four);
    sfSprite_setTextureRect(data->scene[0]->sprite[5], sprite_five);
    return 0;
}

int scene1(data_t *data)
{
    sfVector2f scale_buttons = {1.20, 1.20};
    sfVector2f scale_coffre = {0.85, 0.85};
    sfIntRect sprite_six = {1450, 1322, 489, 270};
    sfIntRect sprite_seven = {1450, 1627, 489, 270};

    define_rect(data);
    sfSprite_setTextureRect(data->scene[0]->sprite[6], sprite_six);
    sfSprite_setTextureRect(data->scene[0]->sprite[7], sprite_seven);
    sfSprite_setScale(data->scene[0]->sprite[2], scale_buttons);
    sfSprite_setScale(data->scene[0]->sprite[5], scale_coffre);
    create_music(data);
    sfMusic_play(data->music);
}
