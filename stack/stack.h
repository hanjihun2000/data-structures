#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct stackCDT* stackADT;
// Define stack element type as integer.
// You can change it to whatever type (e.g. char or bool) you want to store in a stack data structure.
typedef int stackElementT;

stackADT getEmptyStack(void);
void push(stackADT stack, stackElementT element);
stackElementT pop(stackADT stack);
int getStackDepth(stackADT stack);
int isStackEmpty(stackADT stack);

#endif // STACK_H_INCLUDED
