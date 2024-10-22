#include <iostream>
#include <vector>
#include <algorithm> // For sorting

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
    // Step 1: Fill a vector with test data
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Step 2: Sort the vector (already sorted in this case)
    sort(arr.begin(), arr.end());

    int target1 = 6;  // An item that is in the list
    int target2 = 11; // An item that is not in the list

    // Recursive Binary Search
    int index = recursiveBinarySearch(arr, target1, 0, arr.size() - 1);
    cout << "Recursive Binary Search - Target " << target1 << " found at location " << index << endl;
    index = recursiveBinarySearch(arr, target2, 0, arr.size() - 1);
    cout << "Recursive Binary Search - Target " << target2 << " was not found, return value is " << index << endl;

    // Iterative Binary Search
    index = iterativeBinarySearch(arr, target1);
    cout << "Iterative Binary Search - Target " << target1 << " found at location " << index << endl;
    index = iterativeBinarySearch(arr, target2);
    cout << "Iterative Binary Search - Target " << target2 << " was not found, return value is " << index << endl;

    // Sequential Search
    index = sequentialSearch(arr, target1);
    cout << "Sequential Search - Target " << target1 << " found at location " << index << endl;
    index = sequentialSearch(arr, target2);
    cout << "Sequential Search - Target " << target2 << " was not found, return value is " << index << endl;

    return 0;
}
