#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	int num = 1;
	for (int i = 0; i < s.length(); i++) {//���ڿ��� �ܾ� ���� ����
		if (s[i] == ' ') num++;
	}
	if (s[0] == ' ') num--;//���ڿ��� ���� �����϶� 
	if (s[s.length() - 1] == ' ') num--;//���ڿ��� �ڰ� �����϶�
	cout << num << endl;
}