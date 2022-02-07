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

#ifndef __MY_STRUCT__
    #define __MY_STRUCT__
        typedef struct game {
            sfRenderWindow *my_defender;
            sfSprite *cursor;
            sfTexture *texture_cursor;
            sfSprite *start;
            sfTexture *texture_start;
            int game_status;
        } game_t;
        typedef struct background {
            sfSprite *start_back;
            sfTexture *texture_start_back;
        } back_t;
#endif/*__MY_STRUCT__*/
