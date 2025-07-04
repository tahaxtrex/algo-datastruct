#include <iostream>

using namespace std;

template <typename T>
class mystack {
private:
    T* arr;
    int top;
    int n;

public:
    // Default Constructor
    mystack() {
        top = -1;
        n = 10;
        arr = new T[n];
    }

    // Parameterized Constructor
    mystack(int a) {
        top = -1;
        n = a;
        arr = new T[n];
    }

    // Copy Constructor
    mystack(const mystack &s) {
        top = s.top;
        n = s.n;
        arr = new T[n];
        for (int i = 0; i <= top; i++) {
            arr[i] = s.arr[i];
        }
    }

    // Push function
    bool push(T x) {
        if (top == n - 1) {
            cout << "Stack Overflow" << endl;
            return false;
        }
        arr[++top] = x;
        return true;
    }

    // Pop function
    T pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return T();  // Return default object of T
        }
        return arr[top--];
    }

    // Peek function
    T peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return T();
        }
        return arr[top];
    }

    // Get number of entries in the stack
    int getnumentries() {
        return top + 1;
    }

    // Check if stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Destructor
    ~mystack() {
        delete[] arr;
    }
};

// Complex number class
class complex {
public:
    int real, imag;

    complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    bool operator==(const complex &c) {
        return (real == c.real && imag == c.imag);
    }
};