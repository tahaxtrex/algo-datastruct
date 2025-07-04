#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>

int main(){

    std::ifstream thisfile("data.txt");
    
    if (!thisfile || thisfile.fail()) {
        std::cerr << "This file does not exist" << std::endl;
        return 1;
    }

    std::map<std::string, std::string> names;
    std::string firstname, lastname, date, fullname;

    while(thisfile >> firstname >> lastname >> date){
        fullname = firstname + " " + lastname;
        names[fullname] = date;
    }

    std::map<std::string, std::string>::iterator it = names.begin();

    std::string input;
    std::cout << "Enter a name: ";
    std::getline(std::cin, input);

    while(it != names.end()){
        if(it->first == input){
            std::cout << it->second << std::endl;
            break;
        }
        it++;
        if (it == names.end()) {
            std::cout << "Name not found" << std::endl;
        }
    }

    thisfile.close();

    return 0;
}