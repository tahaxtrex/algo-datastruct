/*
Taha Hbirri
thbirri@constructor.university
A4 P1
MergeSort.cpp*/



#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <fstream>

void MergeSort(std::vector<int> &array, int lenght, int variant);
void divide(std::vector<int> &array, int l, int r, int variant);
void merge(std::vector<int> &array, int l, int mid, int r);
void insertionSort(std::vector<int> &arr, int left, int right);
std::vector<int> GenArray(int lenght);
std::vector<int> WorstArray(std::vector<int> &array);
std::vector<int> SortArray(std::vector<int> &array); 





int main() {

    std::ofstream outFile("results.txt"); // Create and open the file
    if (!outFile) { 
    std::cerr << "Error opening file!" << std::endl;
    return 1; 
    }

    int lenght = 10000;
    std::vector<int>array = GenArray(lenght);
    int k;

    std::cout<<"average case: "<<std::endl;
    
    outFile<<"average case: "<<std::endl;
    for(int k = 0; k<lenght; k += 1000){
        auto start = std::chrono::high_resolution_clock::now();
        MergeSort(array, lenght, k);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        outFile << "k = " << k << " Time: " << diff.count() * 1000 << " ms\n";
        std::cout << diff.count()*1000 << std::endl;
        
    }
    outFile<<"Worst case: "<<std::endl;
    std::vector<int> worstarray = WorstArray(array);
    std::cout<<"worst case: "<<std::endl;
    for(int k = 0; k<lenght; k += 1000){
        auto start = std::chrono::high_resolution_clock::now();
        MergeSort(worstarray, lenght, k);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        outFile << "k = " << k << " Time: " << diff.count() * 1000 << " ms\n";
        std::cout << diff.count()*1000 << std::endl;
    }
    outFile<<"Best case: "<<std::endl;
    std::vector<int>bestarray = SortArray(array);
    std::cout<<"Best case: "<<std::endl;
    for(int k = 0; k<lenght; k += 1000){
        auto start = std::chrono::high_resolution_clock::now();
        MergeSort(bestarray, lenght, k);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        outFile << "k = " << k << " Time: " << diff.count() * 1000 << " ms\n";
        std::cout << diff.count()*1000 << std::endl;
    }

    outFile.close();
    return 0;
}

void insertionSort(std::vector<int> &arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void MergeSort(std::vector<int> &array, int length, int variant) {
    divide(array, 0, length - 1, variant);
}

void divide(std::vector<int> &array, int l, int r, int variant){

    if ((r - l + 1) <= variant) {
        insertionSort(array, l, r);
        return;
    }    
    
    if(l<r){
        int mid = (l + r)/2;
        
        divide(array, l, mid, variant);
        divide(array, mid+1, r, variant);
        merge(array, l, mid, r);
    }
    
}

void merge(std::vector<int> &array, int l, int mid, int r){
    
    int n1 = mid - l + 1;
    int n2 = r - mid;
    
    std::vector<int> L(n1);
    std::vector<int> R(n2);
    
    for(int i = 0; i < n1; i++){
        L[i] = array[l + i];
    }
    
    for(int i = 0; i < n2; i++){
        R[i] = array[mid + 1 + i];
    }
    
    int i = 0;
    int j = 0;
    int k = l;
    
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            array[k++] = L[i++];
        }else{
            array[k++] = R[j++];
        }
    }
    
    while(i < n1){
        array[k++] = L[i++];
    }
    
    while(j < n2){
        array[k++] = R[j++];
    }
}

std::vector<int> GenArray(int lenght){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 9999);
    std::vector<int> array;

    for(int i = 0; i < lenght; i++){
        array.push_back(dis(gen));
    }

    return array;
}

std::vector<int> SortArray(std::vector<int> &array){
    std::sort(array.begin(), array.end());
    return array;
}

std::vector<int> WorstArray(std::vector<int> &array){
    std::sort(array.begin(), array.end(), std::greater<int>());
    return array;
}