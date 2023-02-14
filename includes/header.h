/*
** EPITECH PROJECT, 2021
** count_words
** File description:
** my_header
*/

#ifndef my
    #define my

    #define NAME_WINDOW "MyDefender"
    #define NBR_SCENES (2)
    #define MONEY_START (100)
    #define SIMPLE_DAMAGE (25)
    #define MEDIUM_DAMAGE (75)
    #define HARDCORE_DAMAGE (150)

    #define MUSIC_INTRO "ressources/intro.ogg"
    #define MUSIC_GAME "ressources/music2.ogg"
    #define RELOAD "ressources/reload.ogg"
    #define FONT_HELPER "ressources/helper.ttf"
    #define BG_SCENEONE "ressources/map.png"
    #define BACKGROUND_1 "ressources/img.jpg"
    #define SCENE_1 "ressources/scene_one.png"
    #define SOUND_PLAY "ressources/sound_play.ogg"
    #define ENEMY1 "ressources/enemy.png"
    #define ENEMYRED "ressources/enemy_red.png"
    #define FONT_GAME_INFO "ressources/basic_font.ttf"
    #define COIN "ressources/money.png"
    #define BASEMENT "ressources/basement.png"
    #define ARROW "ressources/arrow.png"
    #define BUTTON "ressources/button.ogg"
    #define HOW_TO_PLAY "ressources/how_to_play.png"
    #define COIN50 "ressources/50.png"
    #define COIN100 "ressources/100.png"
    #define COIN150 "ressources/150.png"
    #define COIN250 "ressources/250.png"
    #define MONEY_SOUND "ressources/money_sound.ogg"
    #define WIN_SCREEN "ressources/win_screen.png"
    #define LOSE_SCREEN "ressources/lose_screen.png"
    #define SKIP "ressources/skip.png"

    #define SIMPLE "ressources/simple.png"
    #define MEDIUM "ressources/medium.png"
    #define ADVANCED "ressources/advanced.png"
    #define HARDCORE "ressources/hardcore.png"

    #define ERROR_FILE "Error in files of ressources.\n"

    #include <stdio.h>
    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Vector3.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Joystick.h>
    #include <SFML/Window/Keyboard.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Sensor.h>
    #include <SFML/Audio.h>
    #include "lib.h"

typedef struct scene {
    sfSprite **sprite;
    sfTexture **texture;
    sfVector2f **pos;
    sfIntRect **rect;
} scene_t;

typedef struct basement {
    sfTexture *texture;
    sfTexture *texture_indicator;
    sfSprite *basement_indicator;
    sfSprite **basement;
    int *boolean;
} basement_t;

typedef struct hardcore_tower {
    sfSprite **tower;
    sfTexture *texture;
    sfCircleShape **circle;
    int *boolean;
} hardcore_tower_t;

typedef struct advanced_tower {
    sfSprite **tower;
    sfTexture *texture;
    sfCircleShape **circle;
    int *boolean;
} advanced_tower_t;

typedef struct medium_tower {
    sfSprite **tower;
    sfTexture *texture;
    sfCircleShape **circle;
    int *boolean;
} medium_tower_t;

typedef struct simple_tower {
    sfSprite **tower;
    sfTexture *texture;
    sfCircleShape **circle;
    int *boolean;
} simple_tower_t;

typedef struct price_towers {
    sfSprite *coin_fifty;
    sfTexture *coin_fifty_tex;
    sfSprite *coin_hundred;
    sfTexture *coin_hundred_tex;
    sfSprite *coin_hundred_fifty;
    sfTexture *coin_hundred_fifty_tex;
    sfSprite *coin_two_hundred_fifty;
    sfTexture *coin_two_hundred_fifty_tex;
} price_towers_t;

typedef struct towers {
    simple_tower_t *simple_tower;
    medium_tower_t *medium_tower;
    advanced_tower_t *advanced_tower;
    hardcore_tower_t *hardcore_tower;
    sfClock *timer_rect;
    int show_circle;
} towers_t;

typedef struct game_info {
    sfSprite *win_status;
    sfTexture *win_status_tx;
    sfSprite *lose_status;
    sfTexture *lose_status_tx;
    sfSprite *skip_sprite;
    sfTexture *skip_texture;
    sfText *money_number;
    sfClock *shooter;
    sfClock *timer_score;
    sfClock *timer_enemies;
    sfClock *timer_rect_money;
    sfText **text_life;
    sfText *timmmer;
    sfText *text;
    sfFont *font;
    sfClock *timer_screen_status;
    int skip;
    int life;
    int score;
    float fps;
    int money;
    int win_or_lose;
    int *life_enemies;
    int *enemies_bool;
    int rect_bool;
} game_info_t;

