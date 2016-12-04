#include <iostream>

using namespace std;

void bubbleSort(double arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = i; j < size; j++) {
      if (arr[i] > arr[j]) {
        double temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void selectionSort(double arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    double min = arr[i];
    int index = i;
    
    for (int j = i + 1; j < size; j++) {
      if (min > arr[j]) {
        min = arr[j];
        index = j;
      }
    }
    
    int temp = arr[i];
    arr[i] = arr[index];
    arr[index] = temp;
  }
}

int main() {
  double arr[100] = {10, 22, 3, 14, 55};
  selectionSort(arr, 5);

  for (int i = 0; i < 5; i++)
    cout << arr[i] << " ";
}
