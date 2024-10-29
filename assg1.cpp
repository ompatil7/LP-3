// 1. Write a program to calculate Fibonacci numbers and find its step count.

#include <iostream>
using namespace std;

int stepCount = 0;


int fib(int n) {
    stepCount++;

    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    int choice;


    do { 
        cout << "Menu: " << endl;
        cout << "1. Calculate Fibonacci numbers" << endl;
        // cout << "2. Print all Fibonacci numbers" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            stepCount = 0;
            cout << "Enter the number: ";
            cin >> n;
            cout << "Fibonacci number: " << fib(n) << endl;
            cout << "Step count: " << stepCount << endl;    
        }   
       
    } while(choice != 3);  

    return 0;
}
// if want to print all the series of fibonacci
//  if(choice == 2) {
//     stepCount = 0;
//     cout << "Enter until the number: ";
//     cin >> n;
//     for(int i = 0; i < n; i++) {
//         cout << "Fibonacci number: " << fib(i) << endl;
//     }
//     cout << "Step count: " << stepCount << endl;    
// }