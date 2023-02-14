/*
** EPITECH PROJECT, 2022
** sprites_manage
** File description:
** sprites_manage
*/

#include "header.h"

int check_error_sound(data_t *data)
{
    if (!data->music_game || !data->music)
        return 84;
    if (!data->click || !data->reload || !data->coins_fubb) {
        my_putstr(ERROR_FILE);
        return 84;
    }
    return 0;
}

int init_sound(data_t *data)
{
    data->sound_play_button = sfSound_create();
    data->click = sfSoundBuffer_createFromFile(BUTTON);
    data->reload = sfSound_create();
    data->reloading = sfSoundBuffer_createFromFile(RELOAD);
    data->music_game = sfMusic_createFromFile(MUSIC_GAME);
    data->music = sfMusic_createFromFile(MUSIC_INTRO);
    data->money_sound = sfSound_create();
    data->coins_fubb = sfSoundBuffer_createFromFile(MONEY_SOUND);
    if (check_error_sound(data) == 84)
        return 84;

    sfMusic_setVolume(data->music_game, 10);
    sfSound_setVolume(data->reload, 200);
    sfSound_setBuffer(data->reload, data->reloading);
    sfSound_setBuffer(data->sound_play_button, data->click);
    sfSound_setBuffer(data->money_sound, data->coins_fubb);
    return 0;
}

int define_default(data_t *data)
{
    data->text = sfText_create();
    data->font = sfFont_createFromFile(FONT_HELPER);
    data->game_info->score = 0;
    data->game_info->win_or_lose = 0;
    data->game_info->fps = 60.0;
    data->settings_two = 0;
    data->pause_two = 0;
    data->error = 0;
    data->game_bool = 0;
    data->helper = 0;
    data->settings = 0;
    data->game_info->skip = 0;
    return 0;
}

int set_base(data_t *data)
{
    define_default(data);
    data->list_scenes = malloc(sizeof(int) * 3);
    data->list_scenes[0] = 1;
    data->game_info->text = sfText_create();
    data->game_info->font = sfFont_createFromFile(FONT_GAME_INFO);
    data->game_info->timer_score = sfClock_create();
    data->game_info->timer_screen_status = sfClock_create();
    if (init_sound(data) == 84) {
        data->error = 84;
        return 84;
    }
    if (!data->game_info->font) {
        my_putstr(ERROR_FILE);
        data->error = 84;
        return 84;
    }
    return 0;
}

int init(data_t *data)
{
    sfRenderWindow_setFramerateLimit(data->window, 0);
    data->global_timer = sfClock_create();
    data->timer = sfClock_create();
    data->game_info = malloc(sizeof(game_info_t));
    data->game_info->timer_enemies = sfClock_create();
    data->scene = malloc(sizeof(scene_t) * NBR_SCENES + 1);
    set_base(data);
    for (int i = 0; i < NBR_SCENES; i++) {
        data->scene[i] = malloc(sizeof(data->scene));
        if (i != 0)
            data->list_scenes[i] = 0;
    }
    if (init_sprites(data) != 84)
        scene1(data);
    return 0;
}
