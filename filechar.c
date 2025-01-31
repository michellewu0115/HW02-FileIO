#include <stdio.h>
#include <stdbool.h>


bool countChar(const char *filename, int *counts, int size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return false; // Return false if file cannot be opened
    }
    
    // Initialize all elements to zero
    for (int i = 0; i < size; i++) {
        counts[i] = 0;
    }
    
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch >= 0 && ch < size) {
            counts[ch]++; 
        }
    }
    
    fclose(file); // Close the file after processing
    return true;
}


void printCounts(const int *counts, int size) {
    for (int i = 0; i < size; i++) {
        if (counts[i] > 0) {
            // Print character if it is alphabetic, or else print space
            char displayChar = (i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z') ? (char)i : ' ';
            printf("%d, %c, %d\n", i, displayChar, counts[i]);
        }
    }
}

