#include <iostream>
using namespace std;
int main() {
	int n;//���� �� ������ ���� 23:15
	cin >> n;
	int score[1000];
	int m = -1;//�ִ밪 ����
	double result=0,sum=0;
	for (int i = 0; i < n; i++) {
		cin >> score[i];
		if (score[i] > m) m = score[i];
		sum += score[i];
		result = (sum / m * 100) / n;
	}
	cout << result << endl;
}