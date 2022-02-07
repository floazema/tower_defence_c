/*
** EPITECH PROJECT, 2021
** mystruct
** File description:
** struct init
*/

#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../lib/my/my.h"
#include "struct.h"

#ifndef _DEFENDER_
    #define _DEFENDER_
        void init_window_element(game_t *game);
        void init_backgrounds(back_t *back);
        void manage_event(game_t *game);
        void move_cursor(game_t *game);
        int handle_error();
#endif/*_DEFENDER_*/
