#include "game.h"
#include <unistd.h>
#include "stdio.h"
#include "time.h"

#include "stdbool.h"

void wait_and_get_direction(Table* table, direction* snake_direction) {
    // TODO :
    *snake_direction = (direction)(rand() % 4);
}

Point move_point__(int x, int y, direction* dir) {
    Point p;
    p.x = x;
    p.y = y;
    switch (*dir) {
        case UP:
            p.y++;
            break;
        case DOWN:
            p.y--;
            break;
        case LEFT:
            p.x--;
            break;
        case RIGHT:
            p.x++;
            break;
    }
    return p;
}

int is_collision(Table* table, direction* dir_snake) {
    // TODO : add collition with snake's body 
    Point temp = move_point__(table->head_snake.x, table->head_snake.y, dir_snake);
    if (temp.x == 0 || temp.x == table->W || temp.y == 0 || temp.y == table->H) return 1;  
    return 0;
}

void pause_game() {
    sleep(0.1);
}





Point generate_eat(Table* table) { 
    // TODO  add feature : target != snake position
    // TODO optimization
    
    Point p;
    p.x = 1 + rand() % (table->W - 2);
    p.y = 1 + rand() % (table->H - 2);

    //if (table->cur_size_snake > get_max_size_snake(table->W, table->H) / 2) {
    printf("random : x = %d y = %d\n", p.x, p.y);

    while (table->data[p.x][p.y]) {
        p.x = 1 + rand() % (table->W - 2);
        p.y = 1 + rand() % (table->H - 2);
    }
    table->data[p.y][p.x] = 2;
    return p;
};

// after move
int is_eaten(Table* table, Point p_eat) {
    if (table->head_snake.x == p_eat.x && table->head_snake.y == p_eat.y) {
        return 1;
    }  else {
        return 0;
    }
}