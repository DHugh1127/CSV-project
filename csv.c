#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_fields(const char *csv_file_path) {
    FILE *file = fopen(csv_file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[1024];  // Assuming a maximum line length of 1024 characters
    fgets(line, sizeof(line), file);

    // Count the number of fields in the first line
    int num_fields = 1;
    char *token = strtok(line, ",");
    while (token != NULL) {
        num_fields++;
        token = strtok(NULL, ",");
    }



    fclose(file);
    return num_fields;
}

int count_lines(const char *csv_file_path) {
    FILE *file = fopen(csv_file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int num_lines = 0;
    char line[1024];  // Assuming a maximum line length of 1024 characters
    while (fgets(line, sizeof(line), file) != NULL) {
        num_lines++;
    }

    fclose(file);
    return num_lines;
}

int main(int argc, char *argv[]) {
    const char *csv_file_path = "your_file.csv";
    
    if (argv[1] == "-f"){
        int num_fields = count_fields(csv_file_path);
        printf("The CSV file has %d fields.\n", num_fields);
    }

    if (argv[1] == "-r"){
        int num_lines = count_lines(csv_file_path);
        printf("The CSV file has %d lines.\n", num_lines);
    }
    
    exit(EXIT_SUCCESS);
}
