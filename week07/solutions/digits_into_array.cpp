#include <iostream>

using namespace std;

void digitsIntoArray(int digits[], int n) {
    int size = 0;
    
    while (n > 0) {
        digits[size++] = n % 10;
        n /= 10;
    }
    
    for (int i = 0; i < (size) / 2; i++) {
        int temp = digits[i];
        digits[i] = digits[size - i - 1];
        digits[size - i - 1] = temp;
    }
}

int main() {
    int n = 255109;
    int digits[11];
    
    digitsIntoArray(digits, n);
    
    for (int i = 0; i < 6; i++)
        cout << digits[i] << " ";
}
