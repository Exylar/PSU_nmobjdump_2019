/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "objdump.h"

static void display_hexa(elf_t *elf, size_t i, int offset)
{
    char *sec_off = (char *)(elf->data + elf->section[i].sh_offset);
    int shift = 0;
    int value = offset - elf->section[i].sh_offset;

    for (value; value < offset - elf->section[i].sh_offset + 16 &&
    value < elf->section[i].sh_size; value++) {
        printf("%02x", (unsigned char)sec_off[value]);
        if ((value + 1) % 4 == 0 && (value > 1))
            printf(" ");
    }
    printf(" ");
    for (value; value < offset - elf->section[i].sh_offset + 16; value++) {
        if (shift % 4 == 0)
            printf(" ");
        printf("  ");
        shift++;
    }
}

static void display_text(elf_t *elf, size_t i, int offset)
{
    char *sec_off = (char *)(elf->data + elf->section[i].sh_offset);
    int value = offset - elf->section[i].sh_offset;

    for (value; value < offset - elf->section[i].sh_offset + 16 &&
    value < elf->section[i].sh_size; value++) {
        if (sec_off[value] >= 32 && sec_off[value] <= 126)
            printf("%c", sec_off[value]);
        else
            printf(".");
    }
    for (size_t esapce = value; esapce < offset - elf->section[i].sh_offset
        + 16; esapce++)
        printf(" ");
    printf("\n");
}

void display_content(int *offset, elf_t *elf, int count)
{
    while ((unsigned)*offset < elf->section[count].sh_offset +
    elf->section[count].sh_size) {
        printf(" %04x ", (unsigned)(elf->section[count].sh_addr + *offset -
        elf->section[count].sh_offset));
        display_hexa(elf, count, *offset);
        display_text(elf, count, *offset);
        *offset += 16;
    }
}