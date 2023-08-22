#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isComment(char *line) {
    // Check if the line starts with // or /*
    if (strncmp(line, "//", 2) == 0 || strncmp(line, "/*", 2) == 0) {
        return true;
    }
    
    // Check if the line ends with */
    int len = strlen(line);
    if (len >= 2 && strncmp(line + len - 2, "*/", 2) == 0) {
        return true;
    }
    
    return false;
}

int main() {
    char line[1000];
    
    printf("Enter a line of code: ");
    fgets(line, sizeof(line), stdin);
    
    if (isComment(line)) {
        printf("The given line is a comment.\n");
    } else {
        printf("The given line is not a comment.\n");
    }
    
    return 0;
}
