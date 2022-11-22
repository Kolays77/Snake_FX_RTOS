#include "table.h"
#include "game.h"
#include "stdio.h"
#include "math.h"
#include "unistd.h"
#include "signal.h"
#include "time.h"
#include <ncurses.h>

//optional 
#include "ascii_gui.h"


int main() {
    int H = 5;
    int W = 5;
    initscr();
    //  

    int max_size_snake  = get_max_size_snake(W, H);
    Table * table_game  = init_table (max_size_snake , W, H);
 
    State global_state = RUN;
    direction snake_direction = UP;
    int score = 0;

    srand(time(NULL));
    Point eat_point = generate_eat(table_game);
    

    while (global_state == RUN) {
        show_board(table_game);
        wait_and_get_direction(table_game , &snake_direction); // sleep 1s

        if (is_collision(table_game , &snake_direction)) {   
            global_state = FAILED;
            break;
        }

        move_snake(table_game, &snake_direction);

        if (is_eaten(table_game , eat_point)) {
            eat_point = generate_eat(table_game);
            score++;
        } else {
            cut_snake(table_game);
        }
        
        if (score == max_size_snake ) {
            global_state = WIN;
        }
        pause_game();
    }

    endwin();
    destroy_table(table_game);

    if (global_state == WIN) {
        printf("Congrats! YOU ARE WIN! SCORE = %d \n", score);
    } else {
        printf("THE END. SCORE = %d \n", score);
    }
    



    return 0;
}