#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NON_TERMINALS 10
#define MAX_RULES 20

// Structure to represent the FIRST set of a non-terminal
struct FirstSet {
    char nonTerminal;
    char first[MAX_NON_TERMINALS];
    int count;
};

// Structure to represent a grammar rule
struct GrammarRule {
    char nonTerminal;
    char production[MAX_RULES];
    int productionLength;
};

// Function to add a terminal to the FOLLOW set
void addToFollow(struct FirstSet followSets[], char nonTerminal, char terminal) {
    int index = nonTerminal - 'A';
    followSets[index].first[followSets[index].count++] = terminal;
}

// Function to calculate the FOLLOW sets
void calculateFollow(struct GrammarRule rules[], int ruleCount, struct FirstSet followSets[], char nonTerminal) {
    for (int i = 0; i < ruleCount; i++) {
        for (int j = 0; j < rules[i].productionLength; j++) {
            if (rules[i].production[j] == nonTerminal) {
                // Case 1: A -> ...B... (nonTerminal B)
                // Add FIRST of everything to the right of B to FOLLOW of B
                int k = j + 1;
                while (k < rules[i].productionLength) {
                    bool hasEpsilon = false;
                    int index = rules[i].production[k] - 'A';

                    // Add FIRST of the symbol to FOLLOW
                    for (int x = 0; x < followSets[index].count; x++) {
                        if (followSets[index].first[x] != 'e') {
                            addToFollow(followSets, nonTerminal, followSets[index].first[x]);
                        } else {
                            hasEpsilon = true;
                        }
                    }

                    // If FIRST of the symbol contains epsilon, move to the next symbol
                    if (!hasEpsilon)
                        break;

                    k++;
                }

                // Case 2: A -> ...B or A -> ...B... (nonTerminal B is the last symbol)
                // Add FOLLOW of A to FOLLOW of B
                if (k == rules[i].productionLength) {
                    calculateFollow(rules, ruleCount, followSets, rules[i].nonTerminal);
                }
            }
        }
    }
}

int main() {
    int ruleCount;
    struct GrammarRule rules[MAX_RULES];
    struct FirstSet followSets[MAX_NON_TERMINALS];

    printf("Enter the number of rules: ");
    scanf("%d", &ruleCount);

    printf("Enter the grammar rules:\n");
    for (int i = 0; i < ruleCount; i++) {
        scanf(" %c -> %[^\n]", &rules[i].nonTerminal, rules[i].production);
        rules[i].productionLength = strlen(rules[i].production);
    }

    // Initialize FOLLOW sets
    for (int i = 0; i < MAX_NON_TERMINALS; i++) {
        followSets[i].nonTerminal = 'A' + i;
        followSets[i].count = 0;
    }

    // Add $ to the FOLLOW set of the start symbol (assumed to be 'S')
    addToFollow(followSets, 'S', '$');

    // Calculate FOLLOW sets for non-terminals
    for (int i = 0; i < MAX_NON_TERMINALS; i++) {
        calculateFollow(rules, ruleCount, followSets, 'A' + i);
    }

    // Print the FOLLOW sets
    printf("FOLLOW sets:\n");
    for (int i = 0; i < MAX_NON_TERMINALS; i++) {
        printf("FOLLOW(%c) = {", followSets[i].nonTerminal);
        for (int j = 0; j < followSets[i].count; j++) {
            printf("%c", followSets[i].first[j]);
            if (j < followSets[i].count - 1) {
                printf(", ");
            }
        }
        printf("}\n");
    }

    return 0;
}
