#include <stdio.h>
#include <ctype.h>

void convertToUpperCase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void convertToLowerCase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

void convertToSentenceCase(char *str) {
    int capitalize = 1;  // Flag to indicate if the next character should be capitalized

    while (*str) {
        if (capitalize && isalpha((unsigned char)*str))
            *str = toupper((unsigned char)*str);
        else
            *str = tolower((unsigned char)*str);

        capitalize = (*str == '.' || *str == '?' || *str == '!');

        str++;
    }
}

int main(int argc, char *argv[]) {
    FILE *sourceFile, *destinationFile;
    char ch;

    // Check if the number of arguments is sufficient
    if (argc < 4) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp [-u/-l/-s] source_file destination_file\n");
        return 1;
    }

    // Get the option and validate it
    char *option = argv[1];
    if (option[0] != '-' || option[2] != '\0') {
        printf("Invalid option.\n");
        printf("Usage: ./cp [-u/-l/-s] source_file destination_file\n");
        return 1;
    }

    // Open the source file in read mode
    sourceFile = fopen(argv[2], "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Open the destination file in write mode
    destinationFile = fopen(argv[3], "w");
    if (destinationFile == NULL) {
        printf("Unable to create the destination file.\n");
        return 1;
    }

    // Copy the contents of the source file to the destination file
    while ((ch = fgetc(sourceFile)) != EOF) {
        if (option[1] == 'u')
            ch = toupper(ch);
        else if (option[1] == 'l')
            ch = tolower(ch);
        else if (option[1] == 's')
            convertToSentenceCase(&ch);

        fputc(ch, destinationFile);
    }

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copied successfully.\n");

    return 0;
}