typedef struct data {
    sfRenderWindow *window;
    sfSprite *how_to_play;
    sfTexture *how_to_play_t;
    sfSound *sound_play_button;
    sfSound *reload;
    sfSoundBuffer *click;
    sfSoundBuffer *reloading;
    scene_t **scene;
    towers_t *towers;
    basement_t *basement;
    price_towers_t *price;
    sfClock *global_timer;
    sfClock *timer;
    sfMusic *music;
    sfSprite *money;
    game_info_t *game_info;
    sfTime time;
    sfFont *font;
    sfText *text;
    sfSound *sound_play;
    sfSoundBuffer *buffer_sound_play;
    sfMusic *music_game;
    sfSprite *fps_60;
    sfSprite *fps_120;
    sfSound *money_sound;
    sfSoundBuffer *coins_fubb;
    int settings_two;
    int shooted;
    int game_bool;
    int error;
    int *list_scenes;
    int scene_on;
    int helper;
    int settings;
    int pause_two;
} data_t;

int check_skip_button(data_t *data, sfVector2f pos);
int init_skip_button(data_t *data);
int change_status(data_t *data, int win_or_lose);
int draw_status(data_t *data);
int destroy_game_status(data_t *data);
int init_game_status(data_t *data);
int check_game_status(data_t *data);
sfFloatRect get_circle(int tower_nbr, int y, data_t *data);
sfVector2f check_tower_end_life(data_t *data, int i, sfVector2f pos,
                                    sfSprite *sprite);
int check_damage(data_t *data);
int move_rect_towers(data_t *data);
int destroy_sound(data_t *data);
int change_money(data_t *data, int tower);
int money_sound(data_t *data);
int check_circle_hide(data_t *data);
int change_circle_pos(data_t *data, sfSprite *basement, int circle, int i);
int change_rotation(sfSprite *sprite, sfSprite *sprite_basement,
    int basement_selected);
int hide_arrow(data_t *data, int contains);
int draw_info_towers(data_t *data);
int set_pos(float x, float y, sfSprite *sprite);
int init_info_towers_sprites(data_t *data);
int init_chest(data_t *data);
int check_click_towers(data_t *data, sfVector2f pos);
int init_hardcore_tower(data_t *data);
int init_advanced_tower(data_t *data);
int init_medium_tower(data_t *data);
int init_simple_towers(data_t *data);
int draw_towers(data_t *data);
int init_towers(data_t *data);
int unpause(data_t *data);
int on_pause(data_t *data);
int settings_menu_two(data_t *data);
sfSprite *create_basement(sfTexture *texture, int x, int y, int pos_bool);
int init_fps_sprite(data_t *data);
int settings_menu(data_t *data);
char *convert_int(int nb);
int create_sound(char const *filepath, sfSound *sound, sfSoundBuffer *buffer);
int my_defender(int argc, char **argv);
int check_env(char **env);
sfSprite *create_sprite(char *path, int x, int y, int pos_bool);
int analyse_events(data_t *data);
int scene1(data_t *data);
int destroy_info_towers_sprites(data_t *data);
int check_click_basement(data_t *data, sfVector2f pos, sfFloatRect rect);
int init_basement_sprite(data_t *data);
int init_sprites_two(data_t *data);
int init_money_sprite(data_t *data);
int destroy(data_t *data, int close);
int draw(data_t *data);
int draw_basement(data_t *data);
int init(data_t *data);
int create_window(data_t *data);
int create_music(data_t *data);
int init_sprites(data_t *data);
int set_scale(float x, float y, sfSprite *sprite);
int check_scene_one(data_t *data, int nbr_scene);
int check_scene_two(data_t *data);
int scene_two(data_t *data);
int pause_space_button(data_t *data, sfEvent event);
void move_rect(sfSprite *sprite, int offset, int max_value);
int move_money_rect(data_t *data);
int move_objects(data_t *data, sfClock *clock);
int move_enemies_position(data_t *data, int i, int speed);
int move_enemies_life(data_t *data, int text_life_idx, int idx_sprite);
int move_enemies_rect(data_t *data);
int update_score(data_t *data);
int init_sprites_life(data_t *data, int nbr_enemies);
int chest_helper(data_t *data);
int check_pause_sprite_click(data_t *data, sfVector2f pos);
int show_settings(data_t *data);
int call_pause(data_t *data);
int money(data_t *data);
int draw_pause(data_t *data);
int set_basement_position(data_t *data);
int destroy_towers(data_t *data);
sfSprite *create_towers(sfTexture *texture, int x, int y, sfIntRect rect);

#endif
