/*
** EPITECH PROJECT, 2022
** two
** File description:
** two
*/

#include "header.h"

int music_start(data_t *data)
{
    sfMusic_setVolume(data->music, 15);
    if (create_sound(SOUND_PLAY,
        data->sound_play, data->buffer_sound_play) == 84) {
        my_putstr(ERROR_FILE);
        data->error = 84;
    }
    sfMusic_pause(data->music);
    if (data->music_game == NULL) {
        data->error = 84;
        my_putstr(ERROR_FILE);
        return 84;
    }
    sfMusic_setLoop(data->music_game, sfTrue);
    sfMusic_play(data->music_game);
    return 0;
}

int main_game(data_t *data)
{
    game_info_t *game_info;
    game_info = malloc(sizeof(game_info_t));
    game_info->life = 1;
    return 0;
}

int scene_two(data_t *data)
{
    sfVector2f exit_hide = {-1000, -1000};

    sfSprite_setPosition(data->scene[0]->sprite[3], exit_hide);
    music_start(data);
    data->game_info->rect_bool = 0;
    data->list_scenes[0] = 0;
    data->list_scenes[1] = 1;
    data->game_bool = 1;
    return 0;
}
