//  Write a program to generate binomial coefficients using dynamic programming.
#include <iostream>
#include <vector>
using namespace std;

// Function to calculate binomial coefficients using dynamic programming
int binomialCoeff(int n, int k) {
    vector<vector<int>> C(n + 1, vector<int>(k + 1, 0));

    // Fill the table C[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            // Base cases: C(i, 0) = 1 and C(i, i) = 1
            if (j == 0 || j == i) {
                C[i][j] = 1;
            }
            // Use previously computed values
            else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    return C[n][k];
}

int main() {
    int n, k;
    cout << "Enter values of n and k: ";
    cin >> n >> k;

    cout << "Binomial Coefficient C(" << n << ", " << k << ") = " << binomialCoeff(n, k) << endl;

    return 0;
}

// A binomial coefficient C(n, k) also gives the number of ways, disregarding order, that k objects can be chosen from among n objects more formally, the number of k-element subsets (or k-combinations) of a n-element set.

// The Problem 
// Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k). For example, your function should return 6 for n = 4 and k = 2, and it should return 10 for n = 5 and k = 2.

// Sample Input 
// Enter values of n and k: 4 2
// Sample Output
// Binomial Coefficient C(4, 2) = 6