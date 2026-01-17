#include <iostream>
using namespace std;

class ArrayBasedQueue {
    private:
        static const int MAX_SIZE = 10;
        int arr[MAX_SIZE];
        int front;
        int back;
        int count;
    public:
        ArrayBasedQueue() : front(0), back(0), count(0) {}

        void enqueue(int value) {
            if (count == MAX_SIZE) {
                cout << "Queue is full!" << endl;
                return;
            }
            arr[back] = value;
            back = (back + 1) % MAX_SIZE;
            count++;
        }

        bool isEmpty() const {
            return count == 0;
        }

        int dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
                return -1; 
            }
            int value = arr[front];
            front = (front + 1) % MAX_SIZE;
            count--;
            return value;
        }

        void printQueue() const {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
                return;
            }
            cout << "Queue contents: ";
            for (int i = 0; i < count; i++) {
                cout << arr[(front + i) % MAX_SIZE] << " ";
            }
            cout << endl;
        }
};