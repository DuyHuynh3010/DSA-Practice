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

void InsertSorted(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr || value < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

int main() {
    Node* head = nullptr;
    int value;

    while (true) {
        cout << "Enter a number (-1 to stop): ";
        cin >> value;

        if (value == -1)
            break;

        InsertSorted(head, value);
        PrintList(head);
    }

    return 0;
}
