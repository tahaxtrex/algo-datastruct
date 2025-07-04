#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;
using namespace std::chrono;

// Function to perform Selection Sort
void SelectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Function to generate a random array (Used for Worst & Average Cases)
vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size; // Random values between 0 and size-1
    }
    return arr;
}

// Function to generate a worst-case array (randomly shuffled)  
vector<int> generateWorstCaseArray(vector<int> array) {
    for (int i = 0; i < array.size() ; i++) {
        if (i % 2 == 0) {
            array[i] = i + 2;  // If i is even, increase value
        } else {
            array[i] = i;  // If i is odd, keep value the same
        }
    }
    return array;
}

// Function to generate a best-case array (Already sorted)
vector<int> generateBestCaseArray(vector<int> array) {
    sort(array.begin(), array.end());
    return array;
}

// Function to measure execution time
double measureExecutionTime(vector<int> arr) {
    auto start = high_resolution_clock::now();
    SelectionSort(arr);
    auto stop = high_resolution_clock::now();
    return duration<double, micro>(stop - start).count(); // Time in microseconds
}

int main() {
    srand(time(0));  // Seed randomness

    cout << "Size\tWorst Case (us)\tBest Case (us)\tAverage Case (us)" << endl;

    for (int size = 10; size <= 500; size += 50) { // Test for increasing sizes
        // Measure Worst Case (Most swaps)
        vector<int> array(size);
        vector<int> worstCase = generateWorstCaseArray(array);
        double worstTime = measureExecutionTime(worstCase);

        // Measure Best Case (Already sorted)
        vector<int> bestCase = generateBestCaseArray(array);
        double bestTime = measureExecutionTime(bestCase);

        // Measure Average Case (Take multiple random arrays and average)
        double sum = 0;
        for (int i = 0; i < 5; i++) { // Run 5 times for accuracy
            vector<int> avgCase = generateRandomArray(size);
            sum += measureExecutionTime(avgCase);
        }
        double avgTime = sum / 5; // Compute average time

        // Print results to console
        cout << size << "\t" << worstTime << "\t\t" << bestTime << "\t\t" << avgTime << endl;
    }

    return 0;
}