// DAA Lesson 5 — Shell Sort
//
// Shell Sort (Donald Shell, 1959) is a generalization of insertion sort.
// Insertion sort only compares ADJACENT elements (gap = 1), so a small
// element far to the right takes many steps to reach its place.
//
// Shell sort fixes this by first comparing elements a large GAP apart,
// then shrinking the gap:  gap = n/2, n/4, ... , 1.
// The final pass (gap = 1) is a normal insertion sort, but by then the
// array is almost sorted, so it is fast.
//
// Time  : worst O(n^2), often ~O(n^1.5) in practice (depends on gap sequence)
// Space : O(1)  (in-place)

#include <iostream>
using namespace std;

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {        // gap: n/2, n/4, ... 1
        for (int i = gap; i < n; i++) {               // gapped insertion sort
            int temp = arr[i], j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];                // shift larger element right
            arr[j] = temp;                            // place temp in its spot
        }
    }
}

int main() {
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44};
    int n = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, n);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";   // 10 14 19 27 33 35 42 44
    cout << endl;
    return 0;
}
