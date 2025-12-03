#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countingSort(int arr[], int n, int exp) {
    int output[1000];
    int count[10] = {0};

    // Count digits
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Prefix sum
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output (stable)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy back
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}