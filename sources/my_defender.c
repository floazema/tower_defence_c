/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner
*/

#include "defender.h"

int main(int argc, char **argv)
{
    game_t game;

    init_window(&game);
    if (handle_error(argc, argv) == 84)
        return 84;
    while (sfRenderWindow_isOpen(game.my_defender)) {
        sfRenderWindow_clear(game.my_defender, sfBlack);
        sfRenderWindow_display(game.my_defender);
    }
}
