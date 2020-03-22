#include "board.h"


void _create_cells_(unsigned short bd[DIM][DIM], cell cells[DIM][DIM]){
	int i,j;
	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			cells[i][j].value = bd[i][j];
			cells[i][j].candidates = 0;
		}
	}
}
