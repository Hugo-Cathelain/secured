/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-hugo.cathelain
** File description:
** my_putnbr
*/
#include "../../include/secured.h"

void my_putchar(char ch)
{
    write(1, &ch, 1);
}

void my_putnbr(int number)
{
    if (number / 10)
        my_putnbr(number / 10);
    my_putchar(number % 10 + '0');
}
