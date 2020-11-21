/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** array
*/

#include "nm.h"

symbols_t *add_element(elf_t *elf, sym_t *sym, size_t i)
{
    symbols_t *element = malloc(sizeof(symbols_t));

    element->value = sym->sym_table[i].st_value;
    element->symbol = print_type(sym->sym_table[i], elf->section);
    element->name = (sym->string_table + sym->sym_table[i].st_name);
    return element;
}

symbols_t **add_element_to_array(symbols_t **array, symbols_t* element)
{
    int size = get_count_element(array);

    array = realloc(array, sizeof(symbols_t *) * (size + 2));
    array[size] = element;
    array[size + 1] = NULL;
    return array;
}

int get_count_element(symbols_t **array)
{
    int i = 0;

    for (i = 0; array[i] != NULL; i++)
        continue;
    return i;
}

symbols_t **init_array(void)
{
    symbols_t **array = malloc(sizeof(symbols_t *));

    array[0] = NULL;
    return array;
}

void free_array(symbols_t **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}