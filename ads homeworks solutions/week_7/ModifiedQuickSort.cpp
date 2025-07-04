#include <algorithm>
#include <iostream>
#include <chrono>
#include <random>




int partition(int* arr, int low, int high, int* lp){
    if (arr[low] > arr[high])
    std::swap(arr[low], arr[high]);


    int j = low + 1;
    int g = high - 1, k = low + 1, p = arr[low], q = arr[high];
    while (k <= g) {


        if (arr[k] < p) {
            std::swap(arr[k], arr[j]);
            j++;
        }

        else if (arr[k] >= q) {
            while (arr[g] > q && k < g)
                g--;
            std::swap(arr[k], arr[g]);
            g--;
            if (arr[k] < p) {
                std::swap(arr[k], arr[j]);
                j++;
            }
        }
        k++;
    }
    j--;
    g++;


    std::swap(arr[low], arr[j]);
    std::swap(arr[high], arr[g]);

    *lp = j; 
    return g;
}

void DualPivotQuickSort(int* arr, int low, int high)
{
    if (low < high) {

        int lp, rp;
        rp = partition(arr, low, high, &lp);
      
        DualPivotQuickSort(arr, low, lp - 1);
        DualPivotQuickSort(arr, lp + 1, rp - 1);
        DualPivotQuickSort(arr, rp + 1, high);
    }
}

void RandomQuickSort(int arr[], int start, int end) {
    if (start >= end) return;

    if (start + 1 < end) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(start, end);
        
        int rand1 = dis(gen);
        int rand2;
        do {
            rand2 = dis(gen);
        } while (rand2 == rand1);
        
        std::swap(arr[start], arr[rand1]);
        std::swap(arr[start + 1], arr[rand2]);
        
        int pivot1 = arr[start];
        int pivot2 = arr[start + 1];
        
        int low = start + 2;    
        int mid = low;          
        int high = end;         

        while (mid <= high) {
            if (arr[mid] < pivot1) {
                std::swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] > pivot2) {
                std::swap(arr[mid], arr[high]);
                high--;
            }
            else {
                mid++;
            }
        }
        
        low--;
        high++;
        std::swap(arr[start], arr[low]);
        std::swap(arr[start + 1], arr[high - 1]);
        
        DualPivotQuickSort(arr, start, low - 1);      
        DualPivotQuickSort(arr, low + 1, high - 2);   
        DualPivotQuickSort(arr, high, end);           
    }
    else {
        if (start + 1 == end && arr[start] > arr[end]) {
            std::swap(arr[start], arr[end]);
        }       
    }
}


int main() {
    int arr1[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int arr2[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    DualPivotQuickSort(arr1, 0, n - 1);
    RandomQuickSort(arr2, 0, n - 1);

    for (int i = 0; i < n; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;



    return 0;
}