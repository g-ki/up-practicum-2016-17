#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y;
    cin >> x >> y;

    bool inBiggerCircle = sqrt(x * x + y * y) <= 4;
    bool inSmallerCircle = sqrt((x - 3) * (x - 3) + (y - 3) * (y - 3)) <= 1;

    cout << inBiggerCircle && !inSmallerCircle;
}
