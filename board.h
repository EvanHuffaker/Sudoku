
#ifndef BOARD_H_
#define BOARD_H_
#include <stdlib.h>

#define DIM 9
#define BLANK 0

typedef struct _cell_{
	unsigned short value;
	unsigned short candidates;			//stored in each bit
}cell;




/* Allocation functions */
void create_board(unsigned short cells[DIM][DIM]);
void _create_cells_(unsigned short bd[DIM][DIM], cell cells[DIM][DIM]);
#endif /* BOARD_H_ */
