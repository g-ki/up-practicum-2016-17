#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;

    do {
        cin >> n;
    } while (n < 1);

    // С един цикъл, i ни представлява номера на поредния ред
    for (int i = 0; i < n; i++)
    {
        // Запазваме си броя на звездичките на всеки ред
        int stars = (i >= n/2) ? n - (n - i - 1) * 2 : n - i * 2;

        // Отпечатваме интервал
        for (int j = 0; j < (n - stars)/2; j++)
            cout << " ";

        // Отпечатваме звездички
        for (int j = 0; j < stars; j++)
            cout << "*";

        cout << endl;
    }

    //return 0;

    cout << endl;

    // Цикъл за отпечатване на горната част от часовника
    // При четно n отпечатва и "горната" среда,
    // при нечетно средата се отпечатва от долния цикъл
    for (int i = 0; i < n / 2; i++)
    {
        int stars = n - i * 2;

        for (int j = 0; j < (n - stars)/2; j++)
            cout << " ";

        for (int j = 0; j < stars; j++)
            cout << "*";

        cout << endl;
    }

    // Цикъл за отпечатване на долната част от часовника
    for (int i = ceil(n / 2.0) - 1; i >= 0; i--)
    {
        int stars = n - i * 2;

        for (int j = 0; j < (n - stars)/2; j++)
            cout << " ";

        for (int j = 0; j < stars; j++)
            cout << "*";

        cout << endl;
    }
}
