/*
Taha Hbirri
ADS hw5 p1*/

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>

int recursiveway(int n){
    if(n == 0  || n == 1) return n;
    return recursiveway(n-1) + recursiveway(n-2);
}

int iterationway(int n){
    if(n<2) return n;
    int a = 0;
    int b = 1;
    int c;
    for(int i = 2; i<=n; i++){
    c = a + b;
    a = b;
    b = c;
    }
    return b;
}

int ClosedForm(int n) {
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, n) / sqrt(5));
}

void multiplyMatrix(int F[2][2], int M[2][2]) {
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void powerMatrix(int F[2][2], int n) {
    if (n == 0 || n == 1)
        return;
    
    int M[2][2] = {{1, 1}, {1, 0}};
    
    powerMatrix(F, n / 2);
    multiplyMatrix(F, F);
    
    if (n % 2 != 0)
        multiplyMatrix(F, M);
}

int fibonacciMatrix(int n) {
    if (n == 0 || n == 1)
        return n;
    
    int F[2][2] = {{1, 1}, {1, 0}};
    powerMatrix(F, n - 1);
    int m;
    m = F[0][0];
    return m;
}


int main(){

    std::ofstream file;
    file.open("fibonacci.txt");
    file << "n" << "\t\t" << "Recursion" << "\t\t" << "Iteration" << "\t\t" << "Closed" << "\\tt" << "Matrix" << std::endl;
    for(int i = 0; i<40; i+=2){
        auto start = std::chrono::high_resolution_clock::now();
        recursiveway(i);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        double time1 = elapsed.count()*1000;
        
        start = std::chrono::high_resolution_clock::now();
        iterationway(i);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        double time2 = elapsed.count()*1000;
        
        start = std::chrono::high_resolution_clock::now();
        ClosedForm(i);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        double time3 = elapsed.count()*1000;
        
        start = std::chrono::high_resolution_clock::now();
        fibonacciMatrix(i);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        double time4 = elapsed.count()*1000;
        
        file << i << "\t\t" << time1 << "\t\t" << time2 << "\t\t" << time3 << "\t\t" << time4 << std::endl;
    }
    file.close();

    
    return 0;
}