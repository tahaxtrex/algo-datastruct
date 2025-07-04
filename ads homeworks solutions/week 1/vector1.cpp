#include <iostream>
#include <vector>
#include <string>

int main(){
    
    std::vector<std::string>phrase;
    std::string input;
    std::cout<<"print words and end it with the word \"END\""<<std::endl;
    int i = 0;
    while(input != "END"){
        std::cin>>input;
        phrase.push_back(input);
        i++;
    }
    phrase.pop_back();
    i--;
    for(int index = 0; index<i; index++){
        std::cout<<phrase[index]<<" ";
    }
    
    std::cout<<std::endl;
    
    for(std::vector<std::string>::iterator it = phrase.begin(); it != phrase.end(); it++){
        if(it != phrase.begin()){
            std::cout<<',';
        }
        std::cout<<*it;
    }
    
    return 0;
}