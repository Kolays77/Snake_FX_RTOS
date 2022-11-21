#ifndef SNAKE
#define SNAKE 1

#include "stdlib.h"
#include "stdio.h"
typedef struct {
    int x;
    int y;
} Point;
//                       0   1      2     3 
typedef enum directions {UP, DOWN, LEFT, RIGHT} direction;

// 0 - nothing, 1 - snake, 2 - food;

typedef struct node {
    Point data;
    struct node *next;
} node;


typedef struct {
    int cur_size_snake;
    int** data;
    node* head;
    node* tail;
    int W, H;
} Table;



Table* init_table(int max_size, int W, int H);
int get_max_size_snake(int W, int H);

void destroy_table (Table* table);
void move_snake(Table* tb, direction* dir, int is_grow);

#endif