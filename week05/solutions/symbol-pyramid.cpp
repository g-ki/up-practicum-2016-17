#include <iostream>
using namespace std;

int main() {
    char s;

    do {
        cin >> s;
    } while(s < 'A' || s > 'Z');

    for (char i = 'A'; i <= s; i++) {
        for (char j = 'A'; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }
}
