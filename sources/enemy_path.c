/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner
*/

#include "defender.h"

void knight_health(enemy_t *enemy, game_t *game, int i)
{
    double rect = 0;
    sfVector2f healthpos = enemy->knight_pos[i];

    healthpos.x -= 20;
    healthpos.y -= 30;
    enemy->healthrect.left = 0;
    rect = round(enemy->life_e[i] / 6);
    enemy->healthrect.width = rect;
    sfSprite_setPosition(enemy->health, healthpos);
    sfSprite_setTextureRect(enemy->health, enemy->healthrect);
    sfRenderWindow_drawSprite(game->my_defender, enemy->health, NULL);
    enemy->healthrect.left = 50;
    healthpos.x += rect;
    rect = 50 - rect;
    enemy->healthrect.width = rect;
    sfSprite_setPosition(enemy->health, healthpos);
    sfSprite_setTextureRect(enemy->health, enemy->healthrect);
    sfRenderWindow_drawSprite(game->my_defender, enemy->health, NULL);
}

void hog_health(enemy_t *enemy, game_t *game, int i)
{
    double rect = 0;
    sfVector2f healthpos = enemy->knight_pos[i + 50];

    healthpos.x -= 30;
    healthpos.y -= 30;
    enemy->healthrect.left = 0;
    rect = round(enemy->life_e[i + 50] / 8);
    enemy->healthrect.width = rect;
    sfSprite_setPosition(enemy->health, healthpos);
    sfSprite_setTextureRect(enemy->health, enemy->healthrect);
    sfRenderWindow_drawSprite(game->my_defender, enemy->health, NULL);
    enemy->healthrect.left = 50;
    healthpos.x += rect;
    rect = 50 - rect;
    enemy->healthrect.width = rect;
    sfSprite_setPosition(enemy->health, healthpos);
    sfSprite_setTextureRect(enemy->health, enemy->healthrect);
    sfRenderWindow_drawSprite(game->my_defender, enemy->health, NULL);
}

void anim_knight(game_t *game, enemy_t *enemy)
{
    for (int i = 0; i != 50; i++) {
        enemy->knight_pos[i] = sfSprite_getPosition(enemy->tab_knight[i]);
    }
    enemy->knightmt = sfClock_getElapsedTime(enemy->knightmc);
    enemy->knightt = sfClock_getElapsedTime(enemy->knightc);
    enemy->knight_sec = enemy->knightt.microseconds / 1000000.0;
    enemy->anim_ksec = enemy->knightmt.microseconds / 1000000.0;
    if (enemy->knight_sec >= 0.3) {
        enemy->knightrect.left += 50;
        sfClock_restart(enemy->knightc);
    }
    if (enemy->knightrect.left >= 250) {
        enemy->knightrect.left = 0;
    }
    path(enemy);
    anim_knights(game, enemy);
}

void anim_hog(game_t *game, enemy_t *enemy)
{
    for (int i = 0; i != 15; i++) {
        enemy->knight_pos[i + 50] = sfSprite_getPosition(enemy->tab_hog[i]);
    }
    enemy->hogmt = sfClock_getElapsedTime(enemy->hogmc);
    enemy->hogt = sfClock_getElapsedTime(enemy->hogc);
    enemy->hog_sec = enemy->hogt.microseconds / 1000000.0;
    enemy->anim_hsec = enemy->hogmt.microseconds / 1000000.0;
    if (enemy->hog_sec >= 0.3) {
        enemy->hogrect.left += 100;
        sfClock_restart(enemy->hogc);
    }
    if (enemy->hogrect.left >= 600) {
        enemy->hogrect.left = 0;
    }
    path_hog(enemy);
    anim_hogs(game, enemy);
}

void level(game_t *game, back_t *back, tower_t *tower, enemy_t *enemy)
{
    if (game->status == LEVEL1) {
        if (game->difficulty > 0) {
            load_level1(game, back, tower, enemy);
        }
        level1_game(game, back);
        glow_base(game, tower);
        draw_tower(game, tower, enemy);
        if (game->is_start >= 1) {
            anim_knight(game, enemy);
            anim_hog(game, enemy);
        }
        if (game->is_start == 13) {
            sfMusic_play(game->hogs);
        }
        draw_textselect(game, tower, enemy);
    }
}
