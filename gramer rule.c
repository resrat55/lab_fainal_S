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

// D → bbd
int D() {
    int save = pos;
    if (match('b') && match('b') && match('d'))
        return 1;
    pos = save;
    return 0;
}

// C → aaD
int C() {
    int save = pos;
    if (match('a') && match('a') && D())
        return 1;
    pos = save;
    return 0;
}

// B → bbb
int B() {
    int save = pos;
    if (match('b') && match('b') && match('b'))
        return 1;
    pos = save;
    return 0;
}

// A → aaB | aaba
int A() {
    int save = pos;

    // Try A → aaB
    if (match('a') && match('a') && B())
        return 1;

    pos = save;
    // Try A → aaba
    if (match('a') && match('a') && match('b') && match('a'))
        return 1;

    pos = save;
    return 0;
}

// S → Aa | Ce
int S() {
    int save = pos;

    if (A() && match('a'))
        return 1;

    pos = save;
    if (C() && match('e'))
        return 1;

    pos = save;
    return 0;
}

int parse() {
    return S() && input[pos] == '\0';
}

int main() {
    strcpy(input, "aabbde");  // You can change this input
    if (parse())
        printf("Accepted\n");
    else
        printf("Rejected\n");
    return 0;
}

