/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-florian.azema
** File description:
** increase_button
*/

#include "defender.h"

void up_bomb(tower_t *tower, game_t *game, int i)
{
    if (tower->tower_pos[i + 1] == 3 && game->gold >= 190) {
        game->gold -= 190;
        tower->tower_pos[i + 1] = 11;
    } else if (tower->tower_pos[i + 1] == 11 && game->gold >= 275) {
        game->gold -= 275;
        tower->tower_pos[i + 1] = 12;
    }
}

void up_archer(tower_t *tower, game_t *game, int i)
{
    if (tower->tower_pos[i + 1] == 1 && game->gold >= 110) {
        game->gold -= 110;
        tower->tower_pos[i + 1] = 5;
    } else if (tower->tower_pos[i + 1] == 5 && game->gold >= 150) {
        game->gold -= 150;
        tower->tower_pos[i + 1] = 6;
    }
}

void up_magic(tower_t *tower, game_t *game, int i)
{
    if (tower->tower_pos[i + 1] == 2 && game->gold >= 140) {
        game->gold -= 140;
        tower->tower_pos[i + 1] = 7;
    } else if (tower->tower_pos[i + 1] == 7 && game->gold >= 190) {
        game->gold -= 190;
        tower->tower_pos[i + 1] = 8;
    }
}

void up_arcx(tower_t *tower, game_t *game, int i)
{
    if (tower->tower_pos[i + 1] == 4 && game->gold >= 210) {
        game->gold -= 210;
        tower->tower_pos[i + 1] = 9;
    } else if (tower->tower_pos[i + 1] == 9 && game->gold >= 300) {
        game->gold -= 300;
        tower->tower_pos[i + 1] = 10;
    }
}

void upgrade(game_t *game, tower_t *tower, sfVector2f select_pos,
sfVector2i mouse_pos)
{
    int i = 0;

    if (tower->is_select == 1 && mouse_pos.x >=
    select_pos.x + 80 && mouse_pos.x
    <= select_pos.x + 120 && mouse_pos.y >=
    select_pos.y && mouse_pos.y <= select_pos.y + 40) {
        for (i = 0; tower->tower_pos[i] != select_pos.y; i++);
        up_archer(tower, game, i);
        up_bomb(tower, game, i);
        up_magic(tower, game, i);
        up_arcx(tower, game, i);
    }
}
