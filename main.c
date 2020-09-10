#include "stdio.h"
#include "stack.h"
#include "time.h"

int main(int argc, char const *argv[]) {
    srand(time(NULL));

    Stack stack = new_stack_();

    for (unsigned i = 0; i < 10; ++i) {
        stack = push(stack, rand() % 100);
    }
    printStack(stack);
    stack = pop(stack);
    stack = pop(stack);
    printStack(stack);
    stack = clear(stack);
    printStack(stack);
    return 0;
}
