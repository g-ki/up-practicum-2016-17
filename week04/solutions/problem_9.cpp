#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int first = 0;
	int second = 1;
	
	cout << first << endl << second << endl;
	
	// Отсега нататък можем да си пазим текущото число на Фибоначи във first,
	// а следващото във second. За целта си запазваме старата стойност в copyFirst,
	// "следващото" число става текущото ново, т.е. можем да си представяме, че му е дошъл редът,
	// и във second пресмятаме следващото.
	for (int i = 2; i < 20; i++) {
		int copyFirst = first;
		first = second;
		second = copyFirst + second;

		cout << first << endl;
	}
	
	return 0;
}