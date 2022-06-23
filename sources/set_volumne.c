/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-florian.azema
** File description:
** set_volumne
*/

#include "defender.h"

static const int music_y = 400;

sfVector2f set_volumne_marvin(sfVector2i mouse_pos, sfVector2f move_music,
float volumne)
{
    if (mouse_pos.x <= 650)
        move_music.x = 650;
    if (mouse_pos.x >= 1250) {
        move_music.x = 1250;
        volumne = 100;
    }
    if (volumne < 0)
        volumne = 0;
    return (move_music);
}

void set_volumne(button_t *button, game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->my_defender);
    sfVector2f music_logo_pos = sfSprite_getPosition(button->music_logo);
    sfVector2f move_music = {mouse_pos.x, music_y};
    int buttons_size = 80;
    float volumne = 0;

    if (mouse_pos.x >= music_logo_pos.x && mouse_pos.x
    <= music_logo_pos.x + buttons_size && mouse_pos.y >=
    music_logo_pos.y && mouse_pos.y <= music_logo_pos.y + buttons_size
    && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        volumne = (music_logo_pos.x - 650) / 6;
        move_music = set_volumne_marvin(mouse_pos, move_music, volumne);
        move_music.x -= 40;
        sfSprite_setPosition(button->music_logo, move_music);
        button->music_rect.width = music_logo_pos.x - 600;
        sfMusic_setVolume(game->music_my_defender, volumne);
    }
}
