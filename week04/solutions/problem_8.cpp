#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	double toBinary = 0;
	int binaryDigits = 0;

	// Как се пресмята двоичният запис на едно десетично число:
	// Нека го сметнем за 11. Делим числото на 2, взимаме остатъка му и това
	// ще представлява последната цифра от двоичния му запис. След това взимаме
	// частното от делението и него делим на 2 и т.н.
	// Продължаваме, докато не достигнем частно 0
	//
	// 11 / 2 = 5 (1)
	//  5 / 2 = 2 (1)
	//  2 / 2 = 1 (0)
	//  1 / 2 = 0 (1)
	//
	// Сега взимаме остатъците в обратен ред, т.е. 11 се представя като 1011.
	// При итерациите на цикъла toBinary ще има стойности последователно
	// 1, 11, 11 (добавяме 0 * 100), 1011.
	for (int temp = n; temp > 0; temp /= 2) {
		toBinary += (pow(10, binaryDigits) * (temp % 2));
		binaryDigits++;
	}
	
	cout << toBinary << endl;
	
	double toOcta = 0;
	int octaDigits = 0;
	
	// За осмичното представяне е същото, само че делим и гледаме остатъците при деление на 8.
	for (int temp = n; temp > 0; temp /= 8) {
		toOcta += (pow(10, octaDigits) * (temp % 8));
		octaDigits++;
	}
	
	cout << toOcta << endl;
	
	return 0;
}