/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner
*/

#include "defender.h"

void draw_cursor(game_t game)
{
    sfVector2i vector;
    sfVector2f cursor_pos;

    vector = sfMouse_getPositionRenderWindow(game.my_defender);
    vector.x -= 5;
    vector.y -= 3;
    cursor_pos = (sfVector2f){vector.x, vector.y};
    sfSprite_setPosition(game.cursor, cursor_pos);
    sfRenderWindow_drawSprite(game.my_defender, game.cursor, NULL);
}

void draw_sprite(game_t game, back_t back)
{
    sfRenderWindow_drawSprite(game.my_defender, back.start_back, NULL);
    draw_cursor(game);
}

int main(int argc, char **argv)
{
    game_t game;
    back_t back;

    init_backgrounds(&back);
    init_window_element(&game);
    if (handle_error(argc, argv) == 84)
        return 84;
    while (sfRenderWindow_isOpen(game.my_defender)) {
        sfRenderWindow_clear(game.my_defender, sfBlack);
        manage_event(&game);
        draw_sprite(game, back);
        sfRenderWindow_display(game.my_defender);
    }
}
