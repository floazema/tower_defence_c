/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner
*/

#include "defender.h"

void scale_button(button_t button, game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->my_defender);
    sfVector2f start_pos = sfSprite_getPosition(button.start);
    sfVector2f quit_pos = sfSprite_getPosition(button.quit);
    sfVector2f increase_button_size = {1.2, 1.2};
    sfVector2f decrease_button_size = {1, 1};
    int buttons_length = 450;
    int start_button_height = 225;
    int quit_button_height = 125;

    if (mouse_pos.x >= start_pos.x && mouse_pos.x
    <= start_pos.x + buttons_length && mouse_pos.y >=
    start_pos.y && mouse_pos.y <= start_pos.y + start_button_height)
        sfSprite_setScale(button.start, increase_button_size);
    else
        sfSprite_setScale(button.start, decrease_button_size);
    if (mouse_pos.x >= quit_pos.x && mouse_pos.x
    <= start_pos.x + buttons_length && mouse_pos.y >=
    quit_pos.y && mouse_pos.y <= quit_pos.y + quit_button_height)
        sfSprite_setScale(button.quit, increase_button_size);
    else
        sfSprite_setScale(button.quit, decrease_button_size);
}

void change_status(button_t button, game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->my_defender);
    sfVector2f start_pos = sfSprite_getPosition(button.start);
    sfVector2f quit_pos = sfSprite_getPosition(button.quit);
    int buttons_length = 450;
    int start_button_height = 225;
    int quit_button_height = 125;

    if (mouse_pos.x >= start_pos.x && mouse_pos.x
    <= start_pos.x + buttons_length && mouse_pos.y >=
    start_pos.y && mouse_pos.y <= start_pos.y + start_button_height)
        game->game_status += 1;
    if (mouse_pos.x >= quit_pos.x && mouse_pos.x
    <= start_pos.x + buttons_length && mouse_pos.y >=
    quit_pos.y && mouse_pos.y <= quit_pos.y + quit_button_height) {
        sfMusic_destroy(game->music_my_defender);
        sfRenderWindow_close(game->my_defender);
    }
}
