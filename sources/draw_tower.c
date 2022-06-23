/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-florian.azema
** File description:
** draw_tower
*/

#include "defender.h"

void shoot(game_t *game, tower_t *tower, enemy_t *enemy, int i)
{
    if (tower->tower_pos[i + 2] == 1 || tower->tower_pos[i + 2] == 5 ||
    tower->tower_pos[i + 2] == 6)
        arrow_shoot(game, tower, i, enemy);
    if (tower->tower_pos[i + 2] == 2 || tower->tower_pos[i + 2] == 7 ||
    tower->tower_pos[i + 2] == 8)
        fire_shoot(game, tower, i, enemy);
}

void draw_tower(game_t *game, tower_t *tower, enemy_t *enemy)
{
    int i = 0;
    sfVector2f select_pos = sfSprite_getPosition(tower->select);
    for (i = 0; tower->pos > i; i += 3) {
        tower->arrowt[i] = sfClock_getElapsedTime(tower->arrowc[i]);
        tower->arrow_sec[i] = tower->arrowt[i].microseconds / 1000000.0;
    }
    select_pos.x += 25;
    for (i = 0; tower->pos > i; i += 3) {
        select_pos.x = tower->tower_pos[i];
        select_pos.y = tower->tower_pos[i + 1];
        draw_archer(game, tower, select_pos, i);
        draw_magic(game, tower, select_pos, i);
        draw_bomb(game, tower, select_pos, i);
        draw_arcx(game, tower, select_pos, i);
        shoot(game, tower, enemy, i);
    }
}
