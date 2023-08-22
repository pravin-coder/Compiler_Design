#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// Structure to represent an entry in the symbol table
struct SymbolEntry {
    char name[50];
    int type; // You can extend this to include more attributes
    // Add more attributes as needed
    struct SymbolEntry* next; // For handling collisions in the hash table
};

// Initialize an array of linked lists (hash table)
struct SymbolEntry* symbolTable[SIZE];

// Function to hash a string and return an index
int hash(char* name) {
    int sum = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        sum += name[i];
    }
    return sum % SIZE;
}

// Function to insert an entry into the symbol table
void insert(char* name, int type) {
    int index = hash(name);

    // Create a new symbol entry
    struct SymbolEntry* newEntry = (struct SymbolEntry*)malloc(sizeof(struct SymbolEntry));
    strcpy(newEntry->name, name);
    newEntry->type = type;
    newEntry->next = NULL;

    // Check if there's already an entry at this index
    if (symbolTable[index] == NULL) {
        symbolTable[index] = newEntry;
    } else {
        // Handle collision by chaining (adding to the linked list)
        struct SymbolEntry* current = symbolTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newEntry;
    }
}

// Function to search for an entry in the symbol table
struct SymbolEntry* search(char* name) {
    int index = hash(name);
    struct SymbolEntry* current = symbolTable[index];

    // Traverse the linked list to find the entry
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL; // Entry not found
}

// Function to delete an entry from the symbol table
void deleteEntry(char* name) {
    int index = hash(name);
    struct SymbolEntry* current = symbolTable[index];
    struct SymbolEntry* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                // Entry is the first in the list
                symbolTable[index] = current->next;
            } else {
                // Entry is not the first in the list
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Entry not found for deletion: %s\n", name);
}

int main() {
    // Insert some entries into the symbol table
    insert("variable1", 1);
    insert("variable2", 2);
    insert("function1", 3);

    // Search for an entry
    struct SymbolEntry* entry = search("variable1");
    if (entry != NULL) {
        printf("Found: %s (Type: %d)\n", entry->name, entry->type);
    } else {
        printf("Entry not found.\n");
    }

    // Delete an entry
    deleteEntry("variable1");

    // Search again after deletion
    entry = search("variable1");
    if (entry != NULL) {
        printf("Found: %s (Type: %d)\n", entry->name, entry->type);
    } else {
        printf("Entry not found after deletion.\n");
    }

    return 0;
}
