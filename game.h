#ifndef GAME
#define GAME 1

#include "snake.h"

typedef enum State {RUN, WIN, FAILED} State;

void pause_game();
void wait_and_get_direction(Snake* snake, direction* snake_direction);

int is_collision(Snake* snake, direction* snake_direction, int H, int W);
int is_eaten(Snake* snake, Point p_eat);

Point generate_eat(Snake* snake, int W, int H);

void show_board();

#endif