#include <stdio.h>
#include <stdbool.h>

// Function to ignore comments in a line
void ignoreComments(char *line) {
    bool inComment = false;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '/' && line[i + 1] == '/')
            break;
        else if (line[i] == '/' && line[i + 1] == '*')
            inComment = true;
        else if (line[i] == '*' && line[i + 1] == '/')
            inComment = false;

        if (!inComment)
            putchar(line[i]);
    }
}

int main() {
    char line[1000];

    printf("Enter lines of code (Ctrl+Z to end on Windows or Ctrl+D on Unix-like systems):\n");

    while (fgets(line, sizeof(line), stdin)) {
        int length = strlen(line);

        // Remove trailing newline
        if (length > 0 && line[length - 1] == '\n')
            line[length - 1] = '\0';

        // Ignore redundant spaces and tabs, and ignore comments
        ignoreComments(line);

        putchar('\n');
    }

    return 0;
}
