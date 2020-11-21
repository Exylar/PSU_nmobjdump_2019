/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** check_format
*/

#include "objdump.h"

void check_format(elf_t *elf)
{
    if (elf->header->e_ident[0] == 0x7f && elf->header->e_ident[1] == 'E'
    && elf->header->e_ident[2] == 'L' && elf->header->e_ident[3] == 'F') {
        return;
    }
    exit(84);
}