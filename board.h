
#ifndef BOARD_H_
#define BOARD_H_
#include <stdlib.h>

#define DIM 9
#define BLANK 0

typedef struct _cell_{
	unsigned short value;
	unsigned short candidates;			//stored in each bit
}cell;

typedef struct _group_{
	cell* items[DIM];
}group;

typedef struct _board_{
	group rows[DIM];
	group cols[DIM];
	group blocks[DIM];
	cell cells[DIM][DIM];
}board;



/* Allocation functions */
void create_board(unsigned short cells[DIM][DIM], board *bd);
void _create_cells_(unsigned short bd[DIM][DIM], cell cells[DIM][DIM]);
void _create_rows_(board* bd, unsigned short row);								//Assigns one value of rows in the board structure.  (9 total cells)
void _create_cols_(board* bd, unsigned short col);
void _create_blocks_(board* bd, unsigned short blk);
#endif /* BOARD_H_ */
