/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-hugo.cathelain
** File description:
** my_strlen
*/

int my_strlen(char *str)
{
    int count = 0;

    while (*str != '\0') {
        str++;
        count++;
    }
    return count;
}
