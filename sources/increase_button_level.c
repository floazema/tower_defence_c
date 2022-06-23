/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-florian.azema
** File description:
** increase_button_level
*/

#include "defender.h"

void status_lvl1(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->my_defender);
    sfVector2f lvl_pos = {230, 235};
    int buttons_length = 445;
    int start_button_height = 540;

    if (mouse_pos.x >= lvl_pos.x && mouse_pos.x
    <= lvl_pos.x + buttons_length && mouse_pos.y >=
    lvl_pos.y && mouse_pos.y <= lvl_pos.y + start_button_height) {
        game->difficulty = 1;
        game->status = LEVEL1;
    }
}

void status_lvl2(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->my_defender);
    sfVector2f lvl_pos = {735, 235};
    int buttons_length = 445;
    int start_button_height = 540;

    if (mouse_pos.x >= lvl_pos.x && mouse_pos.x
    <= lvl_pos.x + buttons_length && mouse_pos.y >=
    lvl_pos.y && mouse_pos.y <= lvl_pos.y + start_button_height) {
        game->difficulty = 2;
        game->status = LEVEL1;
    }
}

void status_lvl3(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->my_defender);
    sfVector2f lvl_pos = {1245, 235};
    int buttons_length = 445;
    int start_button_height = 540;

    if (mouse_pos.x >= lvl_pos.x && mouse_pos.x
    <= lvl_pos.x + buttons_length && mouse_pos.y >=
    lvl_pos.y && mouse_pos.y <= lvl_pos.y + start_button_height) {
        game->difficulty = 3;
        game->status = LEVEL1;
    }
}

void change_status_level(game_t *game)
{
    if (game->status == LEVEL_SELECT) {
        status_lvl1(game);
        status_lvl2(game);
        status_lvl3(game);
    }
}
