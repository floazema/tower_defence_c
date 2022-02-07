/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner
*/

#include "defender.h"

void draw_sprite(game_t game, back_t back, button_t button)
{
    if (game.game_status == 0) {
        sfRenderWindow_drawSprite(game.my_defender, back.start_back, NULL);
        sfRenderWindow_drawSprite(game.my_defender, button.start, NULL);
        sfRenderWindow_drawSprite(game.my_defender, button.quit, NULL);
    }
    sfRenderWindow_drawSprite(game.my_defender, game.cursor, NULL);
}

int main(int argc, char **argv)
{
    game_t game;
    back_t back;
    button_t button;

    init_button(&button);
    init_backgrounds(&back);
    init_window_element(&game);
    if (handle_error(argc, argv) == 84)
        return 84;
    while (sfRenderWindow_isOpen(game.my_defender)) {
        sfRenderWindow_clear(game.my_defender, sfBlack);
        manage_event(&game, button);
        draw_sprite(game, back, button);
        sfRenderWindow_display(game.my_defender);
    }
}
