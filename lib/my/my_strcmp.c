/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** UwU
*/

int my_strlen2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    if (my_strlen2(s1) > my_strlen2(s2))
        return (my_strlen2(s1) - my_strlen2(s2));
    else if (my_strlen2(s1) < my_strlen2(s2))
        return (my_strlen2(s1) - my_strlen2(s2));
    for (i; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] < s2[i]) {
            j = j - 1;
        }
        else if (s1[i] > s2[i]) {
            j = j + 1;
        }
    }
    return (j);
}
