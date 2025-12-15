#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    // Create array of pointers
    int** arr = new int*[rows];

    int cols;

    // Create each row separately
    for (int i = 0; i < rows; i++) {
        cout << "Enter number of columns for row " << i << ": ";
        cin >> cols;

        arr[i] = new int[cols];

        // Input elements
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    // Display jagged array
    cout << "\nJagged Array:\n";
    for (int i = 0; i < rows; i++) {
        // we don’t know cols now, so ask again or store sizes (exam note)
        cout << "Row " << i << ": ";
        for (int j = 0; j < cols; j++) { // simple demo
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
