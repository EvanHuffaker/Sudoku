#include "board.h"


void _create_cells_(unsigned short bd[DIM][DIM], cell cells[DIM][DIM]){
	unsigned short i,j;
	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			cells[i][j].value = bd[i][j];
			cells[i][j].candidates = 0;
		}
	}
}
void create_board(unsigned short cells[DIM][DIM], board *bd){
	_create_cells_(cells,bd->cells);
	int i;
	for(i = 0; i < 9; i++){
		_create_rows_(bd,i);
		_create_cols_(bd,i);
		_create_blocks_(bd,i);
	}
}

void _create_rows_(board* bd, unsigned short row){
	unsigned short i;
	for(i = 0; i < DIM; i++){
		bd->rows[row].items[i] =
				&bd->cells[row][i];
	}
}

void _create_cols_(board* bd, unsigned short col){
	unsigned short i;
	for(i = 0; i < DIM; i++){
		bd->cols[col].items[i] =
				&bd->cells[i][col];
	}
}

void _create_blocks_(board* bd, unsigned short blk){
	unsigned short i,j, istart, jstart;
	istart = (blk/3)*3;
	jstart = (blk%3)*3;
	for(i = istart; i < istart+3; i++){
		for(j = jstart; j < jstart+3; j++){
			bd->blocks[blk].items[(i-istart)*3 + j-jstart] =
					&bd->cells[i][j];
		}
	}
}
