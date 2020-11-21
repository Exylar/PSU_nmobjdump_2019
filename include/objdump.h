/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef PSU_NMOBJDUMP_2019_OBJDUMP_H
#define PSU_NMOBJDUMP_2019_OBJDUMP_H

#include <stdlib.h>
#include <stdio.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

typedef struct elf_s {
    Elf64_Ehdr *header;
    Elf64_Shdr *section;
    off_t size;
    void *data;
} elf_t;

void display_content(int *offset, elf_t *elf, int count);
void display_header(char *filename, elf_t *elf);

void check_format(elf_t *elf);

#endif //PSU_NMOBJDUMP_2019_OBJDUMP_H
