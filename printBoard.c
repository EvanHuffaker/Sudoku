#include "printBoard.h"


void _print_hboarder_(){
	int i;
	for(i = 0; i < 9; i++){
		if(!(i%3))
			printf("+");
		printf("+---");
	}
	printf("++\n");
}

void _print_vboarder_(group* row){
	int i;
	group* cur = row;
	cell* curC;
	for(i = 0; i < 9; i++){
		if(!(i%3))
			printf("||");
		curC = *(cur->items+i);
		if(curC->value)
			printf("%d",curC->value);
		else
			printf("-");
	}
	printf("||");
}

void print_board(board* bd){
	int i;
	for(i = 0; i < 9; i++){
		if(!(i%3))
			_print_hboarder_();
		_print_vboarder_(bd->rows+i);
	}
}
