#include<bits/stdc++.h>
using namespace std;

int fib(int n, vector<int>& dp) {
    if (n <= 1) return n; // Base cases

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << "Fibonacci number: " << fib(n, dp) << endl;
    return 0;
}