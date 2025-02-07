#include <stdio.h>
#include <string.h>

int brute_force_string_match(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            return i;
        }
    }
    return -1; 
}

int main() {
    char text[100], pattern[100];
    
    printf("Enter the text: ");
    scanf("%s", text);
    
    printf("Enter the pattern: ");
    scanf("%s", pattern);
    
    int result = brute_force_string_match(text, pattern);
    if (result != -1) {
        printf("Pattern found at index %d\n", result);
    } else {
        printf("Pattern not found\n");
    }
    
    return 0;
}
