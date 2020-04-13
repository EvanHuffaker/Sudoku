#include "Singles.h"

cell* solve_Naked_Singles(board* bd, cell* start){
    ushort k;
    cell* cur = start;
    while(cur < &bd->cells[DIM-1][DIM-1]){
        k = cur->candidates;
        if(k &&(!(k&(k-1)))) {
            set_cell(cur, log2(k) + 1);
            return cur;
        }
        cur++;
    }
    return NULL;
}

ushort solve_Hidden_Singles(board* bd){
    ushort i,ret=0,blk,rw,cl;
    for(i = 0; i < DIM; i++){
        ret += _find_single_(&bd->blocks[i]);
        ret += _find_single_(&bd->rows[i]);
        ret += _find_single_(&bd->cols[i]);  // if anything was changed, return 1
    }
    return ret;
}
ushort _find_single_(group* gr){
    ushort i,j,k,ret=0;
    cell* cur;
    for(i = 0; i < DIM; i++){                       // Loop through the candidates
        k = 1<<i;
        if(!(gr->solved & k)) {                      // if that candidate is not solved
            cur = NULL;
            for (j = 0; j < DIM; j++) {
                if (gr->items[j]->candidates & k) {
                    if (!cur)                        // ignore warning.  it is false on 2nd time around in j
                        cur = gr->items[j];
                    else
                        goto duplicates;              // Breaks out of j loop
                }
            }
            if (cur) {                                   // unreachable if group had multiple occurances
                set_cell(cur, i + 1);
                ret = 1;
            }
        }
        duplicates:;
    }
    return ret;
}
