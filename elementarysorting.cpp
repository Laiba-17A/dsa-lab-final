#include <iostream>
using namespace std;

// ==================== Sorting Algorithms ====================

// 1. Shell Sort: Improved insertion sort that allows exchange of far apart elements
void shellSort(int a[], int n) {
    for(int gap = n / 2; gap > 0; gap /= 2) {
        for(int i = gap; i < n; i++) {
            int temp = a[i];
            int j;
            for(j = i; j >= gap && a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}

// 2. Comb Sort: Improves bubble sort by using gap shrinking (eliminates turtles)
int nextGap(int gap) { // helper function for Comb Sort
    gap = (gap * 10) / 13;
    return (gap < 1) ? 1 : gap;
}

void combSort(int a[], int n) {
    int gap = n;
    bool swapped = true;
    while(gap != 1 || swapped) {
        gap = nextGap(gap);
        swapped = false;
        for(int i = 0; i + gap < n; i++) {
            if(a[i] > a[i + gap]) {
                swap(a[i], a[i + gap]);
                swapped = true;
            }
        }
    }
}

// 3. Bubble Sort: Repeatedly swaps adjacent elements if they are in wrong order
void bubbleSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// 4. Insertion Sort: Builds sorted array one element at a time by shifting elements
void insertionSort(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

/*
Sorting Techniques Summary:

Shell Sort      : Improved insertion sort using gap-based element shifting
Comb Sort       : Bubble sort variant using shrinking gap to eliminate turtles
Bubble Sort     : Swaps adjacent elements repeatedly if in wrong order
Insertion Sort  : Inserts elements into sorted position one at a time

Time Complexities:
Shell Sort      : Best O(n log n), Average O(n log n), Worst O(n^2)
Comb Sort       : Best O(n log n), Average O(n^2 / 2^p), Worst O(n^2)
Bubble Sort     : Best O(n), Average O(n^2), Worst O(n^2)
Insertion Sort  : Best O(n), Average O(n^2), Worst O(n^2)

Space Complexity: All are O(1)
Stability       : Shell & Comb unstable, Bubble & Insertion stable
In-place        : All
*/
