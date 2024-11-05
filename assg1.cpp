// // 1. Write a program to calculate Fibonacci numbers and find its step count.
#include <iostream>
using namespace std;

int stepcount = 0;

int fib(int n) {
    stepcount++;

    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

int iterativeFib(int n) {
    int sc = 0;
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        sc++;
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int choice;
    int n;

    do {
        cout << "1. Calculate fibonacci " << endl;
        cout << "2. Print all " << endl;
        cout << "3. Exit " << endl;
        cout << "Enter :  " << endl;
        cin >> choice;
        switch(choice) {
            
            case 1:
                cout << "Enter n : ";
                cin >> n;
                cout << "Fibonacci number : " << iterativeFib(n) << endl;
                break;
            
            case 2:
                cout << "Enter n : ";
                cin >> n;
                for (int i = 0; i <= n; i++) {
                    cout << iterativeFib(i) << " | ";
                }
                cout << endl;
                break;
            
            case 3:
                break;                
            
            default:
                cout << "Enter valid choice" << endl;
                break;
        }
    
    } while (choice != 3);
}



/*
#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the nth Fibonacci number using DP
int fibonacci(int n) {
    if (n <= 1) return n; // Base cases

    vector<int> dp(n + 1); // DP array to store Fibonacci numbers
    dp[0] = 0; // F(0)
    dp[1] = 1; // F(1)

    // Fill the DP array
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; // F(n) = F(n-1) + F(n-2)
    }

    return dp[n]; // Return the nth Fibonacci number
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    int result = fibonacci(n); // Calculate Fibonacci
    cout << "Fibonacci number F(" << n << ") = " << result << endl;

    return 0;
}
*/
