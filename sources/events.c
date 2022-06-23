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
    cursor_pos = (sfVector2f) {vector.x, vector.y};
    sfSprite_setPosition(game->cursor, cursor_pos);
}

void create_window_fullscreen(game_t *game)
{
    static bool isFull = false;

    if (isFull == false) {
        init_window_element(game, true);
        isFull = true;
    } else {
        init_window_element(game, false);
        isFull = false;
    }
}

void manage_event_level_selection(sfEvent event, game_t *game,
tower_t *tower, button_t *button)
{
    if (event.type == sfEvtMouseButtonPressed && game->status == LEVEL1)
        build_towers(game, tower);
    move_cursor(game);
    if (event.type == sfEvtMouseMoved && game->status == START_MENU)
        scale_button(button, game);
    if (event.type == sfEvtMouseButtonReleased &&
    game->status == START_MENU)
        change_status(button, game);
    if (event.type == sfEvtMouseButtonPressed &&
    game->status == LEVEL_SELECT)
        change_status_level(game);
    if (event.key.code == sfKeyEscape && ((game->status == LEVEL_SELECT)
    || game->status == OPTIONS || game->status == HELP))
        game->status = START_MENU;
    if (event.key.code == sfKeyEscape && game->status == LEVEL1)
        game->status = PAUSE;
}

void manage_event(game_t *game, button_t *button, tower_t *tower)
{
    sfEvent event;

    memset(&event, 0, sizeof(sfEvent));
    while (sfRenderWindow_pollEvent(game->my_defender, &event)) {
        if (event.type == sfEvtClosed || event.key.code == sfKeyQ)
            sfRenderWindow_close(game->my_defender);
        manage_event_level_selection(event, game, tower, button);
        if (event.type == sfEvtMouseButtonPressed && tower->is_select == 1) {
            tower->is_select = 0;
            tower->serect.left = 0;
            sfSprite_setTextureRect(tower->select, tower->serect);
        }
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyF11) {
            sfRenderWindow_destroy(game->my_defender);
            sfMusic_destroy(game->music_my_defender);
            create_window_fullscreen(game);
        }
    }
}
