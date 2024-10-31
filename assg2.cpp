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


// Returns maximum profit from jobs
void jobSequencing(Job arr[], int n) {
    // sort jobs by profit in descending order
    sort(arr, arr + n, comparison);

    int result[n]; // To store result (Sequence of jobs)
	bool slot[n]; // To keep track of free time slots

	// Initialize all slots to be free
    for (int i = 0; i < n; i++) {
        slot[i] = false;
    }

    int maxProfit = 0;
    // iterate thru all the jobs
    for (int i = 0; i < n; i++)
    {
        // Find a free slot for this job (Note that we start
		// from the last possible slot)
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            // if slot is free assingn this job to that slot
            if (slot[j] == false)
            {
                //free slot found
                result[j] = i; // Add this job to result
				slot[j] = true; // Make this slot occupied
                maxProfit += arr[i].profit;
                break;
            }
        }
    }
    // print the selected job sequence and max profit
    cout << "Selected jobs sequence: " <<endl;
    for (int i = 0; i < n; i++) { 
        if(slot[i] == true) {
            cout << arr[result[i]].id << " ";
        }
    }
    cout << "\nMaximum Profit : " << maxProfit;
}

int main() {
    
    int choice;
    do { 
        cout << "Menu: " << endl;
        cout << "1. Enter Job Details" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            stepCount = 0;
            cout << "Enter the number of Jobs: " << endl;
            cin >> n;
            Job jobs[n];
            cout << "Enter details :" << endl;
            for(int i = 0; i < n; i++) {
                cout << "Job " << i + 1 << "(ID Deadline Profit)";
                cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
            }
            jobSequencing(jobs, n);
        }   
       
    } while(choice != 2);  

    return 0;
}
// direct code run sathi
// Job jobs[] = { { 'a', 2, 100 },
//                { 'b', 1, 19 },
//                {'c', 2, 27 },
//                {'d', 1, 25 },
//                {'e', 3, 15 }
//              };
//int n = sizeof(jobs) / sizeof(jobs[0]);
//jobSequencing(jobs, n);