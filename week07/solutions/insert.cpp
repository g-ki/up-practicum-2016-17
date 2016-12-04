#include <iostream>

using namespace std;

void insert(double arr[], int size, double newElem, int position) {
    int i = size;
    for (; i > position; i--)
        arr[i] = arr[i - 1];
  
    arr[i] = newElem;
}

int main() {
    double arr[100] = {1, 2, 3, 4, 5};
    insert(arr, 5, 10, 2);
  
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
}
