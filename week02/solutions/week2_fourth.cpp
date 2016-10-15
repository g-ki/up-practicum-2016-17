#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int days;
    cout << "Enter days to be converted to a date." << endl;
    cin >> days;

    if (days < 1 || days > 365)
        cout << "Error: Expected a number between 1 and 365." << endl;

    // Ако се намираме в януари или февруари
    else if (days <= 31 + 28)
        cout << "M: " << days / 32 + 1 << ", D: " << days % 32 + (days > 31) << endl;

    // Ако се намираме между март и юли включително.
    // Един вариант е, тъй като знаем, че се редуват месеци с 31 и 30 дни,
    // да използваме деление на 31 + 30 = 61 и след това на 31.
    else if (days <= 31 * 4 + 30 * 2 + 28) {
        int months = 3 + (2 * ((days - 60) / 61)) + ((days - 60) % 61) / 31;
        cout << "M: " << months << ", D: " << (((days - 60) % 61) % 31) + 1 << endl;
    }

    // Ако се намираме между август и декември.
    // На пръв поглед излгежда, че можем да слеем този if с горния, но в случая
    // юли и август са съседни месеци с по 31 дни и ние "рестартираме" броенето.
    else {
        int months = 8 + (2 * ((days - 213) / 61)) + ((days - 213) % 61) / 31;
        cout << "M: " << months << ", D: " << (((days - 213) % 61) % 31) + 1 << endl;
    }

    int d, m, y;
    cout << "Enter a date in the format D/M/Y" << endl;
    cin >> d >> m >> y;

    // За да бъде една година високосна, тя трябва или да се дели на 400,
    // или да се дели на 4, но не и на 100.
    bool isLeapYear = (y % 400 == 0) ||
                      (y % 4 == 0 && y % 100 != 0);
    if (d < 1 || d > 31 || m < 1 || m > 12)
        cout << "The date is invalid" << endl;
    else {
        bool isValidDate = true;

        switch(m) {
            case 4: case 6: case 9: case 11:
                if (d > 30)
                    isValidDate = false;
                break;
            case 2:
                if (d > (28 + isLeapYear))
                    isValidDate = false;
                break;
        }

        if (isValidDate)
            cout << "The date is valid." << endl;
        else
            cout << "The date is invalid." << endl;

        // Увеличаване на датата с 6 месеца
        // Увеличаване на месеца с 6
        m = (m + 5) % 12 + 1;

        // Увеличаване на годината при нужда
        if (m <= 6) {
            ++y;

            // Малко повторение на код, понеже още не знаем някои похвати :)
            isLeapYear = (y % 400 == 0) ||
                         (y % 4 == 0 && y % 100 != 0);
        }

        switch(m) {
            case 4: case 6: case 9: case 11:
                // Единствената възможност е d да е 31, тъй като ние знаем, че
                // старата дата е била валидна. В такъв случай "прехвърляме" един ден
                // в следващия месец.
                if (d > 30) {
                    ++m;
                    d = 1;
                }
                break;
            case 2:
                // Тук вече можем да надхвърляме месеца с един до три дни.
                if (d > (28 + isLeapYear)) {
                    ++m;
                    d = d - 28 - isLeapYear;
                }
                break;
        }
        cout << "The date in 6 months will be " << d << "/" << m << "/" << y << endl;
    }
}
