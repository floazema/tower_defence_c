/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** putstr
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char);
void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
