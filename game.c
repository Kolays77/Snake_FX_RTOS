#include "game.h"
#include <unistd.h>
#include "stdio.h"
#include "time.h"
void wait_and_get_direction(Snake* snake, direction* snake_direction) {
    // TODO :
    // srand(time(0));
    *snake_direction = (direction)(rand() % 4);

    // Example
    // if (getchar() == '\033') { // if the first value is esc
    //     getchar(); // skip the [

    //     switch(getchar()) { // the real value
    //     case 65:    // key up
    //         *snake_direction = UP;
    //         break;
    //     case 66:    // key down
    //         *snake_direction = DOWN;
    //         break;
    //     case 67:    // key right
    //         *snake_direction = RIGHT;
    //         break;
    //     case 68:    // key left
    //         *snake_direction = LEFT;
    //         break;
    //     }   
    // }
}

int is_collision(Snake* snake, direction* dir_snake, int W, int H) {
    // TODO : add collition with snake's body 
    switch (*dir_snake) {
    case UP:
        if (snake->ys[0] + 1 == H) return 1; 
        break;
    case DOWN:
        if (snake->ys[0] - 1 == 0) return 1; 
        break;
    case LEFT:
        if (snake->xs[0] - 1 == 0) return 1; 
        break;
    case RIGHT:
        if (snake->xs[0] + 1 == W) return 1; 
        break;
    }
    return 0;

}

void pause_game() {
    sleep(0.1);
}

void show_board() {
    // TODO 
    
}

Point generate_eat(Snake* snake, int W, int H) { 
    // TODO 
    Point p;
    p.x = 1 + rand() % (W - 2);
    p.y = 1 + rand() % (H - 2);
    return p;
};

int is_eaten(Snake* snake, Point p_eat) {
    if (snake->xs[0] == p_eat.x && snake->ys[0] == p_eat.y) 
        return 1;
    else 
        return 0;
}