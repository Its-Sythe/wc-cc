#include <stdio.h>

int main() {
    FILE *fptr = fopen("./test.txt", "r");
    int count = 0;
    int ch;
    while ((ch = fgetc(fptr)) != EOF) {
        count++;
    }
    fclose(fptr);
    printf("Characters: %d\n", count);
    return 0;
}