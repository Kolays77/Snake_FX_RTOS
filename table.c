#include "table.h"

int get_max_size_snake(int W, int H) {
    return (H-2) * (W-2) - 1;
}

Table* init_table(int max_size, int W, int H) {
    
    Table* table = (Table*)malloc(sizeof(Table));
    table->W = W;
    table->H = H;

    table->data = (int**)malloc(sizeof(int*) * H);
    for (int i = 0; i < H; ++i) {
        table->data[i] = (int*)calloc(W, sizeof(int));
    }
 
    table->head_snake.y = H/2;
    table->head_snake.x = W/2;

    table->cur_size_snake = 1;
    table->data[table->head_snake.y][table->head_snake.x] = 1;

    return table;
}

void move_snake(Table* tb, direction* dir) {
    switch (*dir) {
    case UP:
        tb->data[++tb->head_snake.y][tb->head_snake.x] = 1;
        break;
    case DOWN:
        tb->data[--tb->tail_snake.y][tb->tail_snake.x] = 1;
        break;
    case LEFT:
        tb->data[tb->tail_snake.y][--tb->tail_snake.x] = 1;
        break;
    case RIGHT:
        tb->data[tb->tail_snake.y][++tb->tail_snake.x] = 1;
        break;
    }

    tb->data[tb->tail_snake.y][tb->tail_snake.x] = 0;
}

void destroy_table(Table* tb) {
    for (int i = 0 ; i < tb->H; ++i) {
        free(tb->data[i]);
    }

    free(tb->data);
    free(tb); tb = NULL; // ?
}

