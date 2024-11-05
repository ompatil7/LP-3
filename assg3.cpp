#include <iostream>
#include <algorithm>
using namespace std;
// fractional knapscak using greedy method
struct Item {
    int profit;
    int weight;

    // Item(int profit, int weight) {
    //     this->weight = weight;
    //     this->pxrofit = profit;
    // }
};
// comparison function to sort items according to profit/weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;

    return r1 > r2;
}

double fractionalKnapsack(int capacity, Item arr[], int n) {
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
    int choice;
    int n;
    int W;
    do { 
        cout << "Menu: " << endl;
        cout << "1. Enter Item Details" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "Enter the number of Items: " << endl;
            cin >> n;
            cout << "Enter capacity : ";
            cin >> W;
            Item items[n];
            cout << "Enter details of item :" << endl;
            for(int i = 0; i < n; i++) {
                cout << "Item " << i + 1 << "(Profit Weight)";
                cin >> items[i].profit >> items[i].weight;
            }
            cout << "\nMaximum Profit : " << fractionalKnapsack(W, items, n) << endl;
        }   
       
    } while(choice != 2);  


    // Item items[] = {{60, 10}, {100, 20}, {120, 30}};

    return 0;
}

// cap = 50
// profit weifht
// 60 10
// 100 20
// 120 30
// max = 240



/*
// Function to perform Bubble Sort
void bubbleSort(struct Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements
            double r1 = (double)arr[j].profit / (double)arr[j].weight;
            double r2 = (double)arr[j + 1].profit / (double)arr[j + 1].weight;

            // If the current item is less than the next item, swap them
            if (r1 < r2) {
                // Swap arr[j] and arr[j + 1]
                Item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}*/

/*
### What is Greedy?

**Greedy algorithms** are a class of algorithms that build up a solution piece by piece, always choosing the next piece that offers the most immediate benefit or is the most optimal according to a specific criterion. The key characteristic of greedy algorithms is that they make local optimal choices with the hope that these choices will lead to a global optimum.

### Characteristics of Greedy Algorithms

1. **Locally Optimal Choice**: At each step, the algorithm makes the choice that seems the best at that moment.
2. **Irrevocability**: Once a choice is made, it cannot be undone. The algorithm does not reconsider previous choices.
3. **Feasibility**: The choice made must be feasible and satisfy the constraints of the problem.
4. **Optimal Substructure**: A problem has an optimal substructure if an optimal solution to the problem contains optimal solutions to its subproblems.

### Common Greedy Methods

Greedy algorithms can be applied to various problems across different domains. Here are some well-known examples:

1. **Fractional Knapsack Problem**: Selecting items based on the highest profit-to-weight ratio until the knapsack is full.
2. **Activity Selection Problem**: Choosing the maximum number of activities that don't overlap, typically sorted by finishing time.
3. **Huffman Coding**: A method for lossless data compression that uses a greedy approach to build a prefix code based on character frequencies.
4. **Prim's and Kruskal's Algorithms**: Used for finding the Minimum Spanning Tree (MST) of a graph. Prim’s builds the MST one vertex at a time, while Kruskal’s builds it by adding edges in order of increasing weight.
5. **Dijkstra's Algorithm**: A greedy algorithm for finding the shortest path from a starting node to all other nodes in a weighted graph.
6. **Job Sequencing Problem**: Scheduling jobs to maximize profit, given deadlines.

### Limitations of Greedy Algorithms

- **Not Always Optimal**: Greedy algorithms do not always produce the optimal solution for every problem. They work best when a problem exhibits optimal substructure and greedy choice property.
- **Complexity**: While they often have a lower time complexity than dynamic programming approaches, greedy algorithms may still have a high computational cost depending on the problem.

### Conclusion

Greedy algorithms are powerful tools for solving optimization problems. They are usually simpler and more efficient compared to other approaches, such as dynamic programming. However, they require careful analysis to ensure they yield optimal solutions for the specific problem being addressed.
*/