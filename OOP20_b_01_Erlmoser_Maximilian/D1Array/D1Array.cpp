#include <string>
#include <array>
#include <iostream>
using namespace std;

void coutArray(array<double, 8> a) {
	for (int i = 0; i < 4; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 4; i++) {
		cout << a[i] << " ";
	}
}

int main() {
	array<double, 8> arr{ 0 };

	for (int i = 1; i < 8; i++) {
		arr[i] = arr[i - 1] + 0.3456789;
	}
	coutArray(arr);
}
