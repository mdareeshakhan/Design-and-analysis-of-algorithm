// DAA Lesson 6 — Quick Sort
//
// Quick Sort is a DIVIDE AND CONQUER sorting algorithm.
//   1. Pick a PIVOT (here: the last element).
//   2. PARTITION: rearrange so elements < pivot go left, > pivot go right.
//      After this, the pivot sits at its FINAL sorted position.
//   3. Recursively quick-sort the left part and the right part.
//
// Time  : average O(n log n)  (very fast in practice)
//         worst   O(n^2)      (bad pivot, e.g. already-sorted input)
// Space : O(log n)            (recursion stack)

#include <iostream>
using namespace std;

// Lomuto partition: pivot = arr[high]. Returns pivot's final index.
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)                 // smaller element -> left side
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);            // put pivot in its place
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);  // pivot index
        quickSort(arr, low, p - 1);         // sort left part
        quickSort(arr, p + 1, high);        // sort right part
    }
}

int main() {
    int arr[] = {8, 3, 7, 4, 9, 2, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";   // 2 3 4 5 6 7 8 9
    cout << endl;
    return 0;
}
