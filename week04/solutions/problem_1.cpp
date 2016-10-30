#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	bool flag = true;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			flag = false;
			// Открили сме един делител, следователно вече знаем, че числото не е просто.
			break;
		}
	}
	
	// Горният цикъл няма да работи единицата, това е един вариант за хващането ѝ
	if (n == 1)
		cout << false << endl;
	else
		cout << flag << endl;
	
	return 0;
}