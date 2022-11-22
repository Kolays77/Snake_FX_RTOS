#include "ascii_gui.h"
#include "ncurses.h"


void show_board(Table* table) {
    clear(); refresh();
    noecho();
    for (int i = 0; i < table->W; ++i) {
        printw("-");
    }
    printw("\n");

    for (int i = 1; i < table->H-1; ++i) {
        printw("|");
        for (int j = 1; j < table->W-1; ++j) {
            if (table->data[i][j] == 0) {
                printw(" ");
            } else { 
                printw("%d", table->data[i][j]);
            }
        }
        printw("|\n");
    }


    for (int i = 0; i < table->W; ++i) {
        printw("-");
    }
    printw("\n");

}
