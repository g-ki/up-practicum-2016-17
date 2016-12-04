#include <iostream>

using namespace std;

double minElem(double arr[], int size) {
    if (size > 0) {
        double minElem = arr[0];

        for (int i = 0; i < size; i++)
            if (minElem > arr[i])
                minElem = arr[i];

        return minElem;
    }
}

int main() {
    double arr[] = {1, 2, 6, -2, 2};
    
    cout << minElem(arr, 5);
}
