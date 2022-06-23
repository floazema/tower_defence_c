/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-florian.azema
** File description:
** increase_button
*/

#include "defender.h"

void sell_archer(tower_t *tower, game_t *game, int i)
{
    if (tower->tower_pos[i + 1] == 1)
        game->gold += 50;
    if (tower->tower_pos[i + 1] == 5)
        game->gold += 150;
    if (tower->tower_pos[i + 1] == 6)
        game->gold += 290;
}

void sell_arcx(tower_t *tower, game_t *game, int i)
{
    if (tower->tower_pos[i + 1] == 9)
        game->gold += 320;
    if (tower->tower_pos[i + 1] == 10)
        game->gold += 580;
    if (tower->tower_pos[i + 1] == 4)
        game->gold += 120;
}

void sell_magic(tower_t *tower, game_t *game, int i)
{
    if (tower->tower_pos[i + 1] == 2)
        game->gold += 80;
    if (tower->tower_pos[i + 1] == 7)
        game->gold += 190;
    if (tower->tower_pos[i + 1] == 8)
        game->gold += 310;
}

void sell_bomb(tower_t *tower, game_t *game, int i)
{
    if (tower->tower_pos[i + 1] == 3)
        game->gold += 100;
    if (tower->tower_pos[i + 1] == 11)
        game->gold += 290;
    if (tower->tower_pos[i + 1] == 12)
        game->gold += 480;
}

void sell(game_t *game, tower_t *tower, sfVector2f select_pos,
sfVector2i mouse_pos)
{
    int i = 0;

    if (tower->is_select == 1 && mouse_pos.x >= select_pos.x +
    80 && mouse_pos.x
    <= select_pos.x + 120 && mouse_pos.y >=
    select_pos.y + 135 && mouse_pos.y <= select_pos.y + 170 &&
    tower->up_tab[tower->to_up] > 0) {
        for (i = 0; tower->tower_pos[i] != select_pos.y; i++);
        sell_archer(tower, game, i);
        sell_magic(tower, game, i);
        sell_bomb(tower, game, i);
        sell_arcx(tower, game, i);
        tower->tower_pos[i + 1] = 0;
        tower->tower_pos[i] = 0;
        tower->tower_pos[i - 1] = 0;
        tower->up_tab[tower->to_up] = 0;
    }
}
