/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "objdump.h"

void display64(char *filename, elf_t *elf)
{
    printf("%s:\tfile format elf64-x86-64\n", filename);
    printf("architecture: i386:x86-64, flags 0x%08x:\n", elf->header->e_flags);
    printf("HAS_SYMS, DYNAMIC, D_PAGED\n");
    printf("start address 0x%016lx\n\n", elf->header->e_entry);
}

void display32(char *filename, elf_t *elf)
{
    printf("%s:\tfile format elf32-i386\n", filename);
    printf("architecture: i386, flags 0x%08x:\n", elf->header->e_flags);
    printf("HAS_SYMS, DYNAMIC, D_PAGED\n");
    printf("start address 0x%016lx\n\n", elf->header->e_entry);
}

void display_header(char *filename, elf_t *elf)
{
    printf("\n");
    if (elf->header->e_type == 2)
        display32(filename, elf);
    else if (elf->header->e_type == 3)
        display64(filename, elf);
}
