// DAA Lesson 7 — Merge Sort
//
// Merge Sort is a DIVIDE AND CONQUER algorithm in two steps:
//   1. DIVIDE : keep splitting the array in half until each piece has
//               one element (a single element is already sorted).
//   2. MERGE  : combine two sorted pieces into one sorted piece by
//               repeatedly taking the smaller front element.
//
// Time  : O(n log n) in ALL cases (best, average, worst) — guaranteed.
// Space : O(n) extra (temporary arrays for merging).
// Stable: yes.

#include <iostream>
using namespace std;

// Merge two sorted halves arr[l..m] and arr[m+1..r].
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)                       // take the smaller front
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];              // leftovers of L
    while (j < n2) arr[k++] = R[j++];              // leftovers of R
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);                      // sort left half
        mergeSort(arr, m + 1, r);                  // sort right half
        merge(arr, l, m, r);                       // merge the two halves
    }
}

int main() {
    int arr[] = {5, 2, 8, 4, 7, 1, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";   // 1 2 3 4 5 6 7 8
    cout << endl;
    return 0;
}
