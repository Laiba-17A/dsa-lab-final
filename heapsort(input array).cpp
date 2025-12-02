#include <iostream>
using namespace std;

// Heapify a subtree rooted at index i in arr[]
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Build max heap + perform heapsort
void heapsort(int arr[], int n) {
    // Step 1: Build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements one by one
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);   // Move max to end
        heapify(arr, i, 0);     // Heapify reduced heap
    }
}

int main() {
    int arr[] = {45, 20, 35, 10, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapsort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
