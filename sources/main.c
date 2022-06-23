/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-mydefender-florian.azema
** File description:
** main
*/

#include "defender.h"

int helper(int ac, char **argv)
{
    if (ac > 1)
        if (my_strcmp(argv[1], "-h") == 0) {
            my_printf("helper\n");
            return EXIT_HELPER;
        }
    return 0;
}

int main(int argc, char **argv)
{
    if (helper(argc, argv) == EXIT_HELPER)
        return EXIT_HELPER;
    return my_defender();
}
