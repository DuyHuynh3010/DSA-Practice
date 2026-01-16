#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the dynamic array: ";
    cin >> size;

    int* arr = new int[size];
    int count = 0;
    int number;
    while(count < size) {
        cout << "Enter number " << (count + 1) << ": ";
        cin >> number;
        arr[count] = number;
        count++;
        if(number == -1) {
            break;
        }
    }
    cout << "All the numbers in the array are: ";
    for(int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}