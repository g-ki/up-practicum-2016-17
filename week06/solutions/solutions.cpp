#include <iostream>

using namespace std;

// За целите на упражнението се забранява използването на cmath
double abs(double);
double pow(double, int);

double min(double, double);
double max(double, double);
double min3(double, double, double);
double max3(double, double, double);

int isLetter(char);
bool isDigit(char);

int gcd(int, int);
int lcm(int, int);

bool isPrime(int);
bool twinPrimes(int, int);
bool sexyPrimes(int, int);
bool weirdPrimes(int, int, int);

int main()
{
    cout << abs(3) << " " << abs(-3) << endl;
    cout << pow(5, 2) << " " << pow(5, -2) << " " << pow(5, 0) << endl;

    cout << min(3, 5) << " " << max(3, 5) << endl;
    cout << min3(1, 22, 5) << " " << max3(1, 22, 5) << endl;

    cout << isLetter('a') << " " << isLetter('0') << " " << isLetter('A') << endl;
    cout << isDigit('5') << " " << isDigit('a') << endl;

    cout << gcd(40, 12) << " " << lcm(40, 12) << endl;

    cout << twinPrimes(5, 7) << " " << twinPrimes(17, 23) << endl;
    cout << sexyPrimes(5, 11) << " " << sexyPrimes(5, 7) << endl;

    return 0;
}


double abs(double number) {
    return number >= 0 ? number : -number;
}

double pow(double base, int exp) {
    double result = 1;
    // Тук изнасям смятането на абсолютната стойност на exp,
    // за да не се изчислява при всяка итерация на цикъла.
    int expAbs = abs(exp);

    // Тъй като искаме функцията да работи и за отрицателни степени,
    // можем първо да сметнем base на степен модул от exp и след това
    // да проверим знака на еxp и да върнем или result, или реципрочното.
    for (int i = 0; i < expAbs; i++)
        result *= base;

    return exp >= 0 ? result : 1 / result;
}

double min(double first, double second) {
    return first <= second ? first : second;
}

double max(double first, double second) {
    return first >= second ? first : second;
}

// Бонус: Минимум и максимум на три числа, използвайки съответните функции за две числа.
double min3(double first, double second, double third) {
    return min(first, min(second, third));
}

double max3(double first, double second, double third) {
    return max(first, max(second, third));
}

// Малко усложняване на условието - връщаме -1 за малка буква, 1 за главна, 0 за друг символ.
int isLetter(char symbol) {
    if (symbol >= 'a' && symbol <= 'z')
        return -1;
    if (symbol >= 'A' && symbol <= 'Z')
        return 1;
    return 0;
}

bool isDigit(char symbol) {
    return symbol >= '0' && symbol <= '9';
}

// Пример за работа на алгоритъма:
// first second
// ************
// 40    12
// 28    12
// 16    12
// 4     12
// 4     8
// 4     4
int gcd(int first, int second) {
    while (first != second) {
        if (first >= second)
            first -= second;
        else
            second -= first;
    }

    return first;
}

bool isPrime(int number) {
    // Не можем да ползваме cmath, иначе по-ефективно би било
    // да се цикли до корен от number
    for (int i = 2; i <= number / 2; i++)
        if (number % i == 0)
            return false;

    // В случая на едно само горния цикъл няма да е достатъчен
    return number != 1;
}

bool twinPrimes(int first, int second) {
    return abs(first - second) == 2 && isPrime(first) && isPrime(second);
}

// Малко отклонение
bool sexyPrimes(int first, int second) {
    return abs(first - second) == 6 && isPrime(first) && isPrime(second);
}

// Можем да напишем функция, с помощта на която да се реализират горните 2:
bool weirdPrimes(int first, int second, int n) {
    return abs(first - second) == n && isPrime(first) && isPrime(second);
}
// и след това да кажем:
// bool twinPrimes(int first, int second) {
//     return weirdPrimes(first, second, 2);
// }
//
// bool sexyPrimes(int first, int second) {
//     return weirdPrimes(first, second, 6);
// }

bool triangleInequality(double a, double b, double c) {
    return a < b + c;
}

bool isTriangle(double a, double b, double c) {
    return triangleInequality(a, b, c) &&
           triangleInequality(b, a, c) &&
           triangleInequality(c, a, b);
}

// Тук използваме свойството, че произведението на две естествени числа
// е равно на произведението на НОД-а и НОК-а им.
int lcm(int first, int second) {
    return first * second / gcd(first, second);
}
