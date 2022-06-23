/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-florian.azema
** File description:
** init_button
*/

#include "defender.h"

static const int buttons_x = 1200;
static const int start_button_y = 200;
static const int quit_button_y = 450;
static const int option_button_y = 700;
static const int sound_music_x = 1210;
static const int sound_y = 550;
static const int music_y = 400;
static const int bar_x = 610;
static const int sound_bar_y = 575;
static const int music_bar_y = 427;

void button_initialization(button_t *button)
{
    sfVector2f music_pos = {sound_music_x, music_y};
    sfVector2f music_bar_pos = {bar_x, music_bar_y};
    sfVector2f sound_bar_pos = {bar_x, sound_bar_y};

    create_sprite("assets/music_logo.png", &button->music_logo,
    &button->texture_music_logo, &music_pos);
    create_sprite("assets/progress_bar.png", &button->sound_bar,
    &button->texture_progress_bar, &sound_bar_pos);
    create_sprite("assets/progress_bar.png", &button->music_bar,
    &button->texture_progress_bar, &music_bar_pos);
}

void init_button(button_t *button)
{
    sfVector2f start_pos = {buttons_x, start_button_y};
    sfVector2f quit_pos = {buttons_x, quit_button_y};
    sfVector2f option_pos = {buttons_x, option_button_y};
    sfVector2f sound_pos = {sound_music_x, sound_y};

    create_sprite("assets/start.png", &button->start,
    &button->texture_start, &start_pos);
    create_sprite("assets/quit.png", &button->quit,
    &button->texture_quit, &quit_pos);
    create_sprite("assets/option.png", &button->option,
    &button->texture_option, &option_pos);
    create_sprite("assets/sound_logo.png", &button->sound_logo,
    &button->texture_sound_logo, &sound_pos);
    button_initialization(button);
    button->music_rect.top = 0;
    button->music_rect.left = 0;
    button->music_rect.width = 650;
    button->music_rect.height = 20;
}
