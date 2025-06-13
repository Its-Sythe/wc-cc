#include <stdio.h>

int main() {
    FILE *fptr = fopen("./test.txt", "r");
    int count = 0;
    int ch;

    while(((ch = fgetc(fptr)) != EOF)) {
        if (ch == ' ' && ch != '\n') {
            count++;
        }
    }

    fclose(fptr);
    printf("%d\n", count);
}
