#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MAKE SURE TO GIT PULL BEFORE MAKING CHANGES

int count_fields(const char *csv_file_path) {

    char line[4096];  // Assuming a maximum line length of 1024 characters
    fgets(line, sizeof(line), csv_file_path);

    // Count the number of fields in the first line
    int num_fields = 1;
    char *token = strtok(line, ",");
    while (token != NULL) {
        num_fields++;
        token = strtok(NULL, ",");
    }

    return num_fields;
}

int count_lines(const char *csv_file_path) {

    int num_lines = 0;
    char line[4096];  // Assuming a maximum line length of 1024 characters
    while (fgets(line, sizeof(line), csv_file_path) != NULL) {
        num_lines++;
    }

    return num_lines;
}

// function to grab the titles of the header line
char **head_strings(const char *csv_file_path) {

    int fields = 0;
    fields = count_fields(csv_file_path);
    char *headers[fields];
    char whole_line[4096];
    fgets(whole_line, sizeof(whole_line), csv_file_path);

    int x = 0;
    int y = 0;
    int i = 0;
    while(whole_line[i] != NULL)
        {
            while(whole_line[i] != ',')
                {
                    headers[x][y] = whole_line[i];
                    y++;
                    i++;
                }
            i++;
            x++;
            y = 0;
        }
    return **headers;

    
    
    //while (fgets(line, sizeof(line), csv_file_path) != '\n'){
    //  temp[i] = 
    
}


int main(int argc, char *argv[]) {

    const char *csv_file_path = "your_file.csv";

    const char *csv_file_path = "example.csv";

    FILE *file = fopen(csv_file_path, "r");

    int i = 2;

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);   }
    
    if(argc == 3)
        {
            if (argv[1] == "-f"){
                int num_fields = count_fields(csv_file_path);
                printf("The CSV file has %d fields.\n", num_fields);
            }
            
            if (argv[1] == "-r"){
                int num_lines = count_lines(csv_file_path);
                printf("The CSV file has %d lines.\n", num_lines);
            }
            
        }
    
    if (argv[i] == "-min" || "-max" || "-mean" || "-records"){
        int check = atoi(argv[2]);
        
        if (check == 0 && argv[2] != '0'){
            printf("Please input a valid integer unless you use -h\n")
                
                exit(EXIT_FAILURE);
        }
        
    if (argv[1] == "-h"){
        
        
        
        //Check if min,max...are used without -h. Makes sure next arguement is an integer
        if (argv[i] == "-min" || "-max" || "-mean" || "-records"){
            int check = atoi(argv[2]);
            
            if (check == 0 && argv[2] != '0'){
                printf("Please input a valid integer unless you use -h\n")
                    
                    exit(EXIT_FAILURE);
            }
        }
    }
    
    fclose(file);
    exit(EXIT_SUCCESS);
    }

