/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner
*/

#include "defender.h"

void load_menu(game_t *game, back_t *back, button_t *button)
{
    init_button(button);
    init_backgrounds(back);
    init_window_element(game, false);
}

void pause_menu(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->my_defender);

    if (game->status == PAUSE) {
        sfRenderWindow_drawSprite(game->my_defender, game->pause, NULL);
        if (mouse_pos.x >= 760 && mouse_pos.x <= 1131 && mouse_pos.y >= 325
        && mouse_pos.y <= 475 && sfMouse_isButtonPressed(sfMouseLeft) == true)
            game->status = LEVEL1;
        if (mouse_pos.x >= 760 && mouse_pos.x <= 1131 && mouse_pos.y >= 528
            && mouse_pos.y <= 660 &&
            sfMouse_isButtonPressed(sfMouseLeft) == true)
            game->status = START_MENU;
        if (mouse_pos.x >= 760 && mouse_pos.x <= 1131 && mouse_pos.y >= 719
            && mouse_pos.y <= 856 &&
            sfMouse_isButtonPressed(sfMouseLeft) == true)
            sfRenderWindow_close(game->my_defender);
    }
    if (mouse_pos.x >= 750 && mouse_pos.x <= 1185 && mouse_pos.y >= 50
        && mouse_pos.y <= 217 && sfMouse_isButtonPressed(sfMouseLeft) == true
        && game->status == START_MENU)
            game->status = HELP;
}

void win_loose_game(game_t *game)
{
    sfVector2f postext = {900, 100};

    if (game->status == WIN) {
        sfRenderWindow_drawSprite(game->my_defender, game->win, NULL);
        sfText_setPosition(game->wave, postext);
        sfText_setString(game->wave, my_itoa(game->is_start));
        sfRenderWindow_drawText(game->my_defender, game->wave, NULL);
    }
    if (game->status == LOOSE) {
        sfRenderWindow_drawSprite(game->my_defender, game->loose, NULL);
        sfText_setPosition(game->wave, postext);
        sfText_setString(game->wave, my_itoa(game->is_start));
        sfRenderWindow_drawText(game->my_defender, game->wave, NULL);
    }
}

void do_loop_will_window_is_open(game_t *game, button_t *button,
back_t *back, tower_t *tower)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    while (sfRenderWindow_isOpen(game->my_defender)) {
        sfRenderWindow_clear(game->my_defender, sfBlack);
        set_volumne(button, game);
        level(game, back, tower, enemy);
        pause_menu(game);
        win_loose_game(game);
        manage_event(game, button, tower);
        draw_sprite(game, back, button);
        drawSprite(game->my_defender, game->cursor, NULL);
        sfRenderWindow_display(game->my_defender);
    }
}

int my_defender(void)
{
    game_t *game = malloc(sizeof(game_t));
    back_t *back = malloc(sizeof(back_t));
    button_t *button = malloc(sizeof(button_t));
    button_select_t *select_button = malloc(sizeof(button_select_t));
    tower_t *tower = malloc(sizeof(tower_t));

    memset(tower, 0, sizeof(tower_t));
    init_level_select(back);
    load_menu(game, back, button);
    if (handle_error() == EXIT_ERROR)
        return EXIT_ERROR;
    do_loop_will_window_is_open(game, button, back, tower);
    destroy_window(game, button, select_button, back);
    free(game);
    free(back);
    free(button);
    free(select_button);
    return EXIT_SUCCESS;
}
