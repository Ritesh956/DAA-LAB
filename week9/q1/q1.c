#include<stdio.h>
#include<string.h>

// Global variables
int table[256];
int comparisons = 0;

// Shift table function
void shifttable(char *pattern){
    for(int i = 0 ; i < 256 ; i++){
        table[i] = strlen(pattern);
    }
    for(int i = 0 ; i < strlen(pattern) - 1 ; i++){
        table[pattern[i]] = strlen(pattern) - 1 - i;
    }
}

// String match function
int horspool(char *text, char *pattern){
    int plen = strlen(pattern);
    int tlen = strlen(text);
    int i = plen - 1;
    while(i < tlen){
        int k = 0;
        while((k < plen) && (text[i-k] == pattern[plen-1-k])){
            comparisons++;
            k++;
        }
        if(k == plen) return i - plen + 1;
        else{
            comparisons++;
            i += table[text[i]];
        }
    }
    return -1;
}

// Main function
int main(){
    char text[30], pattern[30];
    
    // Use fgets to read text and pattern to allow spaces
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;  // Remove the newline character if present

    printf("Enter pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = 0;  // Remove the newline character if present
    
    shifttable(pattern);
    int hp = horspool(text, pattern);

    if(hp == -1)
        printf("No string matching\n");
    else
        printf("String matching in text at index %d.\n", hp);

    printf("Total key comparisons: %d\n", comparisons);
}
