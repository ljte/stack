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

Node* new_node_(const int val, Node* next) {
    Node* new_node = (Node*)malloc(sizeof(new_node));

    new_node->val = val;
    new_node->next = next;

    return new_node;
}

Stack new_stack_(void) {
    Stack new_stack;

    new_stack.top = NULL;
    new_stack.length = 0;

    return new_stack;
}

Stack push(Stack stack, const int val) {
    if (!stack.top) {
        stack.top = new_node_(val, NULL);
    }
    else {
        stack.top = new_node_(val, stack.top);
    }
    stack.length++;
    return stack;
}

Stack pop(Stack stack) {
    if (stack.length == 1) {
        free(stack.top);
        stack.top = NULL;
    }
    else {
        Node* temp = stack.top;
        stack.top = stack.top->next;
        free(temp);
        temp = NULL;
    }
    stack.length--;
    return stack;
}

Node* top(Stack stack) {
    return stack.top;
}

void printStack(Stack stack) {
    if(stack.length == 0) {
        printf("Empty stack");
    }
    else {
        Node* temp = stack.top;
        while(temp) {
            printf("%d ", temp->val);
            temp = temp->next;
        }
    }
    printf("\n");
}

Stack clear(Stack stack) {
    while(stack.top) {
        stack = pop(stack);
    }
    return stack;
}

#endif
