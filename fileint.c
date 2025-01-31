#include <stdio.h>
#include <stdbool.h>


bool addFile(const char *filename, int *sum) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return false; // Return false if file cannot be opened
    }
    
    *sum = 0; 
    int num;
    while (fscanf(file, "%d", &num) == 1) {
        *sum += num; // Add each integer to sum
    }
    
    fclose(file); // Close the file after reading
    return true;
}


bool writeSum(const char *filename, int sum) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        return false; // Return false if file cannot be opened
    }
    
    fprintf(file, "%d\n", sum); 
    fclose(file); // Close the file after writing
    return true;
}
