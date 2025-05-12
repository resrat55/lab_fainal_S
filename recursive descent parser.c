#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

int match(char expected) {
    if (input[pos] == expected) {
        pos++;
        return 1;
    }
    return 0;
}

// B → b | bB
int B() {
    int save = pos;
    if (match('b')) {
        B(); // Optional recursive call for multiple b's
        return 1;
    }
    pos = save;
    return 0;
}

// S → aB
int S() {
    int save = pos;
    if (match('a') && B())
        return 1;
    pos = save;
    return 0;
}

int parse() {
    return S() && input[pos] == '\0';
}

int main() {
    strcpy(input, "abbb");  // You can change the string to test
    if (parse())
        printf("Accepted\n");
    else
        printf("Rejected\n");
    return 0;
}
