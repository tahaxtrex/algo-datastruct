#include "stack.h"
#include <iostream>

int main() {

    mystack<int> s(10);

    if(s.isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << "Stack is not empty" << std::endl;
    }      // check if stack is empty

    s.push(10);
    s.pop();
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.peek();
    std::cout<<s.getnumentries()<<std::endl;

    //check all the methods of the stack class

    mystack<int> copy(s);

    copy.push(60);
    copy.push(70);
    std::cout<<copy.getnumentries()<<std::endl;

    if(copy.isEmpty()) {
        std::cout << "Stack copy is empty" << std::endl;
    } else {
        std::cout << "Stack copy is not empty" << std::endl;
    }


    return 0;
}