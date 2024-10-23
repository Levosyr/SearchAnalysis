#include <iostream>
#include <vector>
#include <algorithm>  // For sort()
#include <random>     // For random number generation
#include <chrono>     // For measuring execution time

using namespace std;
using namespace std::chrono;

// Recursive Binary Search
int recursiveBinarySearch(const vector<int>& arr, int target, int low, int high) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] > target) return recursiveBinarySearch(arr, target, low, mid - 1);
    else return recursiveBinarySearch(arr, target, mid + 1, high);
}

// Iterative Binary Search
int iterativeBinarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

// Sequential Search
int sequentialSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main() {
    // Define constants
    int N = 200000;  // Set N for testing (adjust as needed)
    double SumRBS = 0.0, SumIBS = 0.0, SumSeqS = 0.0;

    // Random number generator setup
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> dist(1, 100);

    // Run the loop 10 times
    for (int run = 0; run < 10; run++) {
        // Generate a vector of N random numbers
        vector<int> arr;
        for (int i = 0; i < N; i++) {
            arr.push_back(dist(rng));
        }
        // Sort the vector to prepare for binary search
        sort(arr.begin(), arr.end());

        // Generate a random target
        int target = dist(rng);

        // Measure the time for Recursive Binary Search
        auto start = high_resolution_clock::now();
        recursiveBinarySearch(arr, target, 0, arr.size() - 1);
        auto end = high_resolution_clock::now();
        duration<double, micro> durationRBS = end - start;
        SumRBS += durationRBS.count();

        // Measure the time for Iterative Binary Search
        start = high_resolution_clock::now();
        iterativeBinarySearch(arr, target);
        end = high_resolution_clock::now();
        duration<double, micro> durationIBS = end - start;
        SumIBS += durationIBS.count();

        // Measure the time for Sequential Search
        start = high_resolution_clock::now();
        sequentialSearch(arr, target);
        end = high_resolution_clock::now();
        duration<double, micro> durationSeqS = end - start;
        SumSeqS += durationSeqS.count();
    }

    // Print average running times
    cout << "Average Running Time for Recursive Binary Search in microseconds is " << SumRBS / 10 << endl;
    cout << "Average Running Time for Iterative Binary Search in microseconds is " << SumIBS / 10 << endl;
    cout << "Average Running Time for Sequential Search in microseconds is " << SumSeqS / 10 << endl;

    return 0;
}
