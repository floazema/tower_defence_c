/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner
*/

#include "defender.h"

void move_cursor(game_t *game)
{
    sfVector2i vector = sfMouse_getPositionRenderWindow(game->my_defender);
    sfVector2f cursor_pos;
    int reajust_cursor_x = 5;
    int reajust_cursor_y = 3;

    vector.x -= reajust_cursor_x;
    vector.y -= reajust_cursor_y;
    cursor_pos = (sfVector2f){vector.x, vector.y};
    sfSprite_setPosition(game->cursor, cursor_pos);
}

void manage_event(game_t *game, button_t button)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->my_defender, &event)) {
        move_cursor(game);
        if (event.type == sfEvtClosed || event.key.code == sfKeyQ)
            sfRenderWindow_close(game->my_defender);
        if (event.type == sfEvtMouseMoved)
            scale_button(button, game);
        if (event.type == sfEvtMouseButtonPressed)
            change_status(button, game);
    }
}
