#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char *command = argv[1];
    char *filename = argv[2];
    if (command != NULL && filename != NULL) {
        FILE *fptr = fopen(filename, "r");
        if (fptr == NULL) {
            printf("File was not opened successfully");
        } else {
            int ch;
            int count = 0;
            while ((ch = fgetc(fptr)) != EOF) {
                if (strcmp(command, "-c") == 0) {
                    count ++;
                } else if (strcmp(command, "-l") == 0) {
			if (ch == '\n') {
				count++;
			}
		} else if (strcmp(command, "-w") == 0) {
			int inword = 0;
			if (!isspace(ch)) {
				if (!inword) {
					count++;
					inword = 1;
				}
			} else {
				inword = 0;
			}
		}
	    }
            printf("%d\n", count);
        }
    }

    return 0;
}
