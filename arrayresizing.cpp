#include <iostream>
using namespace std;

int main() {

    /* =======================
       1D ARRAY RESIZING
       ======================= */

    int oldSize = 5;
    int newSize = 8;

    int* arr = new int[oldSize];

    // initialize 1D array
    for (int i = 0; i < oldSize; i++)
        arr[i] = i + 1;

    // resize 1D array
    int* temp1D = new int[newSize];

    for (int i = 0; i < oldSize; i++)
        temp1D[i] = arr[i];

    delete[] arr;
    arr = temp1D;

    cout << "Resized 1D Array:\n";
    for (int i = 0; i < newSize; i++)
        cout << arr[i] << " ";
    cout << endl << endl;


    /* =======================
       2D ARRAY RESIZING
       ======================= */

    int rows = 2, cols = 3;

    // create original 2D array
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];

    // initialize 2D array
    int value = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = value++;

    // new size
    int newRows = 4;
    int newCols = 5;

    // create resized 2D array
    int** temp2D = new int*[newRows];
    for (int i = 0; i < newRows; i++)
        temp2D[i] = new int[newCols];

    // copy old data
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            temp2D[i][j] = matrix[i][j];

    // delete old 2D array
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;

    matrix = temp2D;
    rows = newRows;
    cols = newCols;

    cout << "Resized 2D Array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    // cleanup
    delete[] arr;
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}
