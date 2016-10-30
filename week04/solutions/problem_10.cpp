#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	while (n != 1) {
		if (n % 2 == 0)
			n /= 2;
		else
			n = 3 * n + 1;
		
		// И в свата случая ще искаме да отпечатваме n,
		// така че можем да го изнесем след if-овете.
		cout << n << endl;
	}
	
	return 0;
}