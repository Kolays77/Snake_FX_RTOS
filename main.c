#include "table.h"
#include "game.h"
#include "stdio.h"
#include "math.h"
#include "unistd.h"
#include "signal.h"
#include "time.h"

#include "ascii_gui.h"


// void logging(Table * Table , direction st, Point eat_point) {
//     printf("Now state : %d. x = %d. y = %d. EAT x = %d y = %d\n", st, Table ->xs[0], Table ->ys[0], eat_point.x, eat_point.y);
// }

int main() {
    int H = 20;
    int W = 20;

    //  

    int max_size_snake  = get_max_size_snake(W, H);

    Table * table_game  = init_table (max_size_snake , W, H);
 
    State global_state = RUN;
    direction snake_direction = UP;
    int score = 0;

    srand(time(NULL));
    Point eat_point = generate_eat(table_game);
    
    int max_iter = 10000;
    int iter = 0;


    while (global_state == RUN) {
        if (iter >= max_iter) { ++iter; global_state = FAILED; }

        show_board(table_game);
        
    //     // logging(Table , Table _direction, eat_point);
        wait_and_get_direction(table_game , &snake_direction); // sleep 1s
        
        if (is_collision(table_game , &snake_direction)) {
            global_state = FAILED;
        }
        
        if (is_eaten(table_game , eat_point)) {
            eat_point = generate_eat(table_game);
            score++;
            move_snake (table_game , &snake_direction, 1);
        } else {
            move_snake (table_game , &snake_direction, 0);
        }
        
    
        if (score == max_size_snake ) {
            global_state = WIN;
        }
        pause_game(); // if wait_and_get_direction without wait char
    }

    destroy_table(table_game);

    if (global_state == WIN) {
        printf("Congrats! YOU ARE WIN! SCORE = %d \n", score);
    } else {
        printf("THE END. SCORE = %d \n", score);
    }
    return 0;
}