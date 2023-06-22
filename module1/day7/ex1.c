#include <stdio.h>

int main() {
    FILE *srcFile, *dstnFile;
    char ch;

    // Open the source file in read mode
    srcFile = fopen("source.txt", "r");
    if (srcFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Open the destination file in write mode
    dstnFile = fopen("destination.txt", "w");
    if (dstnFile == NULL) {
        printf("Unable to create the destination file.\n");
        return 1;
    }

    // Copy the contents of the source file to the destination file
    while ((ch = fgetc(srcFile)) != EOF) {
        fputc(ch, dstnFile);
    }

    // Close the files
    fclose(srcFile);
    fclose(dstnFile);

    printf("File copied successfully.\n");

    return 0;
}
