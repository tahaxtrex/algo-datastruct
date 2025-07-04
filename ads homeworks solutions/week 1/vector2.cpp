#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> phrase;  // Vector to store strings
    std::string input;

    std::cout << "Enter lines of text (Type \"END\" to stop):" << std::endl;

    while (true) {
        std::getline(std::cin, input);
        if (input == "END") break;
        phrase.push_back(input); 
    }
    
    if (phrase.size()>4){
        std::string temp;
        temp = phrase.at(1);
        phrase.at(1)= phrase.at(4);
        phrase.at(4) = temp;
    }
    else{
        std::cout<<"the vector does not contain a 5th element"<<std::endl;
    }
    
    if (!phrase.empty()) {
        phrase.back() = "???";
    }

    
    for (size_t i = 0; i < phrase.size(); i++) {
        if (i > 0) std::cout << ",";
        std::cout << phrase[i];
    }
    
    std::cout<<std::endl;
    
    for(std::vector<std::string>::iterator it = phrase.begin(); it != phrase.end(); it++){
        if(it != phrase.begin()){
            std::cout<<';';
        }
        std::cout<<*it;
    }
    
    std::cout<<std::endl;
    
    for (auto it = phrase.rbegin(); it != phrase.rend(); ++it) {
        if (it != phrase.rbegin()) {
            std::cout << ' ';
        }
        std::cout << *it;
    }


    return 0;
}
