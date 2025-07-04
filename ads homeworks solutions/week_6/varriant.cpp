#include <iostream>
using namespace std;

int floatDown(int arr[], int n, int i) {
    int current = i;
    int leftChild, rightChild, largerChild;
    int temp = arr[current];  

    while (2 * current + 1 < n) { 
        leftChild = 2 * current + 1;
        rightChild = leftChild + 1;

        if (rightChild < n && arr[rightChild] > arr[leftChild])
            largerChild = rightChild;
        else
            largerChild = leftChild;

        arr[current] = arr[largerChild];
        current = largerChild;
    }

    arr[current] = temp; 
    return current; 
}

void floatUp(int arr[], int i) {
    int parent = (i - 1) / 2;
    int temp = arr[i];  

    while (i > 0 && temp > arr[parent]) {
        arr[i] = arr[parent];  
        i = parent;
        parent = (i - 1) / 2;
    }
    arr[i] = temp;  
}


void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        int finalPosition = floatDown(arr, n, i);
        floatUp(arr, finalPosition);
    }
}

void bottomUpHeapSort(int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        int finalPosition = floatDown(arr, i, 0); 
        floatUp(arr, finalPosition); 
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {4, 10, 3, 5, 1, 8, 7, 2, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    bottomUpHeapSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
