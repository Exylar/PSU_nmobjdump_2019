/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "objdump.h"

static void browse_table(elf_t *elf, char* string_table)
{
    int offset = 0;

    for (size_t count = 0; count < elf->header->e_shnum; count++) {
        if (!(elf->section[count].sh_type == SHT_NULL ||
        elf->section[count].sh_type == SHT_SYMTAB ||
        strcmp(&string_table[elf->section[count].sh_name], ".strtab") == 0 ||
        strcmp(&string_table[elf->section[count].sh_name], ".shstrtab") == 0 ||
        strcmp(&string_table[elf->section[count].sh_name], ".bss") == 0)) {
            printf("Contents of section %s:\n",
            &string_table[elf->section[count].sh_name]);
            offset = elf->section[count].sh_offset;
            display_content(&offset , elf, count);
        }
    }
    free(elf);
}

static void fill_structure(char *filename)
{
    elf_t *elf = malloc(sizeof(elf_t));
    int fd;
    char *string_table;

    if ((fd = open(filename, O_RDONLY)) == -1) {
        printf("my_nm: '%s': No such file\n", filename);
        exit(84);
    } if ((elf->size = lseek(fd, 0, SEEK_END)) == -1)
        exit(84);
    if ((elf->data = mmap(NULL, elf->size, PROT_READ, MAP_SHARED, fd, 0))) {
        elf->header = (Elf64_Ehdr *)(elf->data);
        elf->section = (Elf64_Shdr *)(elf->data + elf->header->e_shoff);
    } else
        exit(84);
    check_format(elf);
    string_table = (char *)(elf->data +
    elf->section[elf->header->e_shstrndx].sh_offset);
    display_header(filename, elf);
    browse_table(elf, string_table);
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        fill_structure("a.out");
        return 0;
    }
    for (size_t i = 1; i < argc; i++) {
        fill_structure(argv[i]);
    }
    return 0;
}