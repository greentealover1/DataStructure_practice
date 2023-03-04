#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	int num = 1;
	for (int i = 0; i < s.length(); i++) {//문자열의 단어 개수 세기
		if (s[i] == ' ') num++;
	}
	if (s[0] == ' ') num--;//문자열의 앞이 공백일때 
	if (s[s.length() - 1] == ' ') num--;//문자열의 뒤가 공백일때
	cout << num << endl;
}