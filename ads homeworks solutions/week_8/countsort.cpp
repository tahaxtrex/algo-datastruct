#include <iostream>

int main() {
    int array[] = {9, 1, 6, 7, 6, 2, 1};

    int n = 7;
    int output[n]; 
    int k = 10;

    int temp[k] = {0};

    for (int i = 0; i < n; i++) {
        temp[array[i]]++;
    }
    for (int i = 1; i < k; i++) {
        temp[i] += temp[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {  
        output[temp[array[i]] - 1] = array[i];
        temp[array[i]]--;  
    }
    for (int i = 0; i < n; i++) {
        std::cout << output[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
