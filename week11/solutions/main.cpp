#include <iostream>
#include <cmath>
using namespace std;

int countDigits(int x) {
	if (abs(x) < 10)
		return 1;
	return 1 + countDigits(x / 10);
}

// Можеше и просто веднъж да си сметнем модула на x в началото,
// но да допуснем, че това не ни е позволено ( ͡° ͜ʖ ͡°)
int sumDigits(int x) {
	if (abs(x) < 10)
		return abs(x);
	return abs(x % 10) + sumDigits(x / 10);
}

int countK(int n, int k) {
	if (n == k)
		return 1;
	if (n < 10 && n != k)
		return 0;
	if (n % 10 == k)
		return 1 + countK(n / 10, k);
	return countK(n / 10, k);
}

int gcd(int x, int y) {
	if (x == y)
		return x;
	if (x > y)
		return gcd(x - y, y);
	return gcd(y - x, x);
}

int compare(const char* first, const char* second) {
	if (*first == '\0' && *second == '\0')
		return 0;
	// Това включва и случая първият елемент на first да е '\0'
	if (*first < *second)
		return -1;
	if (*first > *second)
		return 1;
	return compare(first + 1, second + 1);
}

bool increasing(int* arr, int n) {
	if (n <= 1)
		return true;
	if (arr[0] <= arr[1])
		return increasing(arr + 1, n - 1);
	return false;
}

bool contains(int* arr, int n, int x) {
	if (n == 0)
		return false;
	if (arr[0] == x)
		return true;
	return contains(arr + 1, n - 1, x);
}

// Това ни е същинската функция, но би било по-хубаво, ако не
// спестим на потребителя всеки път да въвежда освен големината
// на масива n и 0 и n-1.
bool binarySearchHelper(int* arr, int x, int left, int right) {
	if (left > right)
		return false;

	int mid = (left + right) / 2;

	if (arr[mid] == x)
		return true;
	if (arr[mid] < x)
		return binarySearchHelper(arr, x, mid + 1, right);
	return binarySearchHelper(arr, x, left, mid - 1);
}

bool binarySearch(int* arr, int n, int x) {
	return binarySearchHelper(arr, x, 0, n - 1);
}

int main() {
	cout << countDigits(-552) << endl;
	cout << sumDigits(-552) << endl;
	cout << countK(1012751, 1) << endl;
	cout << gcd(25, 11) << endl << endl;

	cout << compare("abcd", "abx") << endl;
	cout << compare("abyd", "abx") << endl;
	cout << compare("abx", "abx") << endl;
	cout << compare("abx", "abxabc") << endl << endl;
	
	int a[] = {1, 4, 5};
	cout << increasing(a, 3) << endl;
	int b[] = {4, 5, 2};
	cout << increasing(b, 3) << endl << endl;
	
	cout << contains(a, 3, 10) << endl;
	cout << contains(a, 3, 4) << endl << endl;
	
	cout << binarySearch(a, 3, 1) << endl;
	cout << binarySearch(a, 3, 4) << endl;
	cout << binarySearch(a, 3, 5) << endl;
	cout << binarySearch(a, 3, 17) << endl;
}

