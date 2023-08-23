#include <stdio.h>
#include <stdbool.h>

// Structure to represent an expression
typedef struct {
    char operator;
    int operand1;
    int operand2;
    int result;
    bool calculated;
} Expression;

// Function to evaluate an expression
int evaluate(Expression* exp) {
    if (exp->calculated) {
        return exp->result;
    }

    switch (exp->operator) {
        case '+':
            exp->result = exp->operand1 + exp->operand2;
            break;
        case '-':
            exp->result = exp->operand1 - exp->operand2;
            break;
        case '*':
            exp->result = exp->operand1 * exp->operand2;
            break;
        case '/':
            if (exp->operand2 != 0) {
                exp->result = exp->operand1 / exp->operand2;
            } else {
                printf("ERROR: Division by zero\n");
            }
            break;
        default:
            printf("ERROR: Invalid operator\n");
            break;
    }

    exp->calculated = true;
    return exp->result;
}

int main() {
    Expression exp1 = { '+', 5, 3, 0, false };
    Expression exp2 = { '-', 8, 2, 0, false };

    int result1 = evaluate(&exp1);
    int result2 = evaluate(&exp2);

    printf("Result 1: %d\n", result1);
    printf("Result 2: %d\n", result2);

    return 0;
}
