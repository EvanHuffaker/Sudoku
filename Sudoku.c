#include <stdio.h>
#include <stdlib.h>
#include "printBoard.h"
#include "board.h"

int main(void) {
	unsigned short bd[DIM][DIM] =
	{{5,6,9,2,0,0,0,0,0},
			{2,8,0,6,1,5,4,0,9},
			{4,1,0,0,8,9,5,2,6},
			{0,0,6,8,0,7,2,0,0},
			{0,0,8,0,0,0,0,0,0},
			{0,0,4,5,0,1,9,0,0},
			{8,9,2,1,0,0,0,4,5},
			{6,0,1,4,5,2,0,9,0},
			{0,4,5,0,0,8,6,1,2}
	};
	cell A[DIM][DIM];
	 _create_cells_(bd,A);
	printf("%d",A[0][0].value);
	return EXIT_SUCCESS;
}
