#include <iostream>
#include <set>  
#include <ctime>
#include <cstdlib>

int main(){ 
    std::set<int> s;  
    srand(time(0));   

    while(s.size() < 6){
        s.insert(rand() % 49 + 1);
    }

    for (int num : s) {
        std::cout << num << " ";
    }
    return 0;
}
