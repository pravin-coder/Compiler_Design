#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_SYMBOLS 10

// Structure to represent a production rule
typedef struct {
    char nonTerminal;
    char production[MAX_SYMBOLS];
} ProductionRule;

ProductionRule rules[MAX_RULES];
int ruleCount = 0;

// Function to add a production rule to the grammar
void addRule(char nonTerminal, char production[MAX_SYMBOLS]) {
    rules[ruleCount].nonTerminal = nonTerminal;
    strcpy(rules[ruleCount].production, production);
    ruleCount++;
}

// Function to calculate the FIRST() set for a non-terminal symbol
void calculateFirst(char symbol) {
    printf("FIRST(%c) = { ", symbol);

    for (int i = 0; i < ruleCount; i++) {
        if (rules[i].nonTerminal == symbol) {
            char firstSymbol = rules[i].production[0];

            if (firstSymbol >= 'A' && firstSymbol <= 'Z') {
                // Recursive call to calculate FIRST() for non-terminals
                calculateFirst(firstSymbol);
            } else {
                // Terminal symbol
                printf("%c ", firstSymbol);
            }
        }
    }

    printf("}\n");
}

int main() {
    // Example grammar rules
    addRule('A', "aBC");
    addRule('B', "bB");
    addRule('B', "epsilon");
    addRule('C', "cC");
    addRule('C', "epsilon");

    // Calculate FIRST() sets for each non-terminal
    calculateFirst('A');
    calculateFirst('B');
    calculateFirst('C');

    return 0;
}
