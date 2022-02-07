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

void init_backgrounds(back_t *back)
{
    back->texture_start_back = sfTexture_createFromFile
    ("assets/start_background.jpg", NULL);
    back->start_back = sfSprite_create();
    sfSprite_setTexture(back->start_back, back->texture_start_back, sfTrue);
}

void init_button(button_t *button)
{
    sfVector2f start_pos = {100, 100};
    sfVector2f quit_pos = {100, 400};

    button->texture_start = sfTexture_createFromFile
    ("assets/start.png", NULL);
    button->start = sfSprite_create();
    sfSprite_setTexture(button->start, button->texture_start, sfTrue);
    sfSprite_setPosition(button->start, start_pos);
    button->texture_quit = sfTexture_createFromFile
    ("assets/quit.png", NULL);
    button->quit = sfSprite_create();
    sfSprite_setTexture(button->quit, button->texture_quit, sfTrue);
    sfSprite_setPosition(button->quit, quit_pos);
}

void init_window_element(game_t *game)
{
    sfVideoMode mode = {1920, 1080, 32};

    game->my_defender = sfRenderWindow_create
    (mode, "My_defender", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->my_defender, 60);
    sfRenderWindow_setMouseCursorVisible(game->my_defender, sfFalse);
    game->game_status = 0;
    game->texture_cursor = sfTexture_createFromFile
    ("assets/cursor.png", NULL);
    game->cursor = sfSprite_create();
    sfSprite_setTexture(game->cursor, game->texture_cursor, sfTrue);
}
