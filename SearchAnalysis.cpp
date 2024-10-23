#include <iostream>
#include <vector>
#include <algorithm>  // For sort
#include <random>     // For random number generation

using namespace std;

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
    // Step 1: Fill a vector with random data
    vector<int> arr;
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> dist(1, 100);

    // Fill vector with random numbers (for example, 10 elements)
    for (int i = 0; i < 10; i++) {
        arr.push_back(dist(rng));
    }

    // Step 2: Sort the vector
    sort(arr.begin(), arr.end());

    // Generate a random target
    int target = dist(rng);
    cout << "Random target: " << target << endl;

    // Recursive Binary Search
    int index = recursiveBinarySearch(arr, target, 0, arr.size() - 1);
    if (index >= 0) {
        cout << "Recursive Binary Search - Target found at location " << index << endl;
    }
    else {
        cout << "Recursive Binary Search - Target was not found" << endl;
    }

    // Iterative Binary Search
    index = iterativeBinarySearch(arr, target);
    if (index >= 0) {
        cout << "Iterative Binary Search - Target found at location " << index << endl;
    }
    else {
        cout << "Iterative Binary Search - Target was not found" << endl;
    }

    // Sequential Search
    index = sequentialSearch(arr, target);
    if (index >= 0) {
        cout << "Sequential Search - Target found at location " << index << endl;
    }
    else {
        cout << "Sequential Search - Target was not found" << endl;
    }

    return 0;
}
