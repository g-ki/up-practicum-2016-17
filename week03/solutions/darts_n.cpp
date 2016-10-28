#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int points = 0;

    int n;
    cin >> n;

    for (int i = 0; i < 3; i++) {
        double x, y;
        cin >> x >> y;

        int dist = sqrt(x * x + y * y);
        int pointsForThrow = dist <= n ? (n - dist) * 5 : 0;

        points += pointsForThrow;
    }

    cout << "Total points: " << points << endl;

    return 0;
}
