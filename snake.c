#include "snake.h"

int get_max_size_snake(int W, int H) {
    return (H-2) * (W-2) - 1;
}

Snake* init_snake(int max_size, int W, int H) {
    Snake* snake = (Snake*)malloc(sizeof(Snake));
    snake->xs = (int*)malloc(sizeof(int)*max_size);
    snake->ys = (int*)malloc(sizeof(int)*max_size);
    snake->max_size = max_size;
    snake->cur_size = 1;

    snake->xs[0] = W/2;
    snake->ys[0] = H/2;

    return snake;
}

void move_snake(Snake* snake, direction* dir) {
    switch (*dir) {
    case UP:
        snake->ys[0]++;
        break;
    case DOWN:
        snake->ys[0]--;
        break;
    case LEFT:
        snake->xs[0]--;
        break;
    case RIGHT:
        snake->xs[0]++;
        break;
    }
}

void destroy_snake(Snake* snake) {
    free(snake->xs);
    free(snake->ys);
    free(snake);
}

