#ifndef SNAKE
#define SNAKE 1

#include "stdlib.h"

typedef struct {
    int x;
    int y;
} Point;
//                       0   1      2     3 
typedef enum directions {UP, DOWN, LEFT, RIGHT} direction;

// 0 - nothing, 1 - snake, 2 - food;

typedef struct {
    int cur_size_snake;
    int** data;
    Point head_snake;
    Point tail_snake;
    int W, H;
} Table;


int get_max_size_snake(int W, int H);
Table* init_table(int max_size, int W, int H);

void destroy_table(Table* table);
void move_snake(Table* tb, direction* dir);

#endif