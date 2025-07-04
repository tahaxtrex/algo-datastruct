#include <iostream>
#include <list>
#include <string>
#include <fstream>

int main() {
    std::ofstream file("result.txt"); // Open file for writing

    if (!file) {
        std::cerr << "This file does not exist" << std::endl;
        return 1;
    }

    std::list<int> a;
    std::list<int> b;
    int n;
    int size = 0;

    // Read numbers until a number < 1 is entered
    while (true) {
        std::cin >> n;
        if (n < 1) {
            break;
        }
        a.push_back(n);
        b.push_front(n);
        size ++;
    }

    std::cout << "list a is : ";
    for (int value : a) {
        std::cout << value << " "; 
    }
    std::cout << std::endl;
    

    for (int value : b) {
        file << value << " ";
    }

    file << std::endl;
    file.close();

    if(size > 1){
        int x = a.front();
        int y = b.front();
        a.pop_front();
        b.pop_front();
        a.push_back(x);
        b.push_back(x);
    }

    std::cout << "list a is : ";
    std::list<int>::iterator it = a.begin();
    while (it != a.end()) {
        if(it != a.begin()){
            std::cout<<",";
        }
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
    auto it2 = b.begin();
    while (it2 != b.end()) {
        if(it2 != b.begin()){
            std::cout<<",";
        }
        std::cout << *it2 << " ";
        it2++;
    }
    std::cout << std::endl;

    b.merge(a);
    
    b.sort();

    std::cout << "list b is : ";
    for (int value : b) {
        std::cout << value << " ";
    }

    return 0;
}
