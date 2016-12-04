#include <iostream>

using namespace std;

// Вече като знаем пседвоними, можем да подадем size по референция и след това да го намалим с едно.
void remove(double arr[], int size, int position) {
  for (int i = position; i < size - 1; i++)
    arr[i] = arr[i + 1];
}

int main() {
  double arr[100] = {1, 2, 3, 4, 5};
  remove(arr, 5, 2);

  for (int i = 0; i < 4; i++)
    cout << arr[i] << " ";
}
