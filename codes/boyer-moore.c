#include <stdio.h>
#include <string.h>
#define MAX 256  // For ASCII characters

typedef char string[100];

// Bad Character Table
void badCharTable(char pattern[], int badchar[]) {
    int m = strlen(pattern);
    for (int i = 0; i < MAX; i++)
        badchar[i] = -1;

    for (int i = 0; i < m; i++)
        badchar[(unsigned char)pattern[i]] = i;
}

// Good Suffix Table
void goodSuffixTable(char pattern[], int m, int suffix[], int shift[]) {
    int i, j;

    // Step 1: Initialize
    for (i = 0; i < m; i++) {
        suffix[i] = -1;
        shift[i] = m;
    }

    // Step 2: Fill suffix[]
    for (i = m - 1; i >= 0; i--) {
        j = i;
        while (j >= 0 && pattern[j] == pattern[m - 1 - i + j])
            j--;

        suffix[i] = i - j;
    }

    // Step 3: Fill shift[]
    for (i = 0; i < m - 1; i++) {
        int j = m - 1 - suffix[i];
        if (shift[j] > i - suffix[i] + 1)
            shift[j] = i - suffix[i] + 1;
    }
}

// Boyer-Moore Full
int boyerMooreFull(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    int badchar[MAX];
    int suffix[100], shift[100];

    badCharTable(pattern, badchar);
    goodSuffixTable(pattern, m, suffix, shift);

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0) {
            return s; // Match found
        } else {
            int bcShift = j - badchar[(unsigned char)text[s + j]];
            int gsShift = shift[j];
            s += (bcShift > gsShift) ? bcShift : gsShift;
        }
    }

    return -1;
}

// Main Function
int main() {
    string text, pattern;

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    int pos = boyerMooreFull(text, pattern);
    if (pos != -1)
        printf("Pattern found at position %d\n", pos);
    else
        printf("Pattern not found.\n");

    return 0;
}
