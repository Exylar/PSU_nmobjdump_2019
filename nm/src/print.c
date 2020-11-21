/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "nm.h"

void swap(symbols_t **array, int i, int j)
{
    char *ptr;
    int loop_i = 0;
    int loop_j = 0;

    while (array[i]->name[loop_i] == '_')
        loop_i++;
    while (array[j]->name[loop_j] == '_')
        loop_j++;
    while (tolower(array[i]->name[loop_i]) == tolower(array[j]->name[loop_j]) &&
    (array[i]->name[loop_i] != '\0' || array[j]->name[loop_j] != '\0')) {
        loop_i++;
        loop_j++;
    }
    if (tolower(array[i]->name[loop_i]) < tolower(array[j]->name[loop_j])) {
        ptr = array[i];
        array[i] = array[j];
        array[j] = ptr;
    }
    loop_j = 0;
    loop_i = 0;
}

char **sort_array(symbols_t **array, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            swap(array, i, j);
        }
    }
    return array;
}

void dump(symbols_t **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        if (array[i]->value == 0 && array[i]->symbol != 'T')
            printf("\t\t %c %s\n", array[i]->symbol, array[i]->name);
        else
            printf("%016x %c %s\n", array[i]->value,
            array[i]->symbol, array[i]->name);
    }
}

void print_symbols(elf_t *elf, uint32_t symbol_table)
{
    sym_t *sym = malloc(sizeof(sym_t));
    symbols_t **array = init_array();

    sym->sym_table = (Elf64_Sym *)(elf->data +
    elf->section[symbol_table].sh_offset);
    sym->str_table_index = elf->section[symbol_table].sh_link;
    sym->string_table = (char *)(elf->data +
    elf->section[sym->str_table_index].sh_offset);
    for (size_t i = 0; i < elf->section[symbol_table].sh_size /
    sizeof(Elf64_Sym); i++) {
        if (strcmp("", sym->string_table + sym->sym_table[i].st_name) != 0 &&
        print_type(sym->sym_table[i], elf->section) != 'a') {
            array = add_element_to_array(array, add_element(elf, sym, i));
        }
    }
    array = sort_array(array, get_count_element(array));
    dump(array);
    free_array(array);
    free(sym);
}