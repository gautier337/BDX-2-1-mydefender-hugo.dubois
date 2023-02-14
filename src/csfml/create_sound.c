/*
** EPITECH PROJECT, 2022
** create sound
** File description:
** csfml
*/

#include "header.h"

int create_sound(char const *filepath, sfSound *sound, sfSoundBuffer *buffer)
{
    sound = sfSound_create();
    buffer = sfSoundBuffer_createFromFile(filepath);

    if (!buffer) {
        sfSoundBuffer_destroy(buffer);
        sfSound_destroy(sound);
        return 84;
    }
    sfSound_setBuffer(sound, buffer);
    sfSound_play(sound);
    while (sfSound_getStatus(sound) == sfPlaying);
    sfSoundBuffer_destroy(buffer);
    sfSound_destroy(sound);
    return 0;
}
