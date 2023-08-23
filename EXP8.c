#include <stdio.h>
#include <ctype.h>

char input[100];
int position = 0;

void E();
void T();
void F();

void match(char c) {
    if (input[position] == c) {
        position++;
    } else {
        printf("Error: Expected '%c' but found '%c'\n", c, input[position]);
    }
}

void E() {
    T();
    while (input[position] == '+') {
        match('+');
        T();
    }
}

void T() {
    F();
    while (input[position] == '*') {
        match('*');
        F();
    }
}

void F() {
    if (isalnum(input[position])) {
        match(input[position]);
    } else if (input[position] == '(') {
        match('(');
        E();
        match(')');
    } else {
        printf("Error: Invalid input '%c'\n", input[position]);
    }
}
int main() {
    printf("Enter an expression: ");
    scanf("%s", input);
    E();  // Start parsing from the top-level non-terminal
    if (input[position] == '\0') {
        printf("Parsing successful!\n");
    } else {
        printf("Error: Extra characters at the end of input\n");
    }
    return 0;
}
