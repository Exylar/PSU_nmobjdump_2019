/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "nm.h"

void get_section(elf_t *elf)
{
    for (uint32_t i = 0; i < elf->header->e_shnum; i++) {
        if (elf->section[i].sh_type == SHT_SYMTAB)
            print_symbols(elf, i);
    }
}

void fill_structure(char *filename)
{
    elf_t *elf = malloc(sizeof(elf_t));
    int fd;

    if ((fd = open(filename, O_RDONLY)) == -1) {
        printf("my_nm: '%s': No such file\n", filename);
        exit(84);
    }
    if ((elf->size = lseek(fd, 0, SEEK_END)) == -1)
        exit(84);
    if ((elf->data = mmap(NULL, elf->size, PROT_READ, MAP_SHARED, fd, 0))) {
        elf->header = (Elf64_Ehdr *)(elf->data);
        elf->section = (Elf64_Shdr *)(elf->data + elf->header->e_shoff);
    }
    else
        exit(84);
    check_format(elf);
    get_section(elf);
    free(elf);
}
