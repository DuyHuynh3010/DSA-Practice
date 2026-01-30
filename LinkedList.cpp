#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void PrintList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr)
            cout << ", ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int value;

    while (true) {
        cout << "Enter a number (-1 to stop): ";
        cin >> value;

        if (value == -1)
            break;

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;

        head = newNode;

        PrintList(head);
    }

    return 0;
}