/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner
*/

#include "defender.h"

void load_enemy(enemy_t *enemy, game_t *game)
{
    sfVector2f hog_pos = {6500, 395};

    fill_knight(enemy);
    init_e(enemy, game);
    for (int i = 0, j = 150, k = 0; i != 15; i++) {
        create_sprite("assets/hog.png",
        &enemy->tab_hog[i], &enemy->texture_hog, NULL);
        sfSprite_setTextureRect(enemy->tab_hog[i], enemy->hogrect);
        sfSprite_setPosition(enemy->tab_hog[i], hog_pos);
        hog_pos.x += j + k;
        if (i == 5) {
            j = 200;
            k = 6000;
        }
        else
            k = 0;
        enemy->life_e[i + 50] = 400;
    }
    init_l(enemy, game);
}

void load_level1(game_t *game, back_t *back, tower_t *tower, enemy_t *enemy)
{
    create_scene(game, tower, back);
    load_enemy(enemy, game);
    gold_life_init(game);
    set_pos(tower);
    set_pos2(tower);
    for (int i = 0; i != 55; i++)
        tower->tower_pos[i] = 0;
    for (int i = 0; i < 550; i++) {
        tower->magicc[i] = sfClock_create();
        tower->arrowc[i] = sfClock_create();
    }
    load_b(game, tower);
}

void load_b(game_t *game, tower_t *tower)
{
    tower->shootc = sfClock_create();
    game->difficulty = 0;
    game->is_start = 0;
    tower->is_select = 0;
    tower->pos = 0;
    tower->i = 0;
    tower->to_up = 0;
    for (int i = 0; i != 550; i++)
        tower->is_shoot[i] = -1;
}

void level1_game(game_t *game, back_t *back)
{
    if (game->status == LEVEL1) {
        drawSprite(game->my_defender, back->map1_back, NULL);
    }
}
