/*
** EPITECH PROJECT, 2021
** mystruct
** File description:
** struct init
*/

#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>

#ifndef __MY_STRUCT__
    #define __MY_STRUCT__
        enum game_status_s {
            START_MENU,
            OPTIONS,
            LEVEL_SELECT,
            LEVEL1,
            LEVEL2,
            LEVEL3,
            PAUSE,
            WIN,
            LOOSE,
            HELP,
        };
        typedef struct game_s {
            sfRenderWindow *my_defender;
            sfSprite *cursor;
            sfTexture *texture_cursor;
            sfSprite *start_wave;
            sfTexture *texture_help;
            sfSprite *help;
            sfTexture *texture_start_wave;
            sfTexture *texture_pause;
            sfSprite *win, *loose, *pause;
            sfTexture *texture_win;
            sfTexture *texture_loose;
            sfMusic *music_my_defender, *hogs;
            enum game_status_s status;
            sfClock *goldc;
            sfTime goldt;
            sfFont *font;
            sfText *money, *life_point, *wave;
            int isplay, life, difficulty, gold, is_start;
            float seconds;
        } game_t;
        typedef struct background_s {
            sfSprite *start_back;
            sfTexture *texture_start_back;
            sfSprite *map1_back;
            sfTexture *texture_map1_back;
            sfSprite *option_back;
            sfTexture *texture_option_back;
            sfSprite *level_select;
            sfTexture *texture_level_select;
        } back_t;
        typedef struct buttons_select_s {
            sfSprite *select_lvl1;
            sfTexture *texture_select_lvl1;
            sfSprite *select_lvl2;
            sfTexture *texture_select_lvl2;
            sfSprite *select_lvl3;
            sfTexture *texture_select_lvl3;
        } button_select_t;
        typedef struct tower_s {
            sfVector2f arrow_pos[550];
            sfTexture *texture_glow, *texture_magic, *texture_bomb;
            sfSprite *select, *arrow, *fire, *archer, *magic;
            sfTexture *texture_arrow, *texture_fire, *texture_select;
            sfTexture *texture_archer;
            sfSprite *bomb, *arcx, *glow;
            sfTexture *texture_arcx;
            sfIntRect serect;
            int is_shoot[550], up_tab[360], tower_pos[550], glow_pos[36];
            int to_up, is_select, i, pos;
            sfIntRect bowrect;
            sfClock *shootc, *firec;
            sfTime shoott, firet;
            float shoot_sec, fire_sec;
            sfClock *arrowc[550];
            sfTime arrowt[550];
            float arrow_sec[550], magic_sec[550];
            sfClock *magicc[550];
            sfTime magict[550];
        } tower_t;
        typedef struct buttons_s {
            sfIntRect music_rect;
            sfSprite *sound_logo;
            sfSprite *music_logo;
            sfTexture *texture_sound_logo;
            sfTexture *texture_music_logo;
            sfSprite *start;
            sfTexture *texture_start;
            sfSprite *quit;
            sfTexture *texture_quit;
            sfSprite *option;
            sfSprite *sound_bar;
            sfSprite *music_bar;
            sfTexture *texture_progress_bar;
            sfTexture *texture_option;
        } button_t;
        typedef struct create_enemy_s {
            sfSprite *s;
            sfVector2f posi;
            sfIntRect rect;
            sfIntRect s_rect;
        } create_enemy_t;
        typedef struct enemy_s {
            create_enemy_t *enemy;
            sfSprite *knight, *hog, *health;
            sfTexture *texture_hog, *texture_health, *texture_knight;
            sfSprite *tab_knight[100];
            sfSprite *tab_hog[100];
            sfVector2f knight_pos[200];
            sfVector2f hog_pos[199];
            double life_e[65];
            sfClock *knightc, *knightmc;
            sfTime knightt, knightmt;
            float knight_sec, hog_sec, anim_hsec, anim_ksec;
            sfIntRect knightrect;
            sfClock *hogc;
            sfTime hogt;
            sfClock *hogmc;
            sfTime hogmt;
            sfIntRect hogrect;
            sfIntRect healthrect;
        } enemy_t;
#endif
