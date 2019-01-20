// level2 배열: array 3
// 입력이 4이면 출력은
// 1 2 4 7
// 3 5 8
// 6 9
// 10
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int input[100][100] = { 0 };
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += i;
	}
	int aa = 1, dd = 2;
	for (int i = 0; i < N; i++) {
		int a = aa;
		int d = i + 1;
		for (int j = 0; j < N; j++) {
			if (j == 0) input[i][j] = aa;
			if (j != 0 && sum >= a + d) {
				a += d;
				input[i][j] = a;
				d++;
				//cout << "a+d " << a+d << endl;
			}
		}
		aa += dd;
		dd++;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (input[i][j] == 0) continue;
			cout << input[i][j] << ' ';
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
// 등차수열을 이용한 풀이
// 행의 값이 초항