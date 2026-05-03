#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourcePtr, *destPtr;
    int ch;

    sourcePtr = fopen("source.txt", "r");
    if (sourcePtr == NULL) {
        perror("Error opening source file");
        return EXIT_FAILURE;
    }
    destPtr = fopen("destination.txt", "w");
    if (destPtr == NULL ) {
        perror("Error opening destination file");
        fclose(sourcePtr);
        return EXIT_FAILURE;
    }

    while ((ch = fgetc(sourcePtr)) != EOF) 
    {
        fputc(ch, destPtr);
    }

    printf("File copied succrssfully.\n");

    fclose(sourcePtr);
    fclose(destPtr);

    return EXIT_SUCCESS;
    
}