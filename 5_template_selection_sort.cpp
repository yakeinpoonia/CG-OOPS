#include <iostream>
using namespace std;

// Function template for selection sort
template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        T temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to print the array
template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Input and sort integer array
    int intSize;
    cout << "Enter the number of integers: ";
    cin >> intSize;

    int* intArray = new int[intSize];
    cout << "Enter the integers: ";
    for (int i = 0; i < intSize; i++) {
        cin >> intArray[i];
    }

    selectionSort(intArray, intSize);
    cout << "Sorted integer array: ";
    printArray(intArray, intSize);

    // Input and sort float array
    int floatSize;
    cout << "Enter the number of floats: ";
    cin >> floatSize;

    float* floatArray = new float[floatSize];
    cout << "Enter the floats: ";
    for (int i = 0; i < floatSize; i++) {
        cin >> floatArray[i];
    }

    selectionSort(floatArray, floatSize);
    cout << "Sorted float array: ";
    printArray(floatArray, floatSize);

    // Clean up dynamic memory
    delete[] intArray;
    delete[] floatArray;

    return 0;
}
