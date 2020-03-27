#include "board.h"


void _create_cells_(ushort bd[DIM][DIM], cell cells[DIM][DIM]){
	ushort i,j;
	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			cells[i][j].value = bd[i][j];
			cells[i][j].candidates = 0;
		}
	}
}
void create_board(ushort cells[DIM][DIM], board *bd){
	_create_cells_(cells,bd->cells);
	ushort i;
	for(i = 0; i < 9; i++){
		_create_rows_(bd,i);
		_create_cols_(bd,i);
		_create_blocks_(bd,i);
	}
}

void _create_rows_(board* bd, ushort row){
	ushort i;
	bd->rows[row].solved = 0;
	for(i = 0; i < DIM; i++){
		bd->rows[row].items[i] = &bd->cells[row][i];						// assigns the row pointers
		bd->rows[row].solved |= 1<<(bd->cells[row][i].value - 1);			// creates a binary number representing all solved digits in the row
		bd->cells[row][i].row = &bd->rows[row];
	}
}

void _create_cols_(board* bd, ushort col){
	ushort i;
	bd->cols[col].solved = 0;
	for(i = 0; i < DIM; i++){
		bd->cols[col].items[i] = &bd->cells[i][col];							// assigns the column pointers
		bd->cols[col].solved |= 1<<(bd->cells[i][col].value-1);					// creates a binary number representing all solved digits in column
		bd->cells[i][col].col = &bd->cols[col];
	}
}

void _create_blocks_(board* bd, ushort blk){
	ushort i,j, istart, jstart;
	istart = (blk/3)*3;
	jstart = (blk%3)*3;
	bd->blocks[blk].solved = 0;
	for(i = istart; i < istart+3; i++){
		for(j = jstart; j < jstart+3; j++){
			bd->blocks[blk].items[(i-istart)*3 + j-jstart] = &bd->cells[i][j];	// assigns the block pointers
			bd->blocks[blk].solved |= 1<<(bd->cells[i][j].value-1);				// creates a binary number representing all solved digits in block
			bd->cells[i][j].block = &bd->blocks[blk];
		}
	}
}
