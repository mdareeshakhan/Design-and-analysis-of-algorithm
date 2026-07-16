// DAA Lesson 2 — Analyzing an Algorithm
// We do NOT measure an algorithm in seconds (machine-dependent).
// Instead we count the number of basic operations as a function of the
// input size n, and study how it grows.
//
// Two resources: TIME complexity (operations) and SPACE complexity (memory).
// Three cases: BEST, AVERAGE, WORST (we usually focus on the worst case).
//
// Example: Linear Search — scan left to right, compare each element with key.
//   Best case  : key is the first element   -> 1 comparison   -> O(1)
//   Worst case : key is last / not present  -> n comparisons  -> O(n)
// Space complexity: O(1)

#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)    // scan left to right
        if (arr[i] == key)         // basic operation: comparison
            return i;              // found -> return index
    return -1;                     // not found
}

int main() {
    int arr[] = {4, 8, 15, 16, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int idx = linearSearch(arr, n, 16);
    cout << "Found 16 at index: " << idx << endl;   // -> 3
    return 0;
}
