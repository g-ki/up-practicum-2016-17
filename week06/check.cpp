#include<iostream>
using namespace std;

int main() {
  char a = 0;
  int j = 0;
  for (int i = a; i < '9'; i+=2) {
    j++;
    int j = 2;
    cout << "i: " << i << endl;
    j++;
  }
  cout << "j: " << j << endl;
  while ((j = a + j) || j++)
    j--;
  cout << "j*: "<< j << endl;
  return 0;
}
