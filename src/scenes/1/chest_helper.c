/*
** EPITECH PROJECT, 2022
** chest_helper
** File description:
** chest_helper
*/

#include "header.h"

int init_chest(data_t *data)
{
    sfVector2f pos = {275, 75};
    sfIntRect sprite_one = {50, 100, 1300, 890};

    data->how_to_play = sfSprite_create();
    data->how_to_play_t = sfTexture_createFromFile(HOW_TO_PLAY, NULL);
    if (!data->how_to_play_t)
        return 84;
    sfSprite_setTexture(data->how_to_play, data->how_to_play_t, sfFalse);
    sfSprite_setPosition(data->how_to_play, pos);
    sfSprite_setTextureRect(data->how_to_play, sprite_one);
    return 0;
}

int edit_position(data_t *data)
{
    sfVector2f pos_text = {400, 200};
    sfVector2f pos = {-10, -2000};
    sfVector2f helper_chest = {50, 50};

    sfText_setFont(data->text, data->font);
    sfText_setCharacterSize(data->text, 35);
    sfText_setPosition(data->text, pos_text);
    sfSprite_setPosition(data->scene[0]->sprite[2], pos);
    sfSprite_setPosition(data->scene[0]->sprite[3], pos);
    sfSprite_setPosition(data->scene[0]->sprite[4], pos);
    sfSprite_setPosition(data->scene[0]->sprite[5], helper_chest);
    data->helper = 1;
}

int hide_helper(data_t *data)
{
    sfVector2f two = {550, 500};
    sfVector2f three = {350, 95};
    sfVector2f four = {1100, 190};
    sfVector2f helper_chest = {1200, 600};

    sfSprite_setPosition(data->scene[0]->sprite[2], two);
    sfSprite_setPosition(data->scene[0]->sprite[3], three);
    sfSprite_setPosition(data->scene[0]->sprite[4], four);
    sfSprite_setPosition(data->scene[0]->sprite[5], helper_chest);
    data->helper = 0;
    return 0;
}

char *text(void)
{
    char *text = "Welcome to our tower defense !\n\n\n\
            Your goal is to protect your base from the ennemies\n\
            We will give you some towers to defend your self\n\
            Each time you kill a ennemy your earns some coins\n\
            More you have coins, more you can buy towers\n\
            If you get the score of 10 000 you win\n\n\nGood luck !";
    return text;
}

int chest_helper(data_t *data)
{
    if (data->helper == 0) {
        sfText_setString(data->text, text());
        if (!data->font) {
            data->error = 84;
            return 84;
        }
        edit_position(data);
    } else
        hide_helper(data);
    return 0;
}
