#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isOperator(char c) {
    char operators[] = "+-*/=";
    for (int i = 0; operators[i] != '\0'; i++) {
        if (c == operators[i]) {
            return true;
        }
    }
    return false;
}

bool isKeyword(char *token) {
    char *keywords[] = {"int", "float", "if", "else", "while", "for", "return"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isIdentifier(char *token) {
    if (isalpha(token[0]) || token[0] == '_') {
        for (int i = 1; token[i] != '\0'; i++) {
            if (!isalnum(token[i]) && token[i] != '_') {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool isConstant(char *token) {
    int i = 0;
    if (token[0] == '-' || token[0] == '+') {
        i = 1;
    }
    for (; token[i] != '\0'; i++) {
        if (!isdigit(token[i]) && token[i] != '.') {
            return false;
        }
    }
    return true;
}

int main() {
    char input[100];
    printf("Enter a C token: ");
    scanf("%s", input);

    if (isKeyword(input)) {
        printf("Token is a keyword.\n");
    } else if (isIdentifier(input)) {
        printf("Token is an identifier.\n");
    } else if (isConstant(input)) {
        printf("Token is a constant.\n");
    } else if (strlen(input) == 1 && isOperator(input[0])) {
        printf("Token is an operator.\n");
    } else {
        printf("Token is not recognized.\n");
    }

    return 0;
}
