#include <iostream>
#include <vector>
using namespace std;

// Function to solve the 0-1 Knapsack problem using dynamic programming
int knapsack(int capacity, const vector<int> &weights, const vector<int> &values, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the table dp[][] in a bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (weights[i - 1] <= w)
            {
                // Choose the maximum of including or excluding the current item
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w]; // Item cannot be included
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }


    return dp[n][capacity]; // Maximum value that can be obtained
}

int main()
{
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<int> weights(n), values(n);

    cout << "Enter weights and values for each item:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << ": ";
        cin >> weights[i] >> values[i];
    }

    int maxProfit = knapsack(capacity, weights, values, n);

    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
/*
Enter the number of items: 3
Enter the capacity of the knapsack: 50
Enter weights and values for each item:
Item 1: 10
60
Item 2: 20
100
Item 3: 30
120
Maximum profit: 220
*/