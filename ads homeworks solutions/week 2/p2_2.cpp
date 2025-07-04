#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <deque>

int main() {
    
    std::deque<float> A;
    
    while(true){
        float n;
        std::cin>>n;
        if(n == 0){
            break;
        }
        else if(n>0){
            A.push_back(n);
        }
        else{
            A.push_front(n);
        }
    }
        
        for(float val : A){
            std::cout<<val<<" ";
        }
        
        std::deque<float>::iterator it = A.begin();
        while(it != A.end()){
            if(*it<0){
                it++;
            }
            else{
                A.insert(it, 0);
                break;
            }
        }
    std::cout<<std::endl;
    
    auto its = A.begin();
    while(its != A.end()){
        if(its != A.begin()){
            std::cout<<";";
        }
        std::cout<<*its;
        its++;
    }
    
    
    return 0;
}