#ifndef SNAKE
#define SNAKE 1

#include "stdlib.h"

typedef struct {
    int x;
    int y;
} Point;

typedef enum directions {UP, DOWN, LEFT, RIGHT} direction;

typedef struct {
    int max_size;
    int cur_size;
    int* xs;
    int* ys;
} Snake;


int get_max_size_snake(int W, int H);
Snake* init_snake(int max_size, int W, int H);

void destroy_snake(Snake* snake);
void move_snake(Snake* snake, direction* dir);

#endif