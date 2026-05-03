#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processFile(const char *inputFile, const char *outputFile, const char * key) {
    FILE *in = fopen(inputFile, "rb");
    FILE *out = fopen(outputFile, "wb");

    if (in == NULL || out == NULL) {
        printf("Error opening files.\n");
        return;
    }
    size_t keyLen = strlen(key);
    size_t i = 0;
    int ch;

    while ((ch = fgetc(in)) != EOF) {
        fputc(ch ^ key[i % keyLen], out);
        i++;
    }
    fclose(in);
    fclose(out);
}

int main() {
    char key[100];
    int choice;

    printf("1. Encrypt File\n2. Decrypt File\nEnter choice: ");
    scanf("%d", &choice);
    getchar();

    printf("Enter secret key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;


    if (choice == 1) {
        processFile("plain.txt", "encrypted.dat", key);
        printf("File encrypted successfully as 'encrypted.dat'\n");
    }else if (choice == 2){
        processFile("encrypted.dat", "decrypted.txt", key);
        printf("File decrypted successfully as 'decrypted.txt'\n");
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}