/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-florian.azema
** File description:
** increase_button
*/

#include "defender.h"

void set_pos(tower_t *tower)
{
    tower->glow_pos[18] = 197;
    tower->glow_pos[19] = 864;
    tower->glow_pos[20] = 372;
    tower->glow_pos[21] = 859;
    tower->glow_pos[22] = 745;
    tower->glow_pos[23] = 750;
    tower->glow_pos[24] = 790;
    tower->glow_pos[25] = 599;
    tower->glow_pos[26] = 859;
    tower->glow_pos[27] = 481;
    tower->glow_pos[28] = 945;
    tower->glow_pos[29] = 604;
    tower->glow_pos[30] = 1008;
    tower->glow_pos[31] = 751;
    tower->glow_pos[32] = 1285;
    tower->glow_pos[33] = 843;
    tower->glow_pos[34] = 1513;
    tower->glow_pos[35] = 815;
}

void set_pos2(tower_t *tower)
{

    tower->glow_pos[0] = 218;
    tower->glow_pos[1] = 617;
    tower->glow_pos[2] = 406;
    tower->glow_pos[3] = 611;
    tower->glow_pos[4] = 473;
    tower->glow_pos[5] = 438;
    tower->glow_pos[6] = 581;
    tower->glow_pos[7] = 297;
    tower->glow_pos[8] = 870;
    tower->glow_pos[9] = 241;
    tower->glow_pos[10] = 1088;
    tower->glow_pos[11] = 276;
    tower->glow_pos[12] = 1263;
    tower->glow_pos[13] = 414;
    tower->glow_pos[14] = 1303;
    tower->glow_pos[15] = 577;
    tower->glow_pos[16] = 1672;
    tower->glow_pos[17] = 467;
}

void base_select(tower_t *tower, sfVector2f to_glow, int i)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == true) {
        to_glow.x -= 25;
        to_glow.y -= 40;
        sfSprite_setPosition(tower->select, to_glow);
        tower->is_select = 1;
        tower->to_up = i;
        if (tower->up_tab[i] == 1) {
            tower->serect.left = 200;
            sfSprite_setTextureRect(tower->select, tower->serect);
        }
    }
}

void start_wave(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->my_defender);
    int buttons_length = 80;

    sfRenderWindow_drawSprite(game->my_defender, game->start_wave, NULL);
    if (mouse_pos.x >= 1750 && mouse_pos.x
    <= 1750 + buttons_length && mouse_pos.y >=
    335 && mouse_pos.y <= 335 + buttons_length &&
    sfMouse_isButtonPressed(sfMouseLeft) == true) {
        game->is_start = 1;
    }
}

void glow_base(game_t *game, tower_t *tower)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->my_defender);
    int buttons_length = 120;
    int start_button_height = 90;

    for (int i = 0; i < 35; i += 2) {
        if (mouse_pos.x >= tower->glow_pos[i] && mouse_pos.x
        <= tower->glow_pos[i] + buttons_length &&
        mouse_pos.y >= tower->glow_pos[i + 1] + 20
        && mouse_pos.y <= tower->glow_pos[i + 1] + start_button_height) {
            sfVector2f to_glow = {tower->glow_pos[i], tower->glow_pos[i + 1]};
            sfSprite_setPosition(tower->glow, to_glow);
            sfRenderWindow_drawSprite(game->my_defender, tower->glow, NULL);
            base_select(tower, to_glow, i);
            tower->i = i;
        }
    }
}
