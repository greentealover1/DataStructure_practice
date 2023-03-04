#include <iostream>
using namespace std;
int main() {
	int n;//시험 본 과목의 개수 23:15
	cin >> n;
	int score[1000];
	int m = -1;//최대값 변수
	double result = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> score[i];
		if (score[i] > m) m = score[i];
		sum += score[i];
		result = (sum / m * 100) / n;
	}
	cout << result << endl;
}