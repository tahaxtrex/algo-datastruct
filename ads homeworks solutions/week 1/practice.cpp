#include <iostream>
#include <string>


template <typename T>;

int array_search(T arr, int size, T key){
    for(int i = 0; i < size; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
    
}

class Complex{
    public :
        float x;
        float y;
        Complex(){
            x =0;y=0;
        }
        Complex(float real, float imag){
            x = real;
            y = imag;
        }
};

int main(){

    int arr[] = {1,2,3,4,5};
    char arr1[] = {'a','b','c','d','e'};
    Complex arr2[] = {Complex(1,2),Complex(3,4),Complex(5,6)};
    Complex key(3,4);
    std::cout << array_search(arr2,3,key) << std::endl;

    return 0;
}