#include "pencils.h"

void setup_pencils(board* bd){
	ushort i,j;
	cell* cur;
	for(i=0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			if(!bd->cells[i][j].value){
				cur = &bd->cells[i][j];
				bd->cells[i][j].candidates = ~(cur->block->solved | cur->row->solved | cur->col->solved);		//deMorgan's law: same as (block')&(row')&(col')
			}
		}
	}
}

void set_cell(cell* C, ushort val){		//Does not check if it is a valid assignment
	C->value = val;				//assignment
	ushort shift = 1<<(val-1);
	C->row->solved  |= shift;
	C->col->solved |= shift;
	C->block->solved |= shift;
	_update_pencils_(C->row);
	_update_pencils_(C->col);
	_update_pencils_(C->block);
}

void _update_pencils_(group* gr){
	ushort i;
	for(i = 0; i < DIM; i++){
		(*(gr->items[i])).candidates &=  ~gr->solved;
	}
}
