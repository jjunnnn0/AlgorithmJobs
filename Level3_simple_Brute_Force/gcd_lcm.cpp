// GCD LCM
// 최대공약수 최소공배수
#include <iostream>
using namespace std;

int main() {
	int a, b, min;
	cin >> a >> b;
	if (a >= b) min = b;
	if (a < b) min = a;
	int GCD = 1, LCM;
	for (int i = 2; i <= min; i++) {
		if (a%i == 0 && b%i == 0) GCD = i;
	}
	LCM = a * b / GCD;
	cout << GCD << '\n' << LCM;
	
	system("pause");
	return 0;
}
// 최대공약수는 작은애 기준으로 for문
// 최소공배수 = 두수의 곱 / 최대공약수