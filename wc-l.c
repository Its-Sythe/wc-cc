#include <stdio.h>

int main() {
    FILE *fptr;
    fptr = fopen("./test.txt", "r");

    int count = 0;
    int ch;

    if (fptr != NULL) {
        while ((ch = fgetc(fptr)) != EOF) {
            if (ch == '\n') {
                count++;
            }
        }
    } else {
        printf("Not able to open the file");
    } 

    fclose(fptr);
    printf("%d\n", count);

   return 0;
}
