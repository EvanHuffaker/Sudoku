
#ifndef SINGLES_H_
#define SINGLES_H_
#include "pencils.h"
#include "board.h"

cell* solve_Naked_Singles(board* bd,cell* start);
ushort solve_Hidden_Singles(board* bd);
ushort _find_single_(group* gr);

#endif /* SINGLES_H_ */
