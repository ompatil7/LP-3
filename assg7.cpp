#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

// Function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function for deterministic quicksort (last element as pivot)
int deterministicPartition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Deterministic Quick Sort
void deterministicQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = deterministicPartition(arr, low, high);
        deterministicQuickSort(arr, low, pi - 1);
        deterministicQuickSort(arr, pi + 1, high);
    }
}

// Partition function for randomized quicksort (random pivot selection)
int randomizedPartition(vector<int>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]); // Move random pivot to end
    return deterministicPartition(arr, low, high); // Use deterministic partitioning
}

// Randomized Quick Sort
void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0)); // Seed for random number generation

    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    // Deterministic Quick Sort
    vector<int> deterministicArr = arr; // Copy of the array
    cout << "Original array: ";
    printArray(arr);

    deterministicQuickSort(deterministicArr, 0, n - 1);
    cout << "Sorted array using Deterministic Quick Sort: ";
    printArray(deterministicArr);

    // Randomized Quick Sort
    vector<int> randomizedArr = arr; // Copy of the array
    randomizedQuickSort(randomizedArr, 0, n - 1);
    cout << "Sorted array using Randomized Quick Sort: ";
    printArray(randomizedArr);

    return 0;
}

//bhai idk this yet, i wil be doing this later 
//pata nai kyas hai ye