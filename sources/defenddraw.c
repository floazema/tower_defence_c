/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** myrunner
*/

#include "defender.h"

void draw_sprite(game_t *game, back_t *back, button_t *button)
{
    if (game->status == START_MENU) {
        drawSprite(game->my_defender, back->start_back, NULL);
        drawSprite(game->my_defender, button->start, NULL);
        drawSprite(game->my_defender, button->quit, NULL);
        drawSprite(game->my_defender, button->option, NULL);
    }
    if (game->status == OPTIONS) {
        sfSprite_setTextureRect(button->music_bar, button->music_rect);
        drawSprite(game->my_defender, back->start_back, NULL);
        drawSprite(game->my_defender, back->option_back, NULL);
        drawSprite(game->my_defender, button->music_bar, NULL);
        drawSprite(game->my_defender, button->sound_bar, NULL);
        drawSprite(game->my_defender, button->music_logo, NULL);
        drawSprite(game->my_defender, button->sound_logo, NULL);
    }
    if (game->status == LEVEL_SELECT) {
        drawSprite(game->my_defender, back->level_select, NULL);
    }
    if (game->status == HELP)
        drawSprite(game->my_defender, game->help, NULL);
}

void draw_textselect(game_t *game, tower_t *tower, enemy_t *enemy)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->my_defender);
    int j = 0;

    if (mouse_pos.x >= 1820 && mouse_pos.y <= 100 &&
    sfMouse_isButtonPressed(sfMouseLeft) == true)
        game->status = PAUSE;
    if (tower->is_select > 0) {
        sfRenderWindow_drawSprite(game->my_defender, tower->select, NULL);
    }
    for (int i = 0; i != 65; i++)
        if (enemy->life_e[i] > 0)
            j = 1;
    if (j == 0)
        game->status = WIN;
    if (game->life <= 0)
        game->status = LOOSE;
    if (game->is_start == 0)
        start_wave(game);
    create_text(game);
}

void anim_knightc(enemy_t *enemy, int i, sfVector2f origin)
{
    if (enemy->anim_ksec >= 0.1 && enemy->knight_pos[i].x <= PART5 &&
    enemy->knight_pos[i].x >= PART6) {
        sfSprite_setOrigin(enemy->tab_knight[i], origin);
        sfSprite_setRotation(enemy->tab_knight[i], 180);
        enemy->knight_pos[i].x -= 4;
        enemy->knight_pos[i].y += 8;
        sfClock_restart(enemy->knightmc);
    }
}

void anim_hogt(enemy_t *enemy, int i, sfVector2f origin)
{
    if (enemy->anim_hsec >= 0.1 && (enemy->knight_pos[i + 50].x >= PART1 ||
        (enemy->knight_pos[i + 50].x <= PART2 &&
        enemy->knight_pos[i + 50].x >= PART3) ||
        (enemy->knight_pos[i + 50].x <= PART4 &&
        enemy->knight_pos[i + 50].x >= PART5)
        || (enemy->knight_pos[i + 50].x <= PART6 &&
        enemy->knight_pos[i + 50].x >= PART7))) {
        sfSprite_setOrigin(enemy->tab_hog[i], origin);
        sfSprite_setRotation(enemy->tab_hog[i], 270);
        enemy->knight_pos[i + 50].x -= 20;
        sfClock_restart(enemy->hogmc);
    }
    if (enemy->anim_hsec >= 0.1 && enemy->knight_pos[i + 50].x <= PART1 &&
    enemy->knight_pos[i + 50].x >= PART2) {
        sfSprite_setOrigin(enemy->tab_hog[i], origin);
        sfSprite_setRotation(enemy->tab_hog[i], 180);
        enemy->knight_pos[i + 50].x -= 4;
        enemy->knight_pos[i + 50].y += 16;
        sfClock_restart(enemy->hogmc);
    }
}

void anim_hogc(enemy_t *enemy, int i, sfVector2f origin)
{
    if (enemy->anim_hsec >= 0.1 && enemy->knight_pos[i + 50].x <= PART5 &&
    enemy->knight_pos[i + 50].x >= PART6) {
        sfSprite_setOrigin(enemy->tab_hog[i], origin);
        sfSprite_setRotation(enemy->tab_hog[i], 180);
        enemy->knight_pos[i + 50].x -= 8;
        enemy->knight_pos[i + 50].y += 16;
        sfClock_restart(enemy->hogmc);
    }
}
