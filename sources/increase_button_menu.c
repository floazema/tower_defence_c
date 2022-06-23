/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-florian.azema
** File description:
** increase_button
*/

#include "defender.h"

static const float upscaled_button = 1.2;
static const int default_size = 1;

void increase_start(button_t *button, game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->my_defender);
    sfVector2f start_pos = sfSprite_getPosition(button->start);
    sfVector2f increase_button_size = {upscaled_button, upscaled_button};
    sfVector2f decrease_button_size = {default_size, default_size};
    int buttons_length = 450;
    int start_button_height = 180;

    if (mouse_pos.x >= start_pos.x && mouse_pos.x
    <= start_pos.x + buttons_length && mouse_pos.y >=
    start_pos.y && mouse_pos.y <= start_pos.y + start_button_height)
        sfSprite_setScale(button->start, increase_button_size);
    else
        sfSprite_setScale(button->start, decrease_button_size);
}

void increase_quit(button_t *button, game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->my_defender);
    sfVector2f quit_pos = sfSprite_getPosition(button->quit);
    sfVector2f increase_button_size = {upscaled_button, upscaled_button};
    sfVector2f decrease_button_size = {default_size, default_size};
    int buttons_length = 450;
    int quit_button_height = 180;

    if (mouse_pos.x >= quit_pos.x && mouse_pos.x
    <= quit_pos.x + buttons_length && mouse_pos.y >=
    quit_pos.y && mouse_pos.y <= quit_pos.y + quit_button_height)
        sfSprite_setScale(button->quit, increase_button_size);
    else
        sfSprite_setScale(button->quit, decrease_button_size);
}

void increase_option(button_t *button, game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->my_defender);
    sfVector2f options_pos = sfSprite_getPosition(button->option);
    sfVector2f increase_button_size = {1.2, 1.2};
    sfVector2f decrease_button_size = {1, 1};
    int buttons_length = 450;
    int option_button_height = 180;

    if (mouse_pos.x >= options_pos.x && mouse_pos.x
    <= options_pos.x + buttons_length && mouse_pos.y >=
    options_pos.y && mouse_pos.y <= options_pos.y + option_button_height)
        sfSprite_setScale(button->option, increase_button_size);
    else
        sfSprite_setScale(button->option, decrease_button_size);
}

void scale_button(button_t *button, game_t *game)
{
    increase_start(button, game);
    increase_quit(button, game);
    increase_option(button, game);
}
