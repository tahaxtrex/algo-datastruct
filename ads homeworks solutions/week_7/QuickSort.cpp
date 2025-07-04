#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>

#define len 1000

void QuickSort1(int arr[], int start, int end);
void QuickSort2(int arr[], int start, int end);
void QuickSort3(int arr[], int start, int end);

int lomotoPartition(int arr[], int start, int end) {
    int pivot = arr[end];  
    int i = start;
    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[end]);  
    return i;
}


int hoarePartition(int arr[], int start, int end) {
    int pivot = arr[start];  
    int i = start - 1, j = end + 1;

    while (true) {
        do {
            i++;  
        } while (arr[i] < pivot);

        do {
            j--;  
        } while (arr[j] > pivot);

        if (i >= j) return j;  

        std::swap(arr[i], arr[j]); 
    }
}

int medianOfThreePivot(int arr[], int start, int end) {
    int mid = start + (end - start) / 2;  

    if (arr[mid] < arr[start]) std::swap(arr[mid], arr[start]);
    if (arr[end] < arr[start]) std::swap(arr[end], arr[start]);
    if (arr[end] < arr[mid]) std::swap(arr[end], arr[mid]);
    return mid;  
}


int medianOfThreePartition(int arr[], int start, int end) {
    int pivotIndex = medianOfThreePivot(arr, start, end);
    int pivot = arr[pivotIndex];
    int i = start;

    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[end]); 
    return i;
}


void QuickSort1(int arr[], int start, int end) {
    if (start >= end) return;

    int pivot = lomotoPartition(arr, start, end);
    QuickSort1(arr, start, pivot - 1);
    QuickSort1(arr, pivot + 1, end);
}


void QuickSort2(int arr[], int start, int end) {
    if (start >= end) return;

    int pivot = hoarePartition(arr, start, end);
    QuickSort2(arr, start, pivot);  
    QuickSort2(arr, pivot + 1, end);
}


void QuickSort3(int arr[], int start, int end) {
    if (start >= end) return;

    int pivot = medianOfThreePartition(arr, start, end);
    QuickSort3(arr, start, pivot - 1);
    QuickSort3(arr, pivot + 1, end);
}


int main() {
    
    long long total_time1 = 0, total_time2 = 0, total_time3 = 0;
    
    for (int i = 0; i < 1000; i++) {
        int arr[len];
        for (int j = 0; j < len; j++) {
            arr[j] = rand() % 1000;
        }
        auto start = std::chrono::high_resolution_clock::now();
        QuickSort1(arr, 0, len - 1);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        total_time1 += duration.count();
    }

    for (int i = 0; i < 1000; i++) {
        int arr[len];
        for (int j = 0; j < len; j++) {
            arr[j] = rand() % 1000;
        }
        auto start = std::chrono::high_resolution_clock::now();
        QuickSort2(arr, 0, len - 1);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        total_time2 += duration.count();
    }

    for (int i = 0; i < 1000; i++) {
        int arr[len];
        for (int j = 0; j < len; j++) {
            arr[j] = rand() % 1000;
        }
        auto start = std::chrono::high_resolution_clock::now();
        QuickSort3(arr, 0, len - 1);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        total_time3 += duration.count();
    }

    std::cout << "Total time taken by QuickSort1: " << total_time1 << " microseconds" << std::endl;
    std::cout << "Total time taken by QuickSort2: " << total_time2 << " microseconds" << std::endl;
    std::cout << "Total time taken by QuickSort3: " << total_time3 << " microseconds" << std::endl;


    return 0;
}
