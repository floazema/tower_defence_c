/*
** EPITECH PROJECT, 2021
** arfrvdfs
** File description:
** adsvzfez
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (int i = 0; s1[i] || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return 1;
    }
    if (s1[i] == '\0' || s2[i] == '\0')
        return 1;
    else
        return 0;
}
