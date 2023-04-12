#include <stdlib.h>
#include "stack.h"

struct stackCDT {
    stackElementT* elements;
    int count;
    int size;
};

stackADT getEmptyStack(void) {
    stackADT stack;
    stack = (stackADT)malloc(sizeof(*stack));
    stack->elements = (stackElementT*)malloc(5 * sizeof(stackElementT));
    stack->count = 0;
    stack->size = 5;
    return stack;
};

void push(stackADT stack, stackElementT element) {
    // Automatically increase the size of a stack if a stack is full.
    if (stack->count == stack->size) {
        stack->size += 5;
        stack->elements = (stackElementT*)realloc(stack->elements, (stack->size) * sizeof(stackElementT));
    }
    stack->elements[(stack->count)++] = element;
};

stackElementT pop(stackADT stack) {
    stackElementT result;
    if (isStackEmpty(stack)) {
        exit(EXIT_FAILURE);
    }
    result = stack->elements[--(stack->count)];
    // On the other hand, automatically decrease the size of a stack if it has too enough space.
    // It is always beneficial to set the proper size of a stack for efficient memory usage.
    if (stack->count <= stack->size - 5) {
        stack->size -= 5;
        stack->elements = (stackElementT*)realloc(stack->elements, (stack->size) * sizeof(stackElementT));
    }
    return result;
};

int getStackDepth(stackADT stack) {
    return stack->count;
};

int isStackEmpty(stackADT stack) {
    return stack->count == 0;
};
