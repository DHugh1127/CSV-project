#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// MAKE SURE TO GIT PULL BEFORE MAKING CHANGES

int count_fields(FILE *csv_file_path) {

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

int count_lines(FILE *csv_file_path) {

    int num_lines = 0;
    char line[4096];  // Assuming a maximum line length of 1024 characters
    while (fgets(line, sizeof(line), csv_file_path) != NULL) {
        num_lines++;
    }

    return num_lines;
}

// function to grab the titles of the header line
char **head_strings(FILE *csv_file_path) {

    int fields = 0;
    fields = count_fields(csv_file_path);
    
    char **headers = (char **)malloc(fields * sizeof(char *));
    char whole_line[4096];
    fgets(whole_line, sizeof(whole_line), csv_file_path);

    int x = 0;
    int y = 0;
    int i = 0;
    while(whole_line[i] != '\0')
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
    return headers;

    
    
    //while (fgets(line, sizeof(line), csv_file_path) != '\n'){
    //  temp[i] = 
    
}

//if argv[i] is either min mean or max, send the correct function code and argv[i+1](column) 
int calcMMM(int code, int column, FILE *csv_file_path)
{
//First preload the first value into a variable
    
        char line[4096];  // Assuming a maximum line length of 1024 cha \
    racters
        char *token;
        
        fgets(line, sizeof(line), csv_file_path); //This grabs the header row
        fgets(line, sizeof(line), csv_file_path); //This grabs our first line of data
     
        for(int j = 0; j < column; j++){ 
            token = strtok(line, ",");
        }                 
    
    //initial starting value for min
        int value = atoi(token);  
      
    
        switch (code){
        case 0: //min
            for(int i = 0; i < count_lines(csv_file_path)-2; i++){//the -2 is there since we already checked 2 rows
                char line[4096];  // Assuming a maximum line length of 1024 characters
                fgets(line, sizeof(line), csv_file_path);
                
                for(int j = 0; j < column; j++){
                    token = strtok(line, ",");
                }       
      
                if(value > atoi(token)){
                    value = atoi(token);
                }
            }
            
            break;
        case 1: //max
            break;
        case 2: //mean
            break;
        }
        return value;
}

void calcR(int column, int value, FILE *csv_file_path)
{
    char line[4096];
    char *token;
    
    fgets(line, sizeof(line), csv_file_path); //This grabs the header row

    for(int i = 0; i < count_lines(csv_file_path)-1; i++){ //the -1 since we grabbed header alreadyfor(int j = 0; j < column)
        fgets(line, sizeof(line), csv_file_path);
        
        for(int j = 0; j < column; j++){
            token = strtok(line, ",");
        }
        if(atoi(token) == value){
            printf("%s\n",line);
        }
   }
}


int main(int argc, char *argv[]) {

    const char *csv_file_path = argv[argc - 1];

    FILE *file = fopen(csv_file_path, "r");

    int i = 2;
    bool hFLAG = false;
    
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);   }
    
    if(argc == 3){
            if (argv[1] == "-f"){
                int num_fields = count_fields(file);
                printf("The CSV file has %d fields.\n", num_fields);
            }
            
            if (argv[1] == "-r"){
                int num_lines = count_lines(file);
                printf("The CSV file has %d lines.\n", num_lines);
            }
            
        }
    
    if (argv[i] == "-min" || "-max" || "-mean" || "-records"){
        int check = atoi(argv[2]);
        
        if (check == 0 && argv[2] != '0'){
            printf("Please input a valid integer unless you use -h\n");
                
                exit(EXIT_FAILURE);
        }
    }       
        
    if (argv[1] == "-h"){
        
        
        
        //Check if min,max...are used without -h. Makes sure next arguement is an integer
        if (argv[i] == "-min" || "-max" || "-mean" || "-records"){
            int check = atoi(argv[2]);
            
            if (check == 0 && argv[2] != '0'){
                printf("Please input a valid integer unless you use -h\n");
                    
                    exit(EXIT_FAILURE);
            }
        }
    }

  
//Basic structure for main to search through all arguments in argv.
    for(int i = 1; i < argc; i++){//start at argv[1] 
        if(argv[i] == "-f"){
            printf("The CSV file has %d fields.\n", count_fields(file));
        }
        else if(argv[i] == "-r"){
            printf("The CSV file has %d lines.\n", count_lines(file));
        }
        else if(argv[i] == "-h"){
            //create flag so we know to use -h for min/max/mean
            hFLAG = true;
        }
        else if(argv[i] == "-min"){

            if(hFLAG){
                
                //Search through Brandons array, if argv[i+1] is not found, return EXIT_Failure
                char **header = head_strings(file);
                int column = -1; 
                
                for(int j = 0; j < count_fields(file); j++){
                    if(header[j] == argv[i+1]){
                        //set column if found
                        column = j;
                    }
                }

                if(column == -1){//If column variable is -1, then it means the specific column was not found.
                    printf("Invalid column name given for -min!\n");
                    exit(EXIT_FAILURE);
                }
                else{
                    printf("%d\n", calcMMM(0, column, file));
                    i++; //skip the next argv[i] since it is a corresponding argument for min
                }
                
            }

            //CHECK IF NUMERIC VALUE IS NOT VALID
            else if(atoi(argv[i+1]) < count_fields(file) &&  atoi(argv[i+1]) > count_fields(file)){
                printf("Invalid numeric value for -min not found! (there are 0-%d usable columns)\n", count_fields(file));
                exit(EXIT_FAILURE);
            }
            
            else{
                printf("%d\n", calcMMM(0, atoi(argv[i+1]), file));
                i++; //skip the next argv[i] since it is a corresponding argument for min
            }
            
        }
        else if(argv[i] == "-max"){
            
            //check if min works first, then copy and paste code here for max
            
        }
        else if(argv[i] == "-mean"){
            
            //check if min works first, then copy and past code here for mean
            
        }
        else if(argv[i] == "records"){
            if(hFLAG){
                
            }
        }
        else{
            printf("Invald arugument found!\n");
            exit(EXIT_FAILURE);
        }
            
    }
    
    
    fclose(file);
    exit(EXIT_SUCCESS);
}

