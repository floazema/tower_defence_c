/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** draw_tower2
*/

#include "defender.h"

void fire_shoot_calc(tower_t *tower, int i, enemy_t *enemy)
{
    double coef = 1, coef2 = 1, x = 0, y = 0;

    y = enemy->knight_pos[tower->is_shoot[i]].y - tower->arrow_pos[i + 2].y;
    x = enemy->knight_pos[tower->is_shoot[i]].x - tower->arrow_pos[i + 2].x;
    coef = (y / x);
    if (coef > 10 || coef < -10)
        coef2 = 0.1;
    if (coef > 30 || coef < -30)
        coef2 = 0.033;
    if (coef > 2 || coef < -2)
        coef2 = 0.5;
    if (x >= 0) {
        tower->arrow_pos[i + 2].y += coef * 0.07 * coef2;
        tower->arrow_pos[i + 2].x += 0.07 * coef2;
    } else {
        tower->arrow_pos[i + 2].y -= coef * 0.07 * coef2;
        tower->arrow_pos[i + 2].x -= 0.07 * coef2;
    }
    sfSprite_setPosition(tower->fire, tower->arrow_pos[i + 2]);
}

void touch_arrow(tower_t *tower, int i, enemy_t *enemy)
{
    tower->shoott = sfClock_getElapsedTime(tower->shootc);
    tower->shoot_sec = tower->shoott.microseconds / 1000000.0;
    if (tower->shoot_sec > 0.1) {
        if (tower->tower_pos[i + 2] == 1) {
            enemy->life_e[tower->is_shoot[i]] -= 25;
        }
        if (tower->tower_pos[i + 2] == 5)
            enemy->life_e[tower->is_shoot[i]] -= 35;
        if (tower->tower_pos[i + 2] == 6)
            enemy->life_e[tower->is_shoot[i]] -= 50;
        sfClock_restart(tower->shootc);
    }
        tower->is_shoot[i] = -1;
        tower->arrow_pos[i + 2].x = tower->tower_pos[i] + 100;
        tower->arrow_pos[i + 2].y = tower->tower_pos[i + 1] + 60;
}

void touch_fire(tower_t *tower, int i, enemy_t *enemy)
{
    tower->firet = sfClock_getElapsedTime(tower->firec);
    tower->fire_sec = tower->firet.microseconds / 1000000.0;
    if (tower->fire_sec > 0.1) {
        if (tower->tower_pos[i + 2] == 2)
            enemy->life_e[tower->is_shoot[i]] -= 35;
        if (tower->tower_pos[i + 2] == 7)
            enemy->life_e[tower->is_shoot[i]] -= 50;
        if (tower->tower_pos[i + 2] == 8)
            enemy->life_e[tower->is_shoot[i]] -= 70;
        sfClock_restart(tower->firec);
    }
        tower->is_shoot[i] = -1;
        tower->arrow_pos[i + 2].x = tower->tower_pos[i] + 80;
        tower->arrow_pos[i + 2].y = tower->tower_pos[i + 1] + 60;
}

void arrow_shoot(game_t *game, tower_t *tower, int i, enemy_t *enemy)
{
    double x, y, norme = 0;

    for (int j = 0; j != 65; j++) {
        x = enemy->knight_pos[j].x - (tower->tower_pos[i] + 80);
        y = enemy->knight_pos[j].y - (tower->tower_pos[i + 1] + 60);
        norme = sqrt(x * x + y * y);
        if (norme < 300 && norme > -300
        && tower->is_shoot[i] == -1 && enemy->life_e[j] > 0) {
            tower->is_shoot[i] = j;
        }
        arrow_shootw(game, tower, i, enemy, j);
        if (tower->is_shoot[i] != -1)
            sfRenderWindow_drawSprite(game->my_defender, tower->arrow, NULL);
    }
}

void fire_shoot(game_t *game, tower_t *tower, int i, enemy_t *enemy)
{
    double x = 0;
    double y = 0;
    double norme = 0;

    tower->magict[i] = sfClock_getElapsedTime(tower->magicc[i]);
    tower->magic_sec[i] = tower->magict[i].microseconds / 1000000.0;
    for (int j = 0; j != 65; j++) {
        x = enemy->knight_pos[j].x - (tower->tower_pos[i] + 80);
        y = enemy->knight_pos[j].y - (tower->tower_pos[i + 1] + 60);
        norme = sqrt(x * x + y * y);
        if (norme < 300 && norme > -300
        && tower->is_shoot[i] == -1 && enemy->life_e[j] > 0) {
            tower->is_shoot[i] = j;
        }
        fire_shootx(game, tower, i, enemy, j);
        if (tower->is_shoot[i] != -1)
            sfRenderWindow_drawSprite(game->my_defender, tower->fire, NULL);
    }
}
