#include <iostream>
using namespace std;

/* =======================
   LINEAR SEARCH
   ======================= */
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;   // element found
    }
    return -1;          // element not found
}

/*
Properties:
- Works on both sorted and unsorted arrays
- Simple to implement
- Time Complexity:
  Best: O(1)
  Average: O(n)
  Worst: O(n)
- Space Complexity: O(1)
*/


/* =======================
   BINARY SEARCH
   ======================= */
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

/*
Properties:
- Array MUST be sorted
- Faster than linear search
- Time Complexity:
  Best: O(1)
  Average: O(log n)
  Worst: O(log n)
- Space Complexity: O(1)
*/


/* =======================
   INTERPOLATION SEARCH
   ======================= */
int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while(low <= high && key >= arr[low] && key <= arr[high]) {

        if(low == high) {
            if(arr[low] == key) return low;
            return -1;
        }

        int pos = low + ((key - arr[low]) * (high - low)) 
                         / (arr[high] - arr[low]);

        if(arr[pos] == key)
            return pos;
        else if(arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

/*
Properties:
- Array MUST be sorted and uniformly distributed
- Faster than binary search in best case
- Time Complexity:
  Best: O(1)
  Average: O(log log n)
  Worst: O(n)
- Space Complexity: O(1)
*/


/* =======================
   MAIN (for testing)
   ======================= */
int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;

    cout << "Linear Search: " 
         << linearSearch(arr, n, 40) << endl;

    cout << "Binary Search: " 
         << binarySearch(arr, n, 40) << endl;

    cout << "Interpolation Search: " 
         << interpolationSearch(arr, n, 40) << endl;

    return 0;
}
