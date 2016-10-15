#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Уравнението има вида ax + b = 0
    // В C++ можете да слагате едноредови коментари с // в началото на реда
    // За многоредови коментари използвайте /* код */
    /*
    double a, b;
    cin >> a >> b;

    if (a == 0) {
        //За едноредови if-ове можете да пропускате скобите
        if (b == 0)
            cout << "True for all x." << endl;
        else
            cout << "No solution.";
    }
    else
        cout << "x = " << -b / a << endl;
    */

    // Сега да решим квадратно уравнение ax^2 + bx + c = 0
    double a, b, c;
    cin >> a >> b >> c;

    if (a == 0)
        cout << "Error: Not a quadratic equation.";
    else {
        double d = b * b - 4 * a * c;

        if (d < 0)
            cout << "No real solutions.";
        if (d == 0)
            cout << "x = " << (-b + sqrt(d)) / (2 * a);
        if (d > 0)
            cout << "x1 = " << (-b - sqrt(d)) / (2 * a) <<
                  ", x2 = " << (-b + sqrt(d)) / (2 * a);
    }
}
