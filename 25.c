#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    FILE *f1, *f2;
    char buffer[1000];
    char words[100][50];
    int i = 0, count = 0;

    f1 = fopen("abc.txt", "r");
    if (f1 == NULL) {
        printf("Error opening abc.txt\n");
        return 1;
    }
    while (fscanf(f1, "%s", words[count]) != EOF)
    {
        count++;
    }
    fclose(f1);

    f2 = fopen("xyz.txt", "w");
    if (f2 == NULL) {
        printf("Error opening xyz.txt\n");
        return 1;
    }
    for (i = count - 1; i >= 0; i--) {
        fprintf(f2, "%s", words[i]);
        if (i > 0) {
            fprintf(f2, " ");
        }
    }
    
    fclose(f2);
    printf("Content reversed and saved to xyz.txt successfully.\n");

    return 0;
}

