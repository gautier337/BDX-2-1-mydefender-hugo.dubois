/*
** EPITECH PROJECT, 2022
** init_spritestowersinfo
** File description:
** init_sprites_info_towers
*/

#include "header.h"

int destroy_info_towers_sprites(data_t *data)
{
    sfSprite_destroy(data->price->coin_fifty);
    sfSprite_destroy(data->price->coin_hundred);
    sfSprite_destroy(data->price->coin_hundred_fifty);
    sfSprite_destroy(data->price->coin_two_hundred_fifty);

    sfTexture_destroy(data->price->coin_fifty_tex);
    sfTexture_destroy(data->price->coin_hundred_tex);
    sfTexture_destroy(data->price->coin_hundred_fifty_tex);
    sfTexture_destroy(data->price->coin_two_hundred_fifty_tex);

    return 0;
}

int draw_info_towers(data_t *data)
{
    sfVector2f scale = {0.25, 0.25};

    set_pos(600, 755, data->price->coin_fifty);
    set_pos(800, 755, data->price->coin_hundred);
    set_pos(1000, 755, data->price->coin_hundred_fifty);
    set_pos(1200, 755, data->price->coin_two_hundred_fifty);
    sfSprite_setScale(data->price->coin_fifty, scale);
    sfSprite_setScale(data->price->coin_hundred, scale);
    sfSprite_setScale(data->price->coin_hundred_fifty, scale);
    sfSprite_setScale(data->price->coin_two_hundred_fifty, scale);
    sfRenderWindow_drawSprite(data->window, data->price->coin_fifty, NULL);
    sfRenderWindow_drawSprite(data->window, data->price->coin_hundred, NULL);
    sfRenderWindow_drawSprite(data->window,
        data->price->coin_hundred_fifty, NULL);
    sfRenderWindow_drawSprite(data->window,
        data->price->coin_two_hundred_fifty, NULL);
    return 0;
}

int init_info_towers_sprites(data_t *data)
{
    data->price = malloc(sizeof(price_towers_t));
    data->price->coin_fifty = sfSprite_create();
    data->price->coin_fifty_tex = sfTexture_createFromFile(COIN50, NULL);
    data->price->coin_hundred = sfSprite_create();
    data->price->coin_hundred_fifty_tex =
        sfTexture_createFromFile(COIN150, NULL);
    data->price->coin_hundred_fifty = sfSprite_create();
    data->price->coin_hundred_tex = sfTexture_createFromFile(COIN100, NULL);
    data->price->coin_two_hundred_fifty = sfSprite_create();
    data->price->coin_two_hundred_fifty_tex =
        sfTexture_createFromFile(COIN250, NULL);
    sfSprite_setTexture(data->price->coin_fifty,
        data->price->coin_fifty_tex, sfFalse);
    sfSprite_setTexture(data->price->coin_hundred,
        data->price->coin_hundred_tex, sfFalse);
    sfSprite_setTexture(data->price->coin_hundred_fifty,
        data->price->coin_hundred_fifty_tex, sfFalse);
    sfSprite_setTexture(data->price->coin_two_hundred_fifty,
        data->price->coin_two_hundred_fifty_tex, sfFalse);
    return 0;
}
