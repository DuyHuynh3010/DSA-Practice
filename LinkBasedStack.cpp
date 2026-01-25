#include <iostream>
using namespace std;

struct node {
    double data;
    node* next;
};

struct stack {
    node* top;
    int count = 0;

    stack() {
        top = nullptr;
        count = 0;
    }

    void push(double value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        count++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1; 
        }
        node* temp = top;
        double poppedValue = temp->data;
        top = top->next;
        delete temp;
        count--;
        return poppedValue;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    stack s;
    s.push(10.5);
    s.push(20.3);
    s.push(30.7);

     cout << "Pop: " << s.pop() << endl; 
    cout << "Pop: " << s.pop() << endl; 
    cout << "Pop: " << s.pop() << endl; 
    cout << "Pop: " << s.pop() << endl; 

    return 0;
}