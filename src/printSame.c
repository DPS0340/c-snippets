#include <stdio.h>
#include <string.h>

int main(void) {
    char s[400];

    printf("Type your input!\n");

    printf("Your Type: ");
    while(gets(s)) {
        printf("You Typed: %s\n", s);
        printf("Your Type: ");
    }

    return 0;
}