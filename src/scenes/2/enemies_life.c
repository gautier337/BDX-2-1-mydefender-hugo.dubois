/*
** EPITECH PROJECT, 2022
** move_enmies_life
** File description:
** move_enemies_life
*/

#include "header.h"

int init_sprites_life(data_t *data, int nbr_enemies)
{
    sfText **text = data->game_info->text_life;

    text = malloc(sizeof(sfText *) * nbr_enemies + 1);
    for (int i = 0; i < nbr_enemies; i++)
        text[i] = sfText_create();
    text[nbr_enemies] = NULL;
    data->game_info->text_life = text;
    data->game_info->life_enemies = malloc(sizeof(int) * nbr_enemies);
    for (int i = 0; i < nbr_enemies; i++)
        data->game_info->life_enemies[i] = 100;
    data->game_info->enemies_bool = malloc(sizeof(int) * nbr_enemies + 1);
    for (int i = 0; i < nbr_enemies; i++)
        data->game_info->enemies_bool[i] = 0;
    data->game_info->enemies_bool[nbr_enemies + 1] = -1;
    return 0;
}

int move_enemies_life(data_t *data, int text_life_idx, int idx_sprite)
{
    sfText *text = data->game_info->text_life[text_life_idx];
    sfFont *font = data->game_info->font;
    sfVector2f my_pos = sfSprite_getPosition(
        data->scene[1]->sprite[idx_sprite]);

    sfText_setColor(text, sfBlue);
    sfText_setString(text,
        int_in_string(data->game_info->life_enemies[text_life_idx]));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfText_setPosition(text, my_pos);
    return 0;
}
