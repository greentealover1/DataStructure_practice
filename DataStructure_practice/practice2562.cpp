#include <iostream>
using namespace std;
int main() {
	int arr[9];
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	int max = -1;
	int max_idx;
	for (int i = 0; i < 9; i++) {
		if (arr[i] > max) {
			max = arr[i];
			max_idx = i;
		}
	}
	cout << max << endl;
	cout << max_idx+1 << endl;
}