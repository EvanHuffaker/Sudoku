#include <stdio.h>
#include "board.h"

#ifndef PRINTBOARD_H_
#define PRINTBOARD_H_

void _print_hboarder_();
void _print_vboarder_(cell row[DIM]);
void print_board(cell bd[DIM][DIM]);
#endif /* PRINTBOARD_H_ */
