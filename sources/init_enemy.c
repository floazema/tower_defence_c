/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-florian.azema
** File description:
** init_button
*/

#include "defender.h"

void init_e(enemy_t *enemy, game_t *game)
{
    sfVector2f knight_pos = {2000, 385};
    sfVector2f knight_scale = {1.5, 1.5};

    for (int i = 0, j = 150, k = 0; i != 50; i++) {
        create_sprite("assets/knight.png",
        &enemy->tab_knight[i], &enemy->texture_knight, NULL);
        sfSprite_setTextureRect(enemy->tab_knight[i], enemy->knightrect);
        sfSprite_setScale(enemy->tab_knight[i], knight_scale);
        sfSprite_setPosition(enemy->tab_knight[i], knight_pos);
        knight_pos.x += j + k;
        if (i == 5) {
            j = 50, k = 3000;
        }
        if (i == 30) {
            j = 30, k = 1000;
        }
        if (i != 5 && i != 30)
            k = 0;
        enemy->life_e[i] = 300;
    }
}

void fire_shootx(game_t *game, tower_t *tower, int i, enemy_t *enemy, int j)
{
    if ((enemy->knight_pos[tower->is_shoot[i]].x
    + enemy->knight_pos[tower->is_shoot[i]].y) + 5 >=
    (tower->arrow_pos[i + 2].x + tower->arrow_pos[i + 2].y) &&
    (enemy->knight_pos[tower->is_shoot[i]].x +
    enemy->knight_pos[tower->is_shoot[i]].y) - 5 <=
    tower->arrow_pos[i + 2].x + tower->arrow_pos[i + 2].y) {
        touch_fire(tower, i, enemy);
    }
    if (tower->is_shoot[i] != -1 && tower->magic_sec[i] >= 0.01) {
        fire_shoot_calc(tower, i, enemy);
        sfClock_restart(tower->magicc[i]);
    }
    if (enemy->life_e[j] <= 0 && enemy->life_e[j] != -101) {
        game->is_start += 1, tower->is_shoot[i] = -1;
        enemy->knight_pos[j].x = -500, game->gold += 20;
        tower->arrow_pos[i + 2].x = tower->tower_pos[i] + 100;
        tower->arrow_pos[i + 2].y = tower->tower_pos[i + 1] + 60;
        enemy->life_e[j] = -101;
    }
}

void arrow_shoot_calcs(tower_t *tower, int i, double coef, double coef2)
{
    tower->arrow_pos[i + 2].y -= coef * 0.07 * coef2;
    tower->arrow_pos[i + 2].x -= 0.07 * coef2;
    sfSprite_setRotation(tower->arrow, ((atan(coef)) * 180 / 3.14159265359)
    - 180);
}

void arrow_shootw(game_t *game, tower_t *tower, int i, enemy_t *enemy, int j)
{
    if ((enemy->knight_pos[tower->is_shoot[i]].x
    + enemy->knight_pos[tower->is_shoot[i]].y) + 5 >=
    (tower->arrow_pos[i + 2].x + tower->arrow_pos[i + 2].y) &&
    (enemy->knight_pos[tower->is_shoot[i]].x +
    enemy->knight_pos[tower->is_shoot[i]].y) - 5 <=
    tower->arrow_pos[i + 2].x + tower->arrow_pos[i + 2].y) {
        touch_arrow(tower, i, enemy);
    }
    if (tower->is_shoot[i] != -1 && tower->arrow_sec[i] >= 0.01) {
        arrow_shoot_calc(tower, i, enemy);
        sfClock_restart(tower->arrowc[i]);
    }
    if (enemy->life_e[j] <= 0 && enemy->life_e[j] != -101) {
        game->is_start += 1;
        tower->is_shoot[i] = -1, game->gold += 20;
        enemy->knight_pos[j].x = -500;
        tower->arrow_pos[i + 2].x = tower->tower_pos[i] + 100;
        tower->arrow_pos[i + 2].y = tower->tower_pos[i + 1] + 60;
        enemy->life_e[j] = -101;
    }
}

void create_scene2(game_t *game, tower_t *tower, back_t *back) {
    create_sprite("assets/arrow.png", &tower->arrow,
    &tower->texture_arrow, NULL);
    create_sprite("assets/fire.png", &tower->fire,
    &tower->texture_fire, NULL);
    create_sprite("assets/pause_game.jpg", &game->pause,
    &tower->texture_fire, NULL);
    create_sprite("assets/win.jpg", &game->win,
    &game->texture_win, NULL);
    create_sprite("assets/loose.png", &game->loose,
    &game->texture_loose, NULL);
    tower->serect = select_rect(tower->serect);
    tower->bowrect = tower_rect(tower->serect);
    sfSprite_setTextureRect(tower->select, tower->serect);
    sfSprite_setTextureRect(tower->archer, tower->bowrect);
    sfSprite_setTextureRect(tower->bomb, tower->bowrect);
    sfSprite_setTextureRect(tower->arcx, tower->bowrect);
    sfSprite_setTextureRect(tower->magic, tower->bowrect);
    tower->firec = sfClock_create();
}
