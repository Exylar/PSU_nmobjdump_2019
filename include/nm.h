/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef PSU_NMOBJDUMP_2019_NM_H
#define PSU_NMOBJDUMP_2019_NM_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <ctype.h>

typedef struct sym_s {
    Elf64_Sym *sym_table;
    uint32_t str_table_index;
    char *string_table;
} sym_t;

typedef struct elf_s {
    Elf64_Ehdr *header;
    Elf64_Shdr *section;
    off_t size;
    void *data;
} elf_t;

typedef struct symbols_s {
    Elf32_Addr value;
    char symbol;
    char *name;
} symbols_t;

void swap(symbols_t **array, int i, int j);
char **sort_array(symbols_t **array, int size);

symbols_t *add_element(elf_t *elf, sym_t *sym, size_t i);
symbols_t **add_element_to_array(symbols_t **array, symbols_t* element);
int get_count_element(symbols_t **array);
symbols_t **init_array(void);

void print_symbols(elf_t *elf, uint32_t symbol_table);
char print_type(Elf64_Sym sym, Elf64_Shdr *section);

void get_section(elf_t *elf);
void fill_structure(char *filename);

void check_format(elf_t *elf);

#endif //PSU_NMOBJDUMP_2019_NM_H
