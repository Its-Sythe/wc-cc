#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char *argv[]) {
	char *command = argv[1];
	char *filename = argv[2];

	if (command == NULL || filename == NULL) return 1;

	FILE *fptr;
	fptr = fopen(filename, "r");

	if (fptr == NULL) {
		printf("Failed to open file");
	}

	int ch;
	int count = 0;
	if (strcmp(command, "-c") == 0) {
		while((ch = fgetc(fptr)) != EOF) count++;
	} else if (strcmp(command, "-l") == 0) {
		while((ch = fgetc(fptr)) != EOF) {
			if (ch == '\n') count++;
		}
	} else if (strcmp(command, "-w") == 0) {
		while((ch = fgetc(fptr)) != EOF) {
			if (!isalnum(ch) && isspace(ch)) count++;
		}
	}

	printf("%d\n", count);

	fclose(fptr);

	return 0;
}
