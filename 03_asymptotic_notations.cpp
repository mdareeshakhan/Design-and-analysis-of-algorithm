// DAA Lesson 3 — Growth of Functions (Asymptotic Notations)
//
// Asymptotic notation describes how an algorithm's running time grows
// as the input size n grows large. We drop constants and lower-order
// terms and keep only the fastest-growing term:  3n^2 + 5n + 2  ->  O(n^2)
//
//   Big-O  (O) : UPPER bound  -> "at most"  -> worst case  (most used)
//   Omega  (W) : LOWER bound  -> "at least" -> best case
//   Theta  (T) : TIGHT bound  -> upper == lower -> exact growth
//
// Common growth rates (best -> worst):
//   O(1) < O(log n) < O(n) < O(n log n) < O(n^2) < O(2^n)
//
// The three functions below show how to READ complexity from code.

#include <iostream>
using namespace std;

// O(1) - constant: no loop, one operation
int first(int arr[]) {
    return arr[0];
}

// O(n) - linear: one loop running n times
int sum(int arr[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
        s += arr[i];
    return s;
}

// O(n^2) - quadratic: a loop inside a loop
void pairs(int arr[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << "(" << arr[i] << "," << arr[j] << ") ";
    cout << endl;
}

int main() {
    int arr[] = {4, 8, 15, 16, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "first  (O(1)) : " << first(arr) << endl;
    cout << "sum    (O(n)) : " << sum(arr, n) << endl;
    cout << "pairs (O(n^2)):\n";
    pairs(arr, n);
    return 0;
}
