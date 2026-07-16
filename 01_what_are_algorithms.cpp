// DAA Lesson 1 — What are Algorithms?
// An algorithm = a finite, clearly-defined list of steps to solve a problem.
// 5 properties: Input, Output, Definiteness, Finiteness, Effectiveness.
//
// Example algorithm: find the largest number in an array.
// Idea: assume the first element is the max, then scan the rest and
//       update max whenever a bigger element is found.
// Time complexity: O(n)  (each element is looked at exactly once)
// Space complexity: O(1)

#include <iostream>
using namespace std;

int findLargest(int arr[], int n) {
    int max = arr[0];              // step 1: first element is the max so far
    for (int i = 1; i < n; i++)    // step 2: look at every other element
        if (arr[i] > max)          // found a bigger one?
            max = arr[i];          // update max
    return max;                    // step 3: max now holds the largest
}

int main() {
    int arr[] = {7, 2, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\nLargest: " << findLargest(arr, n) << endl;
    return 0;
}
