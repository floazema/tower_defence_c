/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner
*/

#include "defender.h"

static const int window_height = 1080;
static const int window_width = 1920;
static const int bits_per_pixel = 32;

void create_sprite(char *path, sfSprite **sprite, sfTexture **texture,
sfVector2f *basepos)
{
    sfVector2f no_pos = {0, 0};

    *sprite = sfSprite_create();
    *texture = createFromFile(path, NULL);
    sfSprite_setTexture(*sprite, *texture, sfTrue);
    if (basepos == NULL) {
        sfSprite_setPosition(*sprite, no_pos);
    } else
        sfSprite_setPosition(*sprite, *basepos);
}

void init_backgrounds(back_t *back)
{
    create_sprite("assets/start_background.jpg", &back->start_back,
    &back->texture_start_back, NULL);
    create_sprite("assets/option_menu.png", &back->option_back,
    &back->texture_option_back, NULL);
}

void init_level_select(back_t *back)
{
    create_sprite("assets/select_difficulty.png", &back->level_select,
    &back->texture_level_select, NULL);
    create_sprite("assets/select_difficulty.png", &back->option_back,
    &back->texture_option_back, NULL);
}

void init_window_element(game_t *game, bool do_fullscreen)
{
    sfVideoMode mode = {window_width, window_height, bits_per_pixel};

    if (do_fullscreen == true)
        game->my_defender = sfRenderWindow_create
        (mode, "My_defender", sfClose, NULL);
    else
        game->my_defender = sfRenderWindow_create
        (mode, "My_defender", sfClose | sfFullscreen, NULL);
    sfRenderWindow_setMouseCursorVisible(game->my_defender, sfFalse);
    game->status = START_MENU;
    create_sprite("assets/cursor.png", &game->cursor,
    &game->texture_cursor, NULL);
    create_sprite("assets/help.png", &game->help,
    &game->texture_help, NULL);
    game->music_my_defender = sfMusic_createFromFile("assets/tds_ost.ogg");
    sfMusic_setLoop(game->music_my_defender, sfTrue);
    sfMusic_play(game->music_my_defender);
    game->difficulty = 0;
}
