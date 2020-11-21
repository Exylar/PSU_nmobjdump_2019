/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "nm.h"

int main(int argc, char **argv)
{
    if (argc == 1) {
        fill_structure("a.out");
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        if (argc > 2)
            printf("%s:", argv[i]);
        fill_structure(argv[i]);
        if (argc > 2 && argc - 1 != i)
            printf("\n");
    }
    return 0;
}