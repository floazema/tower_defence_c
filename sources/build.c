/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-florian.azema
** File description:
** increase_button
*/

#include "defender.h"

void build_archer_tower(game_t *game, tower_t *tower, sfVector2f select_pos,
sfVector2i mouse_pos) {
    if (tower->is_select == 1 && mouse_pos.x >= select_pos.x && mouse_pos.x
    <= select_pos.x + 65 && mouse_pos.y >=
    select_pos.y && mouse_pos.y <= select_pos.y + 50 &&
    sfMouse_isButtonPressed(sfMouseLeft) == true && game->gold >= 70
    && tower->up_tab[tower->to_up] != 1) {
        select_pos.x += 25;
        game->gold -= 70;
        tower->tower_pos[tower->pos] = select_pos.x;
        tower->tower_pos[tower->pos + 1] = select_pos.y;
        tower->tower_pos[tower->pos + 2] = 1;
        tower->arrow_pos[tower->pos + 2].x = select_pos.x + 80;
        tower->arrow_pos[tower->pos + 2].y = select_pos.y + 60;
        tower->pos += 3;
        tower->up_tab[tower->to_up] = 1;
    }
}

void build_magic_tower(game_t *game, tower_t *tower, sfVector2f select_pos,
sfVector2i mouse_pos) {
    if (tower->is_select == 1 && mouse_pos.x >= select_pos.x && mouse_pos.x
    <= select_pos.x + 70 && mouse_pos.y >=
    select_pos.y + 130 && mouse_pos.y <= select_pos.y + 200 &&
    sfMouse_isButtonPressed(sfMouseLeft) == true && game->gold >= 100
    && tower->up_tab[tower->to_up] != 1) {
        select_pos.x += 25;
        game->gold -= 100;
        tower->tower_pos[tower->pos] = select_pos.x;
        tower->tower_pos[tower->pos + 1] = select_pos.y;
        tower->tower_pos[tower->pos + 2] = 2;
        tower->arrow_pos[tower->pos + 2].x = select_pos.x + 80;
        tower->arrow_pos[tower->pos + 2].y = select_pos.y + 60;
        tower->pos += 3;
        tower->up_tab[tower->to_up] = 1;
    }
}

void build_bomber_tower(game_t *game, tower_t *tower, sfVector2f select_pos,
sfVector2i mouse_pos) {
    if (tower->is_select == 1 && mouse_pos.x >= select_pos.x + 140 &&
    mouse_pos.x
    <= select_pos.x + 190 && mouse_pos.y >=
    select_pos.y + 130 && mouse_pos.y <= select_pos.y + 200 &&
    sfMouse_isButtonPressed(sfMouseLeft) == true && game->gold >= 125
    && tower->up_tab[tower->to_up] != 1) {
        select_pos.x += 25;
        game->gold -= 125;
        tower->tower_pos[tower->pos] = select_pos.x;
        tower->tower_pos[tower->pos + 1] = select_pos.y;
        tower->tower_pos[tower->pos + 2] = 3;
        tower->arrow_pos[tower->pos + 2].x = select_pos.x + 80;
        tower->arrow_pos[tower->pos + 2].y = select_pos.y + 60;
        tower->pos += 3;
        tower->up_tab[tower->to_up] = 1;
    }
}

void build_arcx_tower(game_t *game, tower_t *tower, sfVector2f select_pos,
sfVector2i mouse_pos) {
    if (tower->is_select == 1 && mouse_pos.x >= select_pos.x + 140 &&
    mouse_pos.x
    <= select_pos.x + 190 && mouse_pos.y >=
    select_pos.y && mouse_pos.y <= select_pos.y + 50 &&
    sfMouse_isButtonPressed(sfMouseLeft) == true && game->gold >= 150
    && tower->up_tab[tower->to_up] != 1) {
        select_pos.x += 25;
        game->gold -= 150;
        tower->tower_pos[tower->pos] = select_pos.x;
        tower->tower_pos[tower->pos + 1] = select_pos.y;
        tower->tower_pos[tower->pos + 2] = 4;
        tower->arrow_pos[tower->pos + 2].x = select_pos.x + 80;
        tower->arrow_pos[tower->pos + 2].y = select_pos.y + 60;
        tower->pos += 3;
        tower->up_tab[tower->to_up] = 1;
    }
}

void build_towers(game_t *game, tower_t *tower)
{
    sfVector2f select_pos = sfSprite_getPosition(tower->select);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->my_defender);

    build_archer_tower(game, tower, select_pos, mouse_pos);
    build_bomber_tower(game, tower, select_pos, mouse_pos);
    build_magic_tower(game, tower, select_pos, mouse_pos);
    build_arcx_tower(game, tower, select_pos, mouse_pos);
    upgrade(game, tower, select_pos, mouse_pos);
    sell(game, tower, select_pos, mouse_pos);
}
