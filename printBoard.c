#include "printBoard.h"


void _print_hboarder_(){
    int i;
    for(i = 0; i < 3; i++){
        printf("+---");
    }
    printf("+\n");
}

void _print_vboarder_(cell row[DIM]){
    int i;
    for(i = 0; i < 9; i++){
        if(!(i%3))
            printf("|");
        if(row[i].value)
            printf("%d",row[i].value);
        else
            printf("-");
    }
    printf("|\n");
}

void print_board(cell bd[DIM][DIM]){
    int i;
    for(i = 0; i < 9; i++){
        if(!(i%3))
            _print_hboarder_();
        _print_vboarder_(bd[i]);
    }
    _print_hboarder_();
    printf("\n");
}
