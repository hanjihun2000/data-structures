#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../stack/stack.h"

/*
*   Application of the infix expression (conventional) caculator.
*/

static void applyOperator(char op, stackADT operandStack) {
    stackElementT lhs, rhs, result;
    rhs = pop(operandStack);
    lhs = pop(operandStack);
    switch (op) {
    case '+': result = lhs + rhs; break;
    case '-': result = lhs - rhs; break;
    case '*': result = lhs * rhs; break;
    case '/': result = lhs / rhs; break;
    }
    push(operandStack, result);
};

// Funtion that compares precedence of two operators 'topop' and 'op'.
// 'flag == 1' means the precedence of 'topop' is greater than or equal to 'op' (topop >= op).
// 'flag == 0' indicates the precedence of 'topop' is less than 'op' (topop < op).
bool comparePrecedence(char topop, char op) {
    bool flag;
    if (topop == '+' || topop == '-') {
        if (op == '+' || op == '-') {
            flag = true;
        }
        else {
            flag = false;
        }
    }
    else if (topop == '*' || topop == '/') {
        flag = true;
    }
    return flag;
};

int main() {
    stackADT operandStack = getEmptyStack();
    stackADT operatorStack = getEmptyStack();
    char op, topop, line[80];
    do {
        scanf("%s", line);
        op = line[0];
        switch (op) {
        case '+': case '-': case '*': case '/':
            if (isStackEmpty(operatorStack)) {
                push(operatorStack, (stackElementT)op);
            }
            else {
                topop = (char)pop(operatorStack);
                if (comparePrecedence(topop, op)) {
                    applyOperator(topop, operandStack);
                    push(operatorStack, (stackElementT)op);
                }
                else {
                    push(operatorStack, (stackElementT)topop);
                    push(operatorStack, (stackElementT)op);
                }
            }
            break;
        case '=':
            while (!isStackEmpty(operatorStack)) {
                applyOperator((char)pop(operatorStack), operandStack);
            }
            printf("%d", pop(operandStack));
            break;
        default:
            // If not operators or '=', push the input into 'operandStack'.
            push(operandStack, atoi(line));
        }
    } while (op != '=');
};
