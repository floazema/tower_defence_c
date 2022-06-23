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
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>
#include "../lib/my/my.h"
#include "struct.h"
#include <string.h>

#ifndef _DEFENDER_
    #define _DEFENDER_
    #define EXIT_ERROR 84
    #define EXIT_HELPER 1
    #define drawSprite sfRenderWindow_drawSprite
    #define createFromFile sfTexture_createFromFile
    #define PART1 1600
    #define TOWER_RANGE 250
    #define PART2 1505
    #define PART3 1300
    #define PART4 1070
    #define PART5 795
    #define PART6 600
    #define PART7 100
        void init_window_element(game_t *game, bool);
        void init_backgrounds(back_t *back);
        void init_button(button_t *button);
        void manage_event(game_t *game, button_t *button, tower_t *tower);
        void move_cursor(game_t *game);
        void change_status(button_t *button, game_t *game);
        void scale_button(button_t *button, game_t *game);
        void set_volumne(button_t *button, game_t *game);
        void init_level_select(back_t *back);
        void create_sprite(char *path, sfSprite **sprite, sfTexture **texture,
        sfVector2f *basepos);
        int handle_error();
        void glow_base(game_t *game, tower_t *tower);
        void change_status_level(game_t *game);
        void level(game_t *game, back_t *, tower_t *tower, enemy_t *enemy);
        void destroy_window(game_t *game, button_t *button,
        button_select_t *select_button, back_t *back);
        void build_towers(game_t *game, tower_t *tower);
        void draw_tower(game_t *game, tower_t *tower, enemy_t *enemy);
        void set_pos(tower_t *tower);
        void set_pos2(tower_t *tower);
        void start_wave(game_t *game);
        void create_text(game_t *game);
        void create_scene(game_t *game, tower_t *tower, back_t *back);
        sfIntRect select_rect(sfIntRect rect);
        void gold_life_init(game_t *game);
        int my_defender(void);
        void set_volumne(button_t *button, game_t *game);
        void mov_enemy();
        void sell(game_t *game, tower_t *tower, sfVector2f select_pos,
        sfVector2i mouse_pos);
        void upgrade(game_t *game, tower_t *tower, sfVector2f select_pos,
        sfVector2i mouse_pos);
        void fire_shoot_calc(tower_t *tower, int i, enemy_t *enemy);
        void touch_arrow(tower_t *tower, int i, enemy_t *enemy);
        void touch_fire(tower_t *tower, int i, enemy_t *enemy);
        void arrow_shoot(game_t *game, tower_t *tower, int i, enemy_t *enemy);
        void fire_shoot(game_t *game, tower_t *tower, int i, enemy_t *enemy);
        void draw_archer(game_t *game, tower_t *tower,
        sfVector2f select_pos, int i);
        void draw_magic(game_t *game, tower_t *tower,
        sfVector2f select_pos, int i);
        void draw_bomb(game_t *game, tower_t *tower,
        sfVector2f select_pos, int i);
        void draw_arcx(game_t *game, tower_t *tower,
        sfVector2f select_pos, int i);
        void arrow_shoot_calc(tower_t *tower, int i, enemy_t *enemy);
        sfIntRect tower_rect(sfIntRect rect);
        sfIntRect select_rect(sfIntRect rect);
        void load_b(game_t *game, tower_t *tower);
#endif
