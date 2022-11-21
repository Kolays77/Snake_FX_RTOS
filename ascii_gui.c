#include "ascii_gui.h"



void show_board(Table* table) {
    for (int i = 0; i < table->W; ++i) {
        printf("-");
    }
    printf("\n");

    for (int i = 0; i < table->H-2; ++i) {
        printf("|");
        for (int j = 0; j < table->W-2; ++j) {
            if (table->data[i][j] == 0) {
                printf(" ");
            } else { 
                printf("%d", table->data[i][j]);
            }
        }
        printf("|\n");
    }


    for (int i = 0; i < table->W; ++i) {
        printf("-");
    }
    printf("\n");

}
