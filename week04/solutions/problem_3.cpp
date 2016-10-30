#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	int copy = n;
	int reversed = 0;
	
	// Да разгледаме работата на цикъла за числото 1234
	// Преди първа итерация: copy -> 1234, reversed -> 0
	// След първа итерация: copy -> 123, reversed -> 4
	// След втора итерация: copy -> 12, reversed -> 40 + 3 = 43
	// След трета итерация: copy -> 1, reversed -> 430 + 2 = 432
	// След четвърта итерация: copy -> 0 reversed -> 4320 + 1 = 4321
	while (copy > 0) {
		reversed = reversed * 10 + copy % 10;
		copy /= 10;
	}
	
	cout << (n == reversed) << endl;
	
	return 0;
}