/*
** EPITECH PROJECT, 2022
** destroy_sound
** File description:
** destroy_sound
*/

#include "header.h"

int destroy_sound(data_t *data)
{
    sfSoundBuffer_destroy(data->click);
    sfSound_destroy(data->sound_play_button);
    sfMusic_destroy(data->music_game);
    sfMusic_destroy(data->music);
    sfSoundBuffer_destroy(data->reloading);
    sfSound_destroy(data->reload);
    sfSoundBuffer_destroy(data->coins_fubb);
    sfSound_destroy(data->money_sound);
    return 0;
}
