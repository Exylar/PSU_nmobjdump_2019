/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "nm.h"

char get_type(Elf64_Sym sym, Elf64_Shdr *section)
{
    char c;

    (void)section;
    if (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE) {
        c = 'u';
        return c;
    }
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK) {
        c = 'W';
        if (sym.st_shndx == SHN_UNDEF)
            c = 'w';
        return c;
    }
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK &&
    ELF64_ST_TYPE(sym.st_info) == STT_OBJECT) {
        c = 'V';
        if (sym.st_shndx == SHN_UNDEF)
            c = 'v';
        return c;
    }
    return '?';
}

char get_type2(Elf64_Sym sym, Elf64_Shdr *section)
{
    char c;

    if (sym.st_shndx == SHN_UNDEF) {
        c = 'U';
        return c;
    } if (sym.st_shndx == SHN_ABS) {
        c = 'A';
        return c;
    } if (sym.st_shndx == SHN_COMMON) {
        c = 'C';
        return c;
    } if (section[sym.st_shndx].sh_type == SHT_NOBITS
    && section[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE)) {
        c = 'B';
        return c;
    }
    return '?';
}

char get_type3(Elf64_Sym sym, Elf64_Shdr *section)
{
    char c;

    if (section[sym.st_shndx].sh_type == SHT_PROGBITS
    && section[sym.st_shndx].sh_flags == SHF_ALLOC) {
        c = 'R';
    } if (section[sym.st_shndx].sh_type == SHT_PROGBITS
    && section[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE)) {
        c = 'D';
        return c;
    } if (section[sym.st_shndx].sh_type == SHT_PROGBITS
    && section[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR)) {
        c = 'T';
        return c;
    } if (section[sym.st_shndx].sh_type == SHT_DYNAMIC) {
        c = 'D';
        return c;
    }
    return '?';
}

char print_type(Elf64_Sym sym, Elf64_Shdr *section)
{
    char c;

    c = get_type(sym, section);
    if (c == '?')
        c = get_type2(sym, section);
    if (c == '?')
        c = get_type2(sym, section);
    if (c == '?')
        c = get_type3(sym, section);
    if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL && c != '?')
        c += 32;
    return c;
}