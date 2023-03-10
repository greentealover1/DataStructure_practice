#include <iostream>
#define MAX_DEGREE 80 //���׽��� ó�� ������ �ִ� ����+1
using namespace std;

class Polynomial { //���α׷��� ������Ʈ2.1
private:
	int degree;//���׽��� �ְ� ����
	float coef[MAX_DEGREE];//�� �׿� ���� ������ �����(5x^5+4x*5�̸� [5,4...]�̷���
public:
	Polynomial() { degree = 0; }//������
	void read() { //����, ��� �б�
		cout << "���׽��� �ְ� ������ �Է��ϼ���:";
		cin >> degree;
		cout << "�� ���� ����� �Է��ϼ���(�� " << degree + 1 << "��):";
		for (int i = 0; i <= degree; i++)
			cin >> coef[i];//��� �迭�� �� ����� �Է�
	}

	void display(const char* str = " Poly = ") { //���׽��� ���� ���
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

	void add(Polynomial a, Polynomial b) { //c=a+b(���� �Լ�)
		if (a.degree > b.degree) { //a>b��
			*this = a;//a���׽��� �ڱ� ��ü�� ����(c=a+b�϶� c=a;�����ϴ� �κ���)
			for (int i = 0; i < b.degree; i++)
				coef[i + (degree - b.degree)] += b.coef[i];//���׽� ����� ������� �ڽ��� ����迭�� �´� �������� ����
		}
		else { //b>a��
			*this = b;
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] += a.coef[i];
		}
		trim();
	}
	void sub(Polynomial a, Polynomial b) {//c=a-b(����)
		if (a.degree > b.degree) {
			*this = a;
			for (int i = 0; i < b.degree; i++) {
				coef[i + (degree - b.degree)] -= b.coef[i];
			}
		}
		else { //b���� a�׺��� ������ ū ���
			b.negate();//��ȣ �ݴ��
			*this = b;//b���׽��� �ڱ� ��ü�� ����
			for (int i = 0; i <= a.degree; i++) {//,i=0�̸�,coef[0+(�ְ�����-a��ü �ְ�����]+=a.coef[i]
				coef[i + (degree - a.degree)] += a.coef[i];
			}
		}
		trim();
	}

	void mult(Polynomial a, Polynomial b) {//c=a*b(����)
		*this = a;
		int temp = degree;//temp�� ���� ���� ����
		degree += b.degree;//a�� b��ü�� ���� ���ϱ�(2���� *3����=5�����̴ϱ�)
		int arr[MAX_DEGREE];//������ ���� ���� ������ �迭 ����
		for (int i = 0; i <= degree; i++)
			arr[i] = 0;//�迭�� ��� �������� ���� �ʱ�ȭ

		if (temp < b.degree) { //���� ���׽��� �ְ�����<b��ü�� ����
			for (int i = 0; i <= temp; i++) {
				coef[i + b.degree] = coef[i];
				coef[i] = 0;
			}
		}
		else if (temp == b.degree) { //���� ���׽��� �ְ�����=b��ü�� ����
			for (int i = 0; i <= temp; i++) {
				coef[i + temp] = coef[i];
				if (i != temp)
					coef[i] = 0;
			}
		}
		else { //���� ���׽��� �ְ�����>b��ü�� ����
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
		for (int i = 0; i <= temp; i++) { //arr���� �迭�� ���� ���
			for (int j = 0; j <= b.degree; j++) {
				arr[i + j] += coef[b.degree + i] * b.coef[j];
			}
		}
		for (int i = 0; i <= temp; i++) {
			for (int j = 0; j <= b.degree; j++) {
				coef[i + j] = arr[i + j];//arr���� �迭 �������� coef�迭�� �ű��
			}
		}
		trim();
	}
	bool iszero() { return degree == 0; }//if �ְ������� 0�϶� ����=0��ȯ
	void negate() { //��� ��ȣ�� �ݴ��
		for (int i = 0; i <= degree; i++)
			coef[i] -= coef[i];//��� ��ȣ �ٲٱ�
	}
	void trim() { //���׽��� �Ӽ������� ���� 
		int count = 0;
		while (!coef[count]) //�ְ������� 0�� �ƴҶ�����
			count++;
		if (count) {//�ְ������� 0�� �ƴ϶�� ���� X
			int temp = degree; //���� ���� ����
			degree -= count; //�ְ������� ���ҽ�Ų��
			for (int i = 0; i <= temp - count; i++) //�ڸ��� �ű�
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