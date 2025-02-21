#include <stdio.h>
#include <string.h>
#define ALPHABET_SIZE 256  // Defines the size of the character set

void badCharTable(char *pattern, int size, int badChar[ALPHABET_SIZE]) {
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        badChar[i] = -1;
    }
    for (i = 0; i < size; i++) {
        badChar[(int)pattern[i]] = i;
    }
}

void boyerMooreSearch(char *text, char *pattern) {
    int textLen = strlen(text);      // Length of the text
    int patternLen = strlen(pattern); // Length of the pattern

    int badChar[ALPHABET_SIZE];      // Array for bad character rule
    badCharTable(pattern, patternLen, badChar);  // Fill the bad character table

    int shift = 0;  // Keeps track of the pattern's shift position over the text
    while (shift <= (textLen - patternLen)) {
        int j = patternLen - 1;  // Start comparing from the end of the pattern
        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }
        if (j < 0) {
            printf("Pattern found at index %d\n", shift);
            shift += (shift + patternLen < textLen) ? patternLen - badChar[(int)text[shift + patternLen]] : 1;
        } else {
            shift += (j - badChar[(int)text[shift + j]] > 1) ? j - badChar[(int)text[shift + j]] : 1;
        }
    }
}

int main() {
    char text[] = "EXAMPLE TEXT FOR BOYER MOORE EXAMPLE"; 
    char pattern[] = "EXAMPLE";                          
    boyerMooreSearch(text, pattern);  // Perform the Boyer-Moore search
    return 0;
}
