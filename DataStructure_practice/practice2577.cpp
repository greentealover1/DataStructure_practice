#include <iostream>
using namespace std;
int main() {
	int cnt[10] = {};
	int a, b, c;
	cin >> a >> b >> c;
	int ans = a * b * c;
	while (ans != 0) {//ans�� 0�� �ɶ����� �ݺ�
		cnt[ans % 10]++;//�ڸ���=index
		ans /= 10;//�ڸ��� ���̱�(��...��....���� �ڸ�...�̷���)
	}
	for (int i : cnt) cout << i << "\n";
}