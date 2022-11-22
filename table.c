#include "table.h"
#include "game.h"
#include <sys/queue.h>

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

    node* node_ = (node*)malloc(sizeof(node*)); 
    
    node_->data.x = W/2;
    node_->data.y = H/2;
    node_->next = NULL;

    table->head = node_;
    table->tail = node_;

    table->cur_size_snake = 1;
    table->data[H/2][W/2] = 1;

    return table;
}


void cut_snake(Table* tb) {
    node * temp = tb->tail->next;
    tb->data[tb->tail->data.y][tb->tail->data.x] = 0;
    free(tb->tail);
    tb->tail = temp;
}

void move_snake(Table* tb, direction* dir) {
    node *new_head = (node*)malloc(sizeof(node));

    // TODO optimize return move_point from collision
    Point new_p = move_point__(tb->head->data.x, 
                tb->head->data.y, dir);
    
    new_head->data = new_p;

    tb->data[new_p.y][new_p.x] = 1;

    tb->head->next = new_head; // set new next
    tb->head = tb->head->next;
    tb->head->next = NULL; 

    tb->cur_size_snake++;
}

void destroy_table(Table* tb) {
    
    for (int i = 0 ; i < tb->H; ++i) {
        free(tb->data[i]);
    }
    free(tb->data);

    node * temp = NULL; 
    printf("TAIL : \n");
    while (tb->tail != NULL ) {
        printf("x = %d, y = %d\n", tb->tail->data.x, tb->tail->data.y);
        temp = tb->tail;
        tb->tail = tb->tail->next;
        free(temp);
    }

    free(tb); 
}

