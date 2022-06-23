/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner
*/

#include "defender.h"

void anim_knights(game_t *game, enemy_t *enemy)
{
    for (int i = 0; i != 50; sfSprite_setTextureRect
    (enemy->tab_knight[i], enemy->knightrect), i++);
    for (int i = 0; i != 50; i++) {
        if (enemy->knight_pos[i].x >= 145 && enemy->life_e[i] > 0) {
            sfRenderWindow_drawSprite(game->my_defender,
            enemy->tab_knight[i], NULL);
            knight_health(enemy, game, i);
        }
        else if (enemy->knight_pos[i].x <= 145 && enemy->knight_pos[i].x >=
        100 && enemy->life_e[i] > 0) {
            game->life -= 1;
            enemy->knight_pos[i].x = -500;
            sfSprite_setPosition(enemy->tab_knight[i], enemy->knight_pos[i]);
        }
    }
}

void anim_hogs(game_t *game, enemy_t *enemy)
{
    for (int i = 0; i != 15; sfSprite_setTextureRect
    (enemy->tab_hog[i], enemy->hogrect), i++);
    for (int i = 0; i != 15; i++) {
        if (enemy->knight_pos[i + 50].x >= 145 && enemy->life_e[i + 50] > 0) {
            sfRenderWindow_drawSprite
            (game->my_defender, enemy->tab_hog[i], NULL);
            hog_health(enemy, game, i);
        }
        else if (enemy->knight_pos[i + 50].x <= 145 &&
        enemy->knight_pos[i + 50].x >= 100
        && enemy->life_e[i + 50] > 0) {
            game->life -= 1;
            enemy->knight_pos[i + 50].x = -500;
            sfSprite_setPosition(enemy->tab_hog[i], enemy->knight_pos[i + 50]);
        }
    }
}

void path_knight(enemy_t *enemy, int i, sfVector2f origin)
{
    if (enemy->anim_ksec >= 0.1 && (enemy->knight_pos[i].x >= PART1 ||
        (enemy->knight_pos[i].x <= PART2 &&
        enemy->knight_pos[i].x >= PART3) || (enemy->knight_pos[i].x <=
        PART4 && enemy->knight_pos[i].x >= PART5)
        || (enemy->knight_pos[i].x <= PART6 && enemy->knight_pos[i].x >=
        PART7))) {
        sfSprite_setOrigin(enemy->tab_knight[i], origin);
        sfSprite_setRotation(enemy->tab_knight[i], 270);
        enemy->knight_pos[i].x -= 10;
        sfClock_restart(enemy->knightmc);
    }
    if (enemy->anim_ksec >= 0.1 && enemy->knight_pos[i].x <= PART1
    && enemy->knight_pos[i].x >= PART2) {
        sfSprite_setOrigin(enemy->tab_knight[i], origin);
        sfSprite_setRotation(enemy->tab_knight[i], 180);
        enemy->knight_pos[i].x -= 2;
        enemy->knight_pos[i].y += 8;
        sfClock_restart(enemy->knightmc);
    }
}

void path(enemy_t *enemy)
{
    sfVector2f origin = {25, 25};

    for (int i = 0; i != 50; i++) {
        path_knight(enemy, i, origin);
        if (enemy->anim_ksec >= 0.1 && enemy->knight_pos[i].x <= PART3 &&
        enemy->knight_pos[i].x >= PART4) {
            sfSprite_setOrigin(enemy->tab_knight[i], origin);
            sfSprite_setRotation(enemy->tab_knight[i], 0);
            enemy->knight_pos[i].x -= 5;
            enemy->knight_pos[i].y -= 8;
            sfClock_restart(enemy->knightmc);
        }
        anim_knightc(enemy, i, origin);
    }
    for (int i = 0; i != 50; i++) {
        sfSprite_setPosition(enemy->tab_knight[i], enemy->knight_pos[i]);
    }
}

void path_hog(enemy_t *enemy)
{
    sfVector2f origin = {23, 50};

    for (int i = 0; i != 15; i++) {
        anim_hogt(enemy, i, origin);
        if (enemy->anim_hsec >= 0.1 && enemy->knight_pos[i + 50].x <= PART3 &&
        enemy->knight_pos[i + 50].x >= PART4) {
            sfSprite_setOrigin(enemy->tab_hog[i], origin);
            sfSprite_setRotation(enemy->tab_hog[i], 0);
            enemy->knight_pos[i + 50].x -= 10;
            enemy->knight_pos[i + 50].y -= 16;
            sfClock_restart(enemy->hogmc);
        }
        anim_hogc(enemy, i, origin);
    }
    for (int i = 0; i != 15; i++) {
        sfSprite_setPosition(enemy->tab_hog[i], enemy->knight_pos[i + 50]);
    }
}
