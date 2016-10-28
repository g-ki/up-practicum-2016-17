#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int points = 0;

    for (int i = 0; i < 3; i++) {
        double x, y;
        cin >> x >> y;

        // Тук dist е целочислено число, за да се закръгли надолу
        int dist = sqrt(x * x + y * y);
        // Тернарен оператор, има значение на:
        // Ако dist <= 3, то запази в pointsForThrow стойността на (3 - dist) * 5,
        // иначе запази 0
        int pointsForThrow = dist <= 3 ? (3 - dist) * 5 : 0;

        points += pointsForThrow;
    }

    cout << "Total points: " << points << endl;

    return 0;
}

