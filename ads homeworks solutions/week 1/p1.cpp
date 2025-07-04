#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T> // template for generic type

int array_search(T arr[], int size, T key) { // function to search for key in array
    for (int i = 0; i < size; i++) {    // loop through array AND CHECK IF KEY IS PRESENT
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;  // return -1 if key is not found
}

class complex { // class for complex numbers    
    public:
        int real, imag;

        complex(int r = 0, int i = 0) {
            real = r;
            imag = i;
        }

        bool operator==(const complex &c) {
            return (real == c.real && imag == c.imag);
        }
};

int main() {

    int arr[] = {1, 2, 3, 4, 5}; // array of integers
    int n = sizeof(arr) / sizeof(arr[0]); // size of array
    complex arr2[] = {complex(1, 2), complex(3, 4), complex(5, 6)}; // array of complex numbers
    complex key(3, 4);  // key to search
    cout << array_search(arr2, n, key) << endl; // search for key in array


    return 0;
}

