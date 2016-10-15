#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // За улеснение приемаме, че годината не е високосна.
    int month, day;
    cin >> day >> month;

    int daysTilNextMonth = 0;
    int daysInUpcomingMonths = 0;

    if (day > 0 && month > 0 && month < 13) {
        switch(month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                cout << "It has 31 days." << endl;
                daysTilNextMonth = 31 - day;
                break;
            case 4: case 6: case 9: case 11:
                cout << "It has 30 days." << endl;
                daysTilNextMonth = 30 - day;
                break;
            case 2:
                cout << "It has 28 days." << endl;
                daysTilNextMonth = 28 - day;
                break;
        }

        if (daysTilNextMonth >= 0) {
            if (month == 1)
                daysInUpcomingMonths = 334;
            else if (month <= 6)
                daysInUpcomingMonths = floor((12 - month) * 30.5) + 1;
            else
                daysInUpcomingMonths = ceil((12 - month) * 30.5);

            cout << "Days remaining: " << daysTilNextMonth + daysInUpcomingMonths;
        }
    }
}
