#include <iostream>
#include <string>
using namespace std;
int main() {
	int cnt=0, total = 0;
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'o') {
				cnt++;
				total += cnt;
			}
			else {
				cnt = 0;
			}
		}
		cout << total << endl;
		total = 0;
		cnt = 0;
	}
}