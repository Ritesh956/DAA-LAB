#include <stdio.h>
#include <string.h>
#define MAX 256  // ASCII character size

// Typedef not needed for this algorithm, kept it simple as per your style
typedef char string[100];

// Preprocessing: create shift table
void createShiftTable(char pattern[], int shift[]) {
    int m = strlen(pattern);
    for (int i = 0; i < MAX; i++)
        shift[i] = m;  // default shift

    for (int i = 0; i < m - 1; i++)
        shift[(unsigned char)pattern[i]] = m - 1 - i;
}

// Horsepool string matching
int horsepoolMatch(char text[], char pattern[]) {
    int shift[MAX];
    int n = strlen(text);
    int m = strlen(pattern);

    createShiftTable(pattern, shift);

    int i = m - 1;

    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k])
            k++;

        if (k == m)
            return i - m + 1;  // match found

        i += shift[(unsigned char)text[i]];
    }

    return -1;  // no match
}

// Main function
int main() {
    string text, pattern;
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    int pos = horsepoolMatch(text, pattern);
    if (pos != -1)
        printf("Pattern found at position %d\n", pos);
    else
        printf("Pattern not found.\n");

    return 0;
}
