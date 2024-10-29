// 2. Implement job sequencing with deadlines using a greedy method.

#include <iostream>
#include <algorithm>
using namespace std;

// Structure to store job information
struct Job {
    char id;       // Job ID
    int deadline; // Deadline of the job
    int profit;   // Profit if job is completed
};

// Comparator function to sort jobs by profit in descending order
bool comparison(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing(Job arr[], int n) {
    // sort jobs by profit in descending order
   
    sort(arr, arr + n, comparison);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].id << " " << arr[i].deadline <<" "    <<     arr[i].profit << endl;
    }
    cout << endl;
   
    int result[n];
    bool slot[n];
    for (int i = 0; i < n; i++) {
        slot[i] = false;
    }

    int maxProfit = 0;

    // iterate thru all the jobs
    for (int i = 0; i < n; i++)
    {
        // find a free slot for the current job (starting from the last possible slot)
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            // if slot is free assingn this job to that slot
            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                maxProfit += arr[i].profit;
                break;
            }
        }
    }

    // print the selected job sequence and max profit
    cout << "Selected jobs sequence: " <<endl;
    for (int i = 0; i < n; i++){
        if(slot[i] == true) {
            cout << arr[result[i]].id << " ";
        }

    }
    cout << "Maximum Profit : " << maxProfit;

}

int main() {
    
    Job jobs[] = { { 'a', 2, 100 },
                   { 'b', 1, 19 },
             { 'c', 2, 27 },
             { 'd', 1, 25 },
             { 'e', 3, 15 }
             };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    
    jobSequencing(jobs, n);
    return 0;
}
///INPUT- BASED
// int n
    // cout  << "Enter number of jobs : ";
    // cin >> n;
// input the job details
    // cout << "Enter the Job ID, profit, deadline for each job" << endl;

    // for (int i = 0; i < n; i++) {
    //     cout << "Job " << i + 1 << "(ID Profit Deadline)";
    //     cin >> jobs[i].id >> jobs[i].profit >> jobs[i].deadline;
    // }