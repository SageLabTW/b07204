#include<stdlib.h>
#include"stack.h"

void push(struct stack* this, int x) {
    if (this->size < STACK_SIZE) {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = x;
	new_node->next_node = this->top_node;
	this->top_node = new_node;
	this->size++;
    }
}

int pop(struct stack* this) {
    int pop_data = this->top_node->data;
    if (this->size > 0) {
        struct node* temp = this->top_node;
	this->top_node = this->top_node ->next_node;
	free(temp);
	this->size--;
    }
    return pop_data;
}

struct stack* new_stack() {
    struct stack* stk = (struct stack*)malloc(sizeof(struct stack));
    struct node* start = (struct node*)malloc(sizeof(struct node));
    start->data = -1;
    start->next_node = NULL;
    stk->top_node = start;
    stk->size = 0;
    return stk;
}

void delete_stack(struct stack* stk) {
    for (int i = 0; i < stk->size; i++) {
        free(stk->top_node);
        stk->top_node = stk->top_node->next_node;
    }
}
