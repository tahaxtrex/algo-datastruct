#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


int main(){
    
    std::vector<int> count(30, 0);

    for(int i = 0; i < 30; i++){
        count[i] = i + 1;
    }

    count.push_back(5);
    std::reverse(count.begin(), count.end());

    std::vector<int>::iterator it = count.begin();
    while(it != count.end()){
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;

    std::replace(count.begin(), count.end(), 5, 129);

    std::vector<int>::iterator it = count.begin();
    while(it != count.end()){
        std::cout << *it << " ";
        it++;
    }


    return 0;
}