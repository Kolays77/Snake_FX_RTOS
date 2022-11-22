#include "game.h"
#include <unistd.h>
#include "stdio.h"
#include "time.h"
#include "ncurses.h"
#include "stdbool.h"

void wait_and_get_direction(Table* table, direction* snake_direction) {
    // TODO :
    noecho();

    char char_dir = getch();
    switch (char_dir) {
    case 'w':
        *snake_direction = UP;
        break;
    case 'a':
        *snake_direction = LEFT;
        break;
    case 'd':
        *snake_direction = RIGHT;
        break;
    case 's':
        *snake_direction = DOWN;
        break;
    default:
        break;
    }
}

Point move_point__(int x, int y, direction* dir) {
    Point p;
    p.x = x;
    p.y = y;
    switch (*dir) {
        case UP:
            p.y--;
            break;
        case DOWN:
            p.y++;
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
    Point temp = move_point__(table->head->data.x, table->head->data.y, dir_snake);
    if (temp.x == table->tail->data.x && 
        temp.y == table->tail->data.y) 
            return 0;

    if (temp.x <= 0 || 
        temp.x >= table->W-1 || 
        temp.y <= 0 || 
        temp.y >= table->H-1 || 
        table->data[temp.y][temp.x] == 1) 
        return 1;  

    return 0;
}

void pause_game() {
    usleep(60000);
}

Point generate_eat(Table* table) { 
    // TODO  add feature : target != snake position
    // TODO optimization
    
    Point p;
    p.x = 1 + rand() % (table->W - 2);
    p.y = 1 + rand() % (table->H - 2);

    printw("random : x = %d y = %d\n", p.x, p.y);

    while (table->data[p.y][p.x] == 1) {
        p.x = 1 + rand() % (table->W - 2);
        p.y = 1 + rand() % (table->H - 2);
    }
    table->data[p.y][p.x] = 2;
    return p;
};

// after move
int is_eaten(Table* table, Point p_eat) {
    if (table->head->data.x == p_eat.x && table->head->data.y == p_eat.y) {
        return 1;
    }  else {
        return 0;
    }
}