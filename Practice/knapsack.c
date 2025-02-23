#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to solve Knapsack using brute force
int Knapsack(unsigned int *w, unsigned int *v, unsigned int n, unsigned int B) {
    unsigned int i, temp;
    unsigned int maxVal = 0, maxSequence = 0;
    unsigned int totalWeight, totalValue;
    unsigned int index;

    // Generate all possible subsets (2^n)
    for (i = 1; i < pow(2,n); i++) {  // (1 << n) is same as pow(2, n)
        temp = i;
        totalWeight = 0;
        totalValue = 0;
        index = 0;

        // Check each bit in the subset representation
        while (temp) {
            if (temp & 1) {  // If the bit is set, include this item
                totalWeight += w[index];
                totalValue += v[index];
            }
            index++;
            temp >>= 1;  // Shift bits to check next item
        }

        // Update maximum value if this subset is valid
        if (totalWeight <= B && totalValue > maxVal) {
            maxVal = totalValue;
            maxSequence = i;  // Store bitmask of chosen items
        }
    }

    // Print the selected items
    printf("Selected items: ");
    for (i = 0; i < n; i++) {
        if (maxSequence & (1 << i)) { // Check if item i is in maxSequence
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    return maxVal; // Return max value found
}

// Driver code
int main() {
    unsigned int n, B;
    
    // Get number of items
    printf("Enter number of items: ");
    scanf("%u", &n);
    
    unsigned int w[n], v[n];

    // Get weights and values
    printf("Enter weights of items: ");
    for (unsigned int i = 0; i < n; i++) {
        scanf("%u", &w[i]);
    }

    printf("Enter values of items: ");
    for (unsigned int i = 0; i < n; i++) {
        scanf("%u", &v[i]);
    }

    // Get knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%u", &B);

    // Solve the knapsack problem
    unsigned int maxProfit = Knapsack(w, v, n, B);
    printf("Maximum value in knapsack: %u\n", maxProfit);

    return 0;
}