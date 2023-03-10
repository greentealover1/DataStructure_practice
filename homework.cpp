#include <iostream>
#define MAX_DEGREE 80 //다항식의 처리 가능한 최대 차수+1
using namespace std;

class Polynomial { //프로그래밍 프로젝트2.1
private:
	int degree;//다항식의 최고 차수
	float coef[MAX_DEGREE];//각 항에 대한 차수의 계수들(5x^5+4x*5이면 [5,4...]이런식
public:
	Polynomial() { degree = 0; }//생성자
	void read() { //차수, 계수 읽기
		cout << "다항식의 최고 차수를 입력하세요:";
		cin >> degree;
		cout << "각 항의 계수를 입력하세요(총 " << degree + 1 << "개):";
		for (int i = 0; i <= degree; i++)
			cin >> coef[i];//계수 배열의 각 계수들 입력
	}

	void display(const char* str = " Poly = ") { //다항식의 내용 출력
		cout << "\t" << str;
		for (int i = 0; i < degree; i++) {
			if (coef[i]) {
				cout << coef[i] << "x^(" << degree - i << ")";
			}
			if (coef[i + 1])
				cout << "+";
		}
		if (coef[degree])
			cout << coef[degree];
		cout << endl;
	}

	void add(Polynomial a, Polynomial b) { //c=a+b(덧셈 함수)
		if (a.degree > b.degree) { //a>b항
			*this = a;//a다항식을 자기 객체에 복사(c=a+b일때 c=a;연산하는 부분임)
			for (int i = 0; i < b.degree; i++)
				coef[i + (degree - b.degree)] += b.coef[i];//다항식 계수를 순서대로 자신의 계수배열에 맞는 차수끼리 더함
		}
		else { //b>a항
			*this = b;
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] += a.coef[i];
		}
		trim();
	}
	void sub(Polynomial a, Polynomial b) {//c=a-b(뺄셈)
		if (a.degree > b.degree) {
			*this = a;
			for (int i = 0; i < b.degree; i++) {
				coef[i + (degree - b.degree)] -= b.coef[i];
			}
		}
		else { //b항이 a항보다 차수가 큰 경우
			b.negate();//부호 반대로
			*this = b;//b다항식을 자기 객체에 복사
			for (int i = 0; i <= a.degree; i++) {//,i=0이면,coef[0+(최고차수-a객체 최고차수]+=a.coef[i]
				coef[i + (degree - a.degree)] += a.coef[i];
			}
		}
		trim();
	}

	void mult(Polynomial a, Polynomial b) {//c=a*b(곱셈)
		*this = a;
		int temp = degree;//temp에 원래 차수 저장
		degree += b.degree;//a와 b객체의 차수 더하기(2제곱 *3제곱=5제곱이니까)
		int arr[MAX_DEGREE];//임의의 차수 정보 보관할 배열 선언
		for (int i = 0; i <= degree; i++)
			arr[i] = 0;//배열의 모든 차수들의 항을 초기화

		if (temp < b.degree) { //기존 다항식의 최고차수<b객체의 차수
			for (int i = 0; i <= temp; i++) {
				coef[i + b.degree] = coef[i];
				coef[i] = 0;
			}
		}
		else if (temp == b.degree) { //기존 다항식의 최고차수=b객체의 차수
			for (int i = 0; i <= temp; i++) {
				coef[i + temp] = coef[i];
				if (i != temp)
					coef[i] = 0;
			}
		}
		else { //기존 다항식의 최고차수>b객체의 차수
			for (int i = 0; i <= temp; i++)
				arr[i] = coef[i];
			for (int i = 0; i <= temp; i++) {
				coef[i + b.degree] = arr[i];
				if (i < b.degree)
					coef[i] = 0;
			}
			for (int i = 0; i <= degree; i++) {
				arr[i] = 0;
			}
		}
		for (int i = 0; i <= temp; i++) { //arr임의 배열에 정보 담기
			for (int j = 0; j <= b.degree; j++) {
				arr[i + j] += coef[b.degree + i] * b.coef[j];
			}
		}
		for (int i = 0; i <= temp; i++) {
			for (int j = 0; j <= b.degree; j++) {
				coef[i + j] = arr[i + j];//arr임의 배열 정보들을 coef배열로 옮기기
			}
		}
		trim();
	}
	bool iszero() { return degree == 0; }//if 최고차수가 0일때 차수=0반환
	void negate() { //계수 부호를 반대로
		for (int i = 0; i <= degree; i++)
			coef[i] -= coef[i];//계수 부호 바꾸기
	}
	void trim() { //다항식의 속성값들을 변경 
		int count = 0;
		while (!coef[count]) //최고차항이 0이 아닐때까지
			count++;
		if (count) {//최고차항이 0이 아니라면 실행 X
			int temp = degree; //기존 차수 저장
			degree -= count; //최고차항을 감소시킨다
			for (int i = 0; i <= temp - count; i++) //자리를 옮김
				coef[i] = coef[i + count];
		}
	}
};
int main() {
    Polynomial a, b, c;
    a.read();
    b.read();
    c.add(a, b); //c=a+b;
    a.display("A=");
    b.display("B=");
    c.display("A+B=");
    c.sub(a, b); //c=a-b;
    c.display("A-B=");
    c.mult(a, b); //c=a*b;
    c.display("A*B=");
}