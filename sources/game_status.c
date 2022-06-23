/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner
*/

#include "defender.h"

void start_status(button_t *button, game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->my_defender);
    sfVector2f start_pos = sfSprite_getPosition(button->start);
    int buttons_length = 450;
    int start_button_height = 225;

    if (mouse_pos.x >= start_pos.x && mouse_pos.x
    <= start_pos.x + buttons_length && mouse_pos.y >=
    start_pos.y && mouse_pos.y <= start_pos.y + start_button_height)
        game->status = LEVEL_SELECT;
}

void quit_status(button_t *button, game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->my_defender);
    sfVector2f quit_pos = sfSprite_getPosition(button->quit);
    int buttons_length = 450;
    int quit_button_height = 125;

    if (mouse_pos.x >= quit_pos.x && mouse_pos.x
    <= quit_pos.x + buttons_length && mouse_pos.y >=
    quit_pos.y && mouse_pos.y <= quit_pos.y + quit_button_height) {
        sfMusic_destroy(game->music_my_defender);
        sfRenderWindow_close(game->my_defender);
    }
}

void option_status(button_t *button, game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->my_defender);
    sfVector2f option_pos = sfSprite_getPosition(button->option);
    int buttons_length = 450;
    int option_button_height = 225;

    if (mouse_pos.x >= option_pos.x && mouse_pos.x
    <= option_pos.x + buttons_length && mouse_pos.y >=
    option_pos.y && mouse_pos.y <= option_pos.y + option_button_height)
        game->status = OPTIONS;
}

void change_status(button_t *button, game_t *game)
{
    start_status(button, game);
    quit_status(button, game);
    option_status(button, game);
}
