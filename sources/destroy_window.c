/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-florian.azema
** File description:
** destroy_window
*/

#include "../include/defender.h"

void sprite_destroyer (game_t *game, button_t *button,
button_select_t *select_button, back_t *back)
{
    sfSprite_destroy(button->music_bar);
    sfSprite_destroy(button->music_logo);
    sfSprite_destroy(button->option);
    sfSprite_destroy(button->quit);
    sfSprite_destroy(button->sound_bar);
    sfSprite_destroy(button->sound_logo);
    sfSprite_destroy(button->start);
    sfSprite_destroy(select_button->select_lvl1);
    sfSprite_destroy(select_button->select_lvl2);
    sfSprite_destroy(select_button->select_lvl3);
    sfSprite_destroy(back->level_select);
    sfSprite_destroy(back->option_back);
    sfSprite_destroy(back->start_back);
    sfSprite_destroy(game->cursor);
}

void texture_destroyer (game_t *game, button_t *button,
button_select_t *select_button, back_t *back)
{
    sfTexture_destroy(button->texture_music_logo);
    sfTexture_destroy(button->texture_option);
    sfTexture_destroy(button->texture_progress_bar);
    sfTexture_destroy(button->texture_quit);
    sfTexture_destroy(button->texture_sound_logo);
    sfTexture_destroy(button->texture_start);
    sfTexture_destroy(select_button->texture_select_lvl1);
    sfTexture_destroy(select_button->texture_select_lvl2);
    sfTexture_destroy(select_button->texture_select_lvl3);
    sfTexture_destroy(back->texture_level_select);
    sfTexture_destroy(back->texture_option_back);
    sfTexture_destroy(back->texture_start_back);
    sfTexture_destroy(game->texture_cursor);
}

void destroy_window(game_t *game, button_t *button,
button_select_t *select_button, back_t *back)
{
    sfRenderWindow_destroy(game->my_defender);
    sfMusic_destroy(game->music_my_defender);
    sprite_destroyer(game, button, select_button, back);
    texture_destroyer(game, button, select_button, back);
}
