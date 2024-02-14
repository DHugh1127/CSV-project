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

//if argv[i] is either min mean or max, send the correct function code and argv[i+1](column) 
int calcMMM(int code, int column)
{
//First preload the first value into a variable
    
    for(int i = 0; i < count_lines(csv_file_path); i++){
        char line[4096];  // Assuming a maximum line length of 1024 cha \
    racters
        fgets(line, sizeof(line), csv_file_path);
        char *token = strtok(line, ",");
     
        for(int j = 0; j < column; j++){
            token = strtok(line, ",");
        }                 

        int value = atoi(token);  
                       
            
    
        switch (code){
        case 0: //min
            for(int i = 0; i < count_lines(csv_file_path)-1; i++){
                char line[4096];  // Assuming a maximum line length of 1024 characters
                fgets(line, sizeof(line), csv_file_path);
                char *token = strtok(line, ",");
                
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
            /*for (i = 0; i < argc; i++){
              if argv[i] == "min"
              { calcMMR(0, argv[i+1])
              
              }
              }
            */
}


int main(int argc, char *argv[]) {

    const char *csv_file_path = "example.csv";

    FILE *file = fopen(csv_file_path, "r");

    int i = 2;
    bool hFLAG = false;
    
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);   }
    
    if(argc == 3){
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
            printf("The CSV file has %d fields.\n", num_fields);
        }
        else if(argv[i] == "-r"){
            printf("The CSV file has %d lines.\n", num_lines);
        }
        else if(argv[i] == "-h"){
            //create flag so we know to use -h for min/max/mean
            hFLAG = true;
        }
        else if(argv[i] == "-min"){

            if(hFLAG){
                bool found = false;
                
                //Search through Brandons array, if argv[i+1] is not found, return EXIT_Failure
                char **header == head_strings(csv_file_path);
                for(int j = 0; j < count_fields(csv_file_path); j++){
                    if(header[j] == argv[i+1]){
                        //set flag if found, set column number
                        found = true;
                        int column = j;
                    }
                }

                if(!found){
                    printf("Invalid column name given for -min!\n");
                    return(EXIT_FAILURE);
                }
                
         
                printf("%d\n", calcMMM(0,column));
                i++; //skip the next argv[i] since it is a corresponding argument for min
            }

            //CHECK IF NUMERIC VALUE IS NOT VALID
            else if(argv[i+1] < count_fields(csv_file_path) &&  argv[i+1] > count_fields(csv_file_path)){
                printf("Invalid numeric value for -min not found! (there are 0-%d usable columns)\n", count_fields(csv_file_path));
                return(EXIT_FAILURE);
            }
            
            else{
                printf("%d\n", calcMMM(0, argv[i+1]));
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
            
        }
        else{
            printf("Invald arugument found!\n");
            return(EXIT_FAILURE);
        }
            
    }
    
    
    fclose(file);
    exit(EXIT_SUCCESS);
}

