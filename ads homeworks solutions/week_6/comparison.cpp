#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void heapSort(vector<int>& arr) {
    buildMaxHeap(arr);
    for (int i = arr.size() - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int floatDown(vector<int>& arr, int n, int i) {
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

void floatUp(vector<int>& arr, int i) {
    int parent = (i - 1) / 2;
    int temp = arr[i];

    while (i > 0 && temp > arr[parent]) {
        arr[i] = arr[parent];
        i = parent;
        parent = (i - 1) / 2;
    }
    arr[i] = temp;
}

void buildMaxHeapBottomUp(vector<int>& arr) {
    for (int i = arr.size() / 2 - 1; i >= 0; i--) {
        int finalPosition = floatDown(arr, arr.size(), i);
        floatUp(arr, finalPosition);
    }
}

void bottomUpHeapSort(vector<int>& arr) {
    buildMaxHeapBottomUp(arr);

    for (int i = arr.size() - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        int finalPosition = floatDown(arr, i, 0);
        floatUp(arr, finalPosition);
    }
}

void compareSortingPerformance(int n) {
    vector<int> arr1(n), arr2(n);

    // Generate random data
    for (int i = 0; i < n; i++)
        arr1[i] = arr2[i] = rand() % 100000;

    // Measure Standard Heap Sort
    auto start = high_resolution_clock::now();
    heapSort(arr1);
    auto stop = high_resolution_clock::now();
    auto durationHeapSort = duration_cast<milliseconds>(stop - start);

    
    start = high_resolution_clock::now();
    bottomUpHeapSort(arr2);
    stop = high_resolution_clock::now();
    auto durationBottomUp = duration_cast<milliseconds>(stop - start);

   
    cout << "Array Size: " << n << endl;
    cout << "Heap Sort Time: " << durationHeapSort.count() << " ms" << endl;
    cout << "Bottom-Up Heap Sort Time: " << durationBottomUp.count() << " ms" << endl;
    cout << "--------------------------------------" << endl;
}

// Main function to compare performance
int main() {
    srand(time(0));

    vector<int> sizes = {1000, 10000, 100000, 1000000};  // Different input sizes
    for (int n : sizes)
        compareSortingPerformance(n);

    return 0;
}


/*
result output:

Array Size: 1000
Heap Sort Time: 0 ms
Bottom-Up Heap Sort Time: 0 ms
--------------------------------------
Array Size: 10000
Heap Sort Time: 2 ms
Bottom-Up Heap Sort Time: 1 ms
--------------------------------------
Array Size: 100000
Heap Sort Time: 29 ms
Bottom-Up Heap Sort Time: 17 ms
--------------------------------------
Array Size: 1000000
Heap Sort Time: 336 ms
Bottom-Up Heap Sort Time: 220 ms


we notice that the bottum up heap sort is more fast and optimized for larger values of n but similar when the values are small*/
