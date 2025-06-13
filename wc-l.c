#include <stdio.h>

int main() {
    FILE *fptr = fopen("./test.txt", "r");
    int count = 0;
    int ch;
    
    if (fptr == NULL) {
        printf("Failed to read the file");
    }

    while ((ch = fgetc(fptr)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    fclose(fptr);
    printf("%d\n", count);
    return 0;
}
