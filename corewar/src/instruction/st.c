/*
** EPITECH PROJECT, 2020
** st.c
** File description:
** Coline SEGURET's st.c made the 05/15/2020
*/

#include "vm_prototypes.h"
#include "champ_struct.h"

void st(vm_t *vm, elem_t *champs)
{
    unsigned char params[4] = {0};
    unsigned char coding_byte = 0;
    int value = 0;
    int ind = 0;

    champs->instruction_cycles = 5;
    champs->index_actual += 1;
    coding_byte = vm->mem[champs->index_actual];
    set_param_with_byte(coding_byte, params);
    champs->index_actual += 1;

    value = champs->reg[get_index_reg(vm, champs)];
    if (params[1] == REG)
        champs->reg[get_index_reg(vm, champs)] = value;
    else if (params[1] == IND) {
        ind = get_indirect(vm, champs);
        for (int i = 0; i < 4; i += 1) {
            //écrire les 4 byte de la value a partir de l'addresse pc + ind %IDX_MOD
        }
    }
}
