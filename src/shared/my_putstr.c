/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-hugo.cathelain
** File description:
** my_putstr
*/
#include "../../include/secured.h"

void my_putstr(char *str)
{
    int len = my_strlen(str);

    write(1, str, len);
}
