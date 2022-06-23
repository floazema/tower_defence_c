/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-florian.azema
** File description:
** init_button
*/

#include "defender.h"

sfIntRect create_knight_rect(sfIntRect rect)
{
    rect.height = 50;
    rect.left = 0;
    rect.width = 50;
    rect.top = 0;
    return (rect);
}

sfIntRect create_health_rect(sfIntRect rect)
{
    rect.height = 10;
    rect.left = 0;
    rect.width = 40;
    rect.top = 0;
    return (rect);
}

sfIntRect create_hog_rect(sfIntRect rect)
{
    rect.height = 100;
    rect.left = 0;
    rect.width = 100;
    rect.top = 0;
    return (rect);
}

void fill_knight(enemy_t *enemy)
{
    enemy->tab_knight[0] = enemy->knight;
    enemy->tab_hog[0] = enemy->hog;
}

void init_l(enemy_t *enemy, game_t *game)
{
    create_sprite("assets/health.png",
    &enemy->health, &enemy->texture_health, NULL);
    enemy->knightrect = create_knight_rect(enemy->knightrect);
    enemy->healthrect = create_health_rect(enemy->knightrect);
    enemy->knight_sec = 0;
    enemy->anim_ksec = 0;
    enemy->knightc = sfClock_create();
    enemy->knightmc = sfClock_create();
    enemy->hogrect = create_hog_rect(enemy->hogrect);
    enemy->hog_sec = 0;
    enemy->anim_hsec = 0;
    enemy->hogc = sfClock_create();
    enemy->hogmc = sfClock_create();
    game->hogs = sfMusic_createFromFile("assets/hog.ogg");
    game->isplay = 0;
}
