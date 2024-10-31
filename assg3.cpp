#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int profit;
    int weight;

    Item(int profit, int weight) {
        this->weight = weight;
        this->profit = profit;
    }
};
// comparison function to sort items according to profit/weight ratio
static bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;

    return r1 > r2;
}

double fractionalKnapsack(int capacity, struct Item arr[], int n) {
    //sort basis on the pro/wt ratio
    sort(arr, arr + n, cmp);

    double totalProfit = 0.0;

    //iterate thru itemms and keep adding until capacity owari da
    for (int i = 0; i < n; i++)
    {
        if(arr[i].weight <= capacity) {
            totalProfit += arr[i].profit;
            capacity -= arr[i].weight;
        }
        else {
            double fracProfit = ( (double)capacity / (double)arr[i].weight) * arr[i].profit;
            totalProfit += fracProfit;
            break;
        }
    }
    return totalProfit;
}

int main()
{
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = 3;
    int W = 50;
    cout << fractionalKnapsack(W, items, n);
}