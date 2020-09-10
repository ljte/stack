#ifndef STACK
#define STACK

#include "stdlib.h"

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    int length;
} Stack;

Node* new_node_(const int val, Node* next);
Stack new_stack_(void);
Stack push(Stack stack, const int val);
Stack pop(Stack stack);
Node* top(Stack stack);
Stack clear(Stack stack);
void printStack(Stack stack);

#endif
