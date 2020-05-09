/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** init_champ.c
*/

#include <stdlib.h>
#include "corewar.h"
#include <string.h>

elem_t *add_elem(char *str, int n, int a, elem_t *actual)
{
    elem_t *node = malloc(sizeof(elem_t));

    if (node == NULL)
        return (NULL);
    node->next = actual;
    node->instruction_cycles = 0;
    node->name = str;
    node->progNumber = n;
    node->address = a;
    for (int i = 0; i < REG_NUMBER; i += 1)
        node->reg[i] = 0;
    node->before = NULL;
    if (actual != NULL)
        actual->before = node;
    return (node);
}

elem_t *param_list(char *str, int n, int a)
{
    elem_t *actual = NULL;

    actual = add_elem(str, n, a, actual);
    return (actual);
}