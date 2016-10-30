#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	int digits = 0;

	// Еквивалентно на
	//
	// int temp = n;
	// while (temp > 0) {
	//   temp /= 10;
	//   ++digits;
	// }
	//
	// В случая трябва да си запазим оригиналното n, защото за да намерим броя на цирфите му,
	// трябва да го делим, докато не стане 0, но по този начин ние губим първоначалната стойност
	// на n.
	for (int temp = n; temp > 0; temp /= 10)
		++digits;

	// Тук трябва да е double, тъй като pow на някои компилатори вместо да върне,
	// че 5 ^ 3 е 125, връща нещо, което приближава 125 отдолу, но в целочислена
	// променлива ще се закръгли на 124.
	double total = 0;

	for (int temp = n; temp > 0; temp /= 10)
		total += pow(temp % 10, digits);
	
	cout << (total == n) << endl;
	
	return 0;
}