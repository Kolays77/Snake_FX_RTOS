#ifndef GAME
#define GAME 1

#include "table.h"

typedef enum State {RUN, WIN, FAILED} State;

void pause_game();
void wait_and_get_direction(Table* Table, direction*  snake_direction);

Point move_point__(int x, int y, direction* dir);

int is_collision(Table * Table , direction* snake_direction);
int is_eaten(Table * Table , Point p_eat);

Point generate_eat(Table * table);

#endif