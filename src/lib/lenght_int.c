/*
** EPITECH PROJECT, 2022
** lenght_int
** File description:
** lenght_int
*/

#include "header.h"

int lenght_int(int nbr)
{
    int count = 0;

    if (nbr > 0)
        count = 1;

    while (nbr >= 10) {
        nbr = nbr / 10;
        count++;
    }
    return count;
}
