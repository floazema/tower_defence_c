/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-florian.azema
** File description:
** draw_tower3
*/

#include "defender.h"

void draw_archer(game_t *game, tower_t *tower, sfVector2f select_pos, int i)
{
    sfSprite_setPosition(tower->archer, select_pos);
    if (tower->tower_pos[i + 2] == 1) {
        sfRenderWindow_drawSprite(game->my_defender, tower->archer, NULL);
    }
    if (tower->tower_pos[i + 2] == 5) {
        tower->bowrect.left = 150;
        sfSprite_setTextureRect(tower->archer, tower->bowrect);
        sfRenderWindow_drawSprite(game->my_defender, tower->archer, NULL);
        tower->bowrect.left = 0;
        sfSprite_setTextureRect(tower->archer, tower->bowrect);
    }
    if (tower->tower_pos[i + 2] == 6) {
        tower->bowrect.left = 300;
        sfSprite_setTextureRect(tower->archer, tower->bowrect);
        sfRenderWindow_drawSprite(game->my_defender, tower->archer, NULL);
        tower->bowrect.left = 0;
        sfSprite_setTextureRect(tower->archer, tower->bowrect);
    }
}

void draw_magic(game_t *game, tower_t *tower, sfVector2f select_pos, int i)
{
    sfSprite_setPosition(tower->magic, select_pos);
    if (tower->tower_pos[i + 2] == 2) {
        sfRenderWindow_drawSprite(game->my_defender, tower->magic, NULL);
    }
    if (tower->tower_pos[i + 2] == 7) {
        tower->bowrect.left = 150;
        sfSprite_setTextureRect(tower->magic, tower->bowrect);
        sfRenderWindow_drawSprite(game->my_defender, tower->magic, NULL);
        tower->bowrect.left = 0;
        sfSprite_setTextureRect(tower->magic, tower->bowrect);
    }
    if (tower->tower_pos[i + 2] == 8) {
        tower->bowrect.left = 300;
        sfSprite_setTextureRect(tower->magic, tower->bowrect);
        sfRenderWindow_drawSprite(game->my_defender, tower->magic, NULL);
        tower->bowrect.left = 0;
        sfSprite_setTextureRect(tower->magic, tower->bowrect);
    }
}

void draw_bomb(game_t *game, tower_t *tower, sfVector2f select_pos, int i)
{
    sfSprite_setPosition(tower->bomb, select_pos);
    if (tower->tower_pos[i + 2] == 3) {
        sfRenderWindow_drawSprite(game->my_defender, tower->bomb, NULL);
    }
    if (tower->tower_pos[i + 2] == 11) {
        tower->bowrect.left = 150;
        sfSprite_setTextureRect(tower->bomb, tower->bowrect);
        sfRenderWindow_drawSprite(game->my_defender, tower->bomb, NULL);
        tower->bowrect.left = 0;
        sfSprite_setTextureRect(tower->bomb, tower->bowrect);
    }
    if (tower->tower_pos[i + 2] == 12) {
        tower->bowrect.left = 300;
        sfSprite_setTextureRect(tower->bomb, tower->bowrect);
        sfRenderWindow_drawSprite(game->my_defender, tower->bomb, NULL);
        tower->bowrect.left = 0;
        sfSprite_setTextureRect(tower->bomb, tower->bowrect);
    }
}

void draw_arcx(game_t *game, tower_t *tower, sfVector2f select_pos, int i)
{
    sfSprite_setPosition(tower->arcx, select_pos);
    if (tower->tower_pos[i + 2] == 4) {
        sfRenderWindow_drawSprite(game->my_defender, tower->arcx, NULL);
    }
    if (tower->tower_pos[i + 2] == 9) {
        tower->bowrect.left = 150;
        sfSprite_setTextureRect(tower->arcx, tower->bowrect);
        sfRenderWindow_drawSprite(game->my_defender, tower->arcx, NULL);
        tower->bowrect.left = 0;
        sfSprite_setTextureRect(tower->arcx, tower->bowrect);
    }
    if (tower->tower_pos[i + 2] == 10) {
        tower->bowrect.left = 300;
        sfSprite_setTextureRect(tower->arcx, tower->bowrect);
        sfRenderWindow_drawSprite(game->my_defender, tower->arcx, NULL);
        tower->bowrect.left = 0;
        sfSprite_setTextureRect(tower->arcx, tower->bowrect);
    }
}

void arrow_shoot_calc(tower_t *tower, int i, enemy_t *enemy)
{
    double coef = 1, coef2 = 1, y = 0, x = 0;

    y = enemy->knight_pos[tower->is_shoot[i]].y - tower->arrow_pos[i + 2].y;
    x = enemy->knight_pos[tower->is_shoot[i]].x - tower->arrow_pos[i + 2].x;
    coef = (y / x);
    if (coef > 3 || coef < -3)
        coef2 = 0.3;
    if (coef > 10 || coef < -10)
        coef2 = 0.1;
    if (coef > 30 || coef < -30)
        coef2 = 0.033;
    if (x >= 0) {
        tower->arrow_pos[i + 2].y += coef * 0.07 * coef2;
        tower->arrow_pos[i + 2].x += 0.07 * coef2;
        sfSprite_setRotation(tower->arrow, (atan(coef)) * 180 / 3.14159265359);
    } else
        arrow_shoot_calcs(tower, i, coef, coef2);
    sfSprite_setPosition(tower->arrow, tower->arrow_pos[i + 2]);
}
