#include <stdio.h>
#include <string.h>

// Function to perform leftmost derivation
void leftmostDerivation(char* input) {
    char str[100];
    strcpy(str, input);
    printf("Leftmost Derivations:\n");
    printf("Step 1: %s\n", str);

    int step = 2;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'A') {
            str[i] = 'b'; // Apply A -> b
            printf("Step %d: %s\n", step++, str);
            i = -1; // Restart from beginning for leftmost
        } else if (str[i] == 'B') {
            str[i] = 'c'; // Apply B -> c
            printf("Step %d: %s\n", step++, str);
            i = -1;
        }
    }
}

// Function to perform rightmost derivation
void rightmostDerivation(char* input) {
    char str[100];
    strcpy(str, input);
    printf("\nRightmost Derivations:\n");
    printf("Step 1: %s\n", str);

    int step = 2;
    for (int i = strlen(str) - 1; i >= 0; i--) {
        if (str[i] == 'B') {
            str[i] = 'c'; // Apply B -> c
            printf("Step %d: %s\n", step++, str);
            i = strlen(str); // Restart from right
        } else if (str[i] == 'A') {
            str[i] = 'b'; // Apply A -> b
            printf("Step %d: %s\n", step++, str);
            i = strlen(str);
        }
    }
}

int main() {
    char input[50] ; // Initial input string
    gets(input);

    // Perform leftmost and rightmost derivations
    leftmostDerivation(input);
    rightmostDerivation(input);

    return 0;
}
