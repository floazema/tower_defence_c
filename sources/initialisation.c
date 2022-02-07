/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner
*/

#include "defender.h"

int handle_error()
{
    return 0;
}

void init_window(game_t *game)
{
    sfVideoMode mode = {1920, 1080, 32};
    game->my_defender = sfRenderWindow_create
    (mode, "My_defender", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->my_defender, 60);
}