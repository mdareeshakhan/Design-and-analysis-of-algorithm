// DAA Lesson 4 — Performance Measurement
//
// Two ways to measure an algorithm's performance:
//   1. EMPIRICAL   : actually run the code and time it with a clock.
//                    Gives real time, but is MACHINE-DEPENDENT.
//   2. THEORETICAL : count basic operations vs input size n (Big-O).
//                    MACHINE-INDEPENDENT — same on any computer.
//
// Best practice: use BOTH. Understand with theory, confirm with experiment.
//
// This program empirically times an O(n) function using <chrono>.
// Tip: run for several values of n and watch how the time grows.
//   n = 10,000,000   -> ~30 ms
//   n = 100,000,000  -> ~300 ms   (10x n -> 10x time = linear = O(n))

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

long sumTo(int n) {              // O(n) work: one loop over n
    long s = 0;
    for (int i = 1; i <= n; i++)
        s += i;
    return s;
}

int main() {
    int n = 100000000;

    auto t1 = high_resolution_clock::now();          // start clock
    long result = sumTo(n);
    auto t2 = high_resolution_clock::now();          // stop clock

    auto ms = duration_cast<milliseconds>(t2 - t1).count();
    cout << "Result: " << result << endl;
    cout << "Time:   " << ms << " ms" << endl;
    return 0;
}
