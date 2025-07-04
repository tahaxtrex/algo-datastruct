#ifndef LINKEDLIST_H
#define LINKEDLIST_H 

#include <iostream>

template <typename T>
  
class node{  //create a basic doubly linked 
            //node class with 2 constructors
    
    private:
    
    node* prev;
    T data;
    node* next;
      
    public;
    
    node(){
        prev = NULL;
        data = T();
        next = NULL;
    }
    
    node(T value){
        prev = nullptr;
        data = value;
        next = nullptr;
    }
    
};

template <typename T>
class linkedlist{  //create a linked list class with 
                    //all the basic functions
    private:
    
    node<T>* head;
    node<T>* tail;
    int size;
    
    public:
    
    linkedlist(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    void addfront(T value){ //add a node to the front of the linked list
        node<T> newnode = new node<T>(value);
        if(head == nullptr){
            head = tail = newnode;
        }
        else{
            newnode->next = head;
            head-> prev = newnode;
            head = newnode;
        }
        size++;
    }
    
    void addend(T value){ //add a node to the end of the linked list
        node<T> newnode = new nodet<T>(value);
        if(tail == nullptr){
            head = tail = newnode;
        }
        else{
            newnode->prev = tail;
            tail -> next = newnode;
            tail = newnode;
        }
        size++;
    }
    
    T firstvalue(){ //return the first value of the linked list
        if(size == 0){
            throw std::runtime_error("This linked list is empty");
        }
        else{
            return head -> data;
        }
    }
    
    T lastvalue(){ //return the last value of the linked list
        if(size == 0){
            throw std::runtime_error("This linked list is empty");
        }
        else{
            return tail -> data;
        }
    }
    
    int getsize(){ //return the size of the linked list
        return size;
    }
    
    T removefirst() { //remove the first node of the linked list
    if (size == 0) {
        throw std::runtime_error("This linked list is empty");
    }

    Node<T>* temp = head; 
    T value = temp->data; 

    head = head->next;  

    if (head) {
        head->prev = nullptr;  
    } 
    else {
        tail = nullptr;  
    }

    delete temp;
    size--;
    return value;
    }

    
    T removelast() { //remove the last node of the linked list
    if (size == 0) {
        throw std::runtime_error("This linked list is empty");
    }

    Node<T>* temp = tail; 
    T value = temp->data; 

    tail = tail->prev;  

    if (tail) { // if the list is not empty
        tail->next = nullptr;  
    } else {
        head = nullptr;  
    }

    delete temp;
    size--;
    return value;
    }
    
    T listdisplay(){
        node<T>* current = head;
        while(current){
            std::cout<< current->data<<" ";
            current = current->next;
        }
    }
    
    ~linkedlist(){ //destructor to delete all the nodes
        node<T>* current = head;
        while(current){
            node<T>* temp = current->next;
            delete current;
            current = temp;
        }
    }
};

#endif