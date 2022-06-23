/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-florian.azema
** File description:
** level1_things
*/

#include "defender.h"

sfVector2f moneypos = {350, 17};
sfVector2f lifepos = {68, 17};
sfVector2f count_wave = {185, 17};
sfVector2f wave_pos = {1750, 335};

void gold_life_init(game_t *game)
{
    game->font = sfFont_createFromFile("assets/text.ttf");
    game->goldc = sfClock_create();
    game->money = sfText_create();
    game->life_point = sfText_create();
    game->wave = sfText_create();
    sfText_setFont(game->money, game->font);
    sfText_setFont(game->wave, game->font);
    sfText_setFont(game->life_point, game->font);
    sfText_setPosition(game->life_point, lifepos);
    sfText_setPosition(game->wave, count_wave);
    sfText_setPosition(game->money, moneypos);
    game->gold = 700;
    game->life = 5;
}

sfIntRect select_rect(sfIntRect rect)
{
    rect.height = 200;
    rect.left = 0;
    rect.width = 200;
    rect.top = 0;
    return (rect);
}

sfIntRect tower_rect(sfIntRect rect)
{
    rect.height = 150;
    rect.left = 0;
    rect.width = 150;
    rect.top = 0;
    return (rect);
}

void create_scene(game_t *game, tower_t *tower, back_t *back)
{
    create_sprite("assets/map1.jpg", &back->map1_back,
    &back->texture_map1_back, NULL);
    create_sprite("assets/base.png", &tower->glow,
    &tower->texture_glow, NULL);
    create_sprite("assets/select.png", &tower->select,
    &tower->texture_select, NULL);
    create_sprite("assets/archer.png", &tower->archer,
    &tower->texture_archer, NULL);
    create_sprite("assets/magic.png", &tower->magic,
    &tower->texture_magic, NULL);
    create_sprite("assets/bomb.png", &tower->bomb,
    &tower->texture_bomb, NULL);
    create_sprite("assets/arcx.png", &tower->arcx,
    &tower->texture_arcx, NULL);
    create_sprite("assets/start_wave.png", &game->start_wave,
    &game->texture_start_wave, &wave_pos);
    create_scene2(game, tower, back);
}

void create_text(game_t *game)
{
    game->goldt = sfClock_getElapsedTime(game->goldc);
    game->seconds = game->goldt.microseconds / 1000000.0;
    if (game->seconds > 0.5 && game->is_start > 0) {
        game->gold += 1;
        sfClock_restart(game->goldc);
    }
    sfText_setString(game->money, my_itoa(game->gold));
    sfRenderWindow_drawText(game->my_defender, game->money, NULL);
    sfText_setString(game->life_point, my_itoa(game->life));
    sfRenderWindow_drawText(game->my_defender, game->life_point, NULL);
    sfText_setString(game->wave, my_itoa(game->is_start));
    sfRenderWindow_drawText(game->my_defender, game->wave, NULL);
    }
