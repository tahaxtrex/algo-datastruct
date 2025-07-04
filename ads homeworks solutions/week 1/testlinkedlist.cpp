#include "linkedlist.h"
#include <iostream>

int main(){

    linkedlist<int> l;
    l.addfront(10);
    l.addfront(20);
    l.addfront(30);
    l.addfront(40);
    l.addend(50);
    l.addend(60);
    l.firstvalue();
    l.lastvalue();
    l.getsize();
    l.listdisplay();
    l.removelast();
    l.removelast();
    l.listdisplay();
    l.removelast();
    l.removefirst();
    l.listdisplay();


    return 0;
}