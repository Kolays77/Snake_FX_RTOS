#include "snake.h"
#include "game.h"
#include "stdio.h"
#include "math.h"
#include "unistd.h"
#include "signal.h"
#include "time.h"

void logging(Snake* snake, direction st, Point eat_point) {
    printf("Now state : %d. x = %d. y = %d. EAT x = %d y = %d\n", st, snake->xs[0], snake->ys[0], eat_point.x, eat_point.y);
}

int main() {
    int H = 10;
    int W = 10;

    int max_size_snake = get_max_size_snake(W, H);

    Snake* snake = init_snake(max_size_snake, W, H);
 
    State global_state = RUN;
    direction snake_direction = UP;
    int score = 0;

    Point eat_point = generate_eat(snake, W, H);
    
    srand(time(0));

    while (global_state == RUN) {
        show_board();
        
        logging(snake, snake_direction, eat_point);
        wait_and_get_direction(snake, &snake_direction); // sleep 1s
        
        if (is_collision(snake, &snake_direction, W, H)) {
            global_state = FAILED;
        }
        
        move_snake(snake, &snake_direction);
        if (is_eaten(snake, eat_point)) {
            eat_point = generate_eat(snake, W, H);
            score++;
        }

        pause_game(); // if wait_and_get_direction without wait char
    }

    printf("THE END. SCORE = %d \n", score);
    destroy_snake(snake);
    return 0;
}