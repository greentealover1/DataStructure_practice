#include <iostream>
using namespace std;
int main() {
	int cnt[10] = {};
	int a, b, c;
	cin >> a >> b >> c;
	int ans = a * b * c;
	while (ans != 0) {//ans가 0이 될때까지 반복
		cnt[ans % 10]++;//자리수=index
		ans /= 10;//자리수 줄이기(백...십....일의 자리...이런식)
	}
	for (int i : cnt) cout << i << "\n";
}