#include <iostream>
using namespace std;

int main() {
    int n;

    // Валидация на входа с do-while
    do {
        cin >> n;
    } while(n < 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }
}
