#ifndef PENCILS_H_
#define PENCILS_H_
#include "board.h"

void setup_pencils(board* bd);


void set_cell(cell* C, ushort val);		//sets the value of a cell and updates pencil marks
void _update_pencils_(group* gr);
#endif /* PENCILS_H_ */
