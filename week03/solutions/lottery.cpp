#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));

    int first = rand() % 49 + 1;
    int second = rand() % 49 + 1;
    int third = rand() % 49 + 1;

    // Сортиране на трите числа с цел по-лесно сравнение с потребителския вход
    // За целта винаги ще си пазим най-голямото текущо проветено число в third
    if (third < first) {
        int temp = first;
        first = third;
        third = temp;
    }
    if (third < second) {
        int temp = second;
        second = third;
        third = temp;
    }

    // В момента сме сигурни, че в third се намира най-голямото число от трите,
    // сега остава да сравним first и second
    if (second < first) {
        int temp = second;
        second = first;
        first = temp;
    }

    int x, y, z;
    cin >> x >> y >> z;

    // Повтаряме процедурата за x, y и z.
    if (z < x) {
        int temp = x;
        x = z;
        z = temp;
    }

    if (z < y) {
        int temp = y;
        y = z;
        z = temp;
    }

    if (y < x) {
        int temp = y;
        y = x;
        x = temp;
    }

    cout << (x == first) && (y == second) && (z == third);

    return 0;
}

