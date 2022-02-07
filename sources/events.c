/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner
*/

#include "defender.h"

void manage_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->my_defender, &event)) {
        if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
            sfRenderWindow_close(game->my_defender);
    }
}