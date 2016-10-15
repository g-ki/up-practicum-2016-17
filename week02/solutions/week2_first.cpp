#include <iostream>
using namespace std;

int main() {
    char symbol;
    cin >> symbol;

    //Без кавички ще проверим дали символът има ASCII код между 0 и 9
    if (symbol >= '0' && symbol <= '9') {
        cout << symbol << " is a digit." << endl;
        int toNumber = symbol - '0';
        cout << symbol << " ^ 2 = " << toNumber * toNumber;
    }

    if (symbol >= 'a' && symbol <= 'z') {
        cout << symbol << " is a lowercase letter." << endl;
        char upperCase = symbol - 'a' + 'A';
        cout << "Its corresponding uppercase letter is " << upperCase;
    }

    if (symbol >= 'A' && symbol <= 'Z') {
        cout << symbol << " is an uppercase letter." << endl;
        char lowerCase = symbol - 'A' + 'a';
        cout << "Its corresponding lowercase letter is " << lowerCase;
    }

    return 0;
}
