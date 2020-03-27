
#ifndef BOARD_H_
#define BOARD_H_
#include <stdlib.h>

#define DIM 9
#define BLANK 0
#define ushort unsigned short

typedef struct _cell_{
	ushort value;
	ushort candidates;			//stored in each bit
	struct _group_* row;							//pointer to the row the cell is in
	struct _group_* col;							//pointer to the column the cell is in
	struct _group_* block;						//pointer to the block the cell is in
}cell;

typedef struct _group_{
	cell *items[DIM];
	ushort solved;						//bit array of solved cells
}group;

typedef struct _board_{
	group rows[DIM];
	group cols[DIM];
	group blocks[DIM];
	cell cells[DIM][DIM];
}board;



/* Allocation functions */
void create_board(ushort cells[DIM][DIM], board *bd);
void _create_cells_(ushort bd[DIM][DIM], cell cells[DIM][DIM]);
void _create_rows_(board* bd, ushort row);								//Assigns one value of rows in the board structure.  (9 total cells)
void _create_cols_(board* bd, ushort col);
void _create_blocks_(board* bd, ushort blk);

#endif /* BOARD_H_ */
