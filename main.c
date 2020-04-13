#include <stdio.h>
#include <stdlib.h>
#include "printBoard.h"
#include "board.h"
#include "Singles.h"
#include <sys/time.h>

int main(void) {
    struct timeval stop,start;
    gettimeofday(&start,NULL);
	unsigned short nums[DIM][DIM] = {
            {5,0,4,0,0,3,9,1,0},
            {1,0,0,0,0,0,0,0,0},
            {0,3,6,5,0,7,0,0,0},
            {0,0,5,6,0,0,0,0,0},
            {3,4,0,0,0,0,0,7,8},
            {0,0,0,0,0,8,5,0,0},
            {0,0,0,1,0,4,7,5,0},
            {0,0,0,0,0,0,0,0,2},
            {0,6,9,7,0,0,8,0,1}
	};
	board bd;
	int steps = 0;
	cell* cur = &bd.cells[0][0];
	ushort t = 1;
	create_board(nums,&bd);
	setup_pencils(&bd);
	//print_board(bd.cells);
	printf("\n");
	while(cur){
	    steps++;
	    cur = solve_Naked_Singles(&bd,cur->row->items[0]);
	    //print_board(bd.cells);
	}
	steps--;
    //printf("Hidden Singles\n");

    while(t){
        steps++;
	    t = solve_Hidden_Singles(&bd);
        //print_board(bd.cells);
    }
    steps--;

    printf("Steps: %d\n",steps);
    gettimeofday(&stop,NULL);
    printf("Time: %lu\n",stop.tv_usec - start.tv_usec);
	return EXIT_SUCCESS;
}

