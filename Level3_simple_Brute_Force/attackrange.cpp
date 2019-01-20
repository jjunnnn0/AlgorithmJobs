// level 3 attack range
#include <iostream>
using namespace std;

int main() {
	int n, x, y, r; // r<= n/2
	cin >> n;
	cin >> x >> y >> r;
	int input[101][101] = { 0 };

	input[x][y] = -1;
	for (int k = 1; k <= r; k++) {
		if (x - k >= 0) input[x - k][y] = k;
		if (x + k <= n) input[x + k][y] = k;
		if (y - k >= 0) input[x][y - k] = k;
		if (y + k <= n) input[x][y + k] = k;
	}
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		if (input[i][j] == -1) cout << "x ";
	//		else cout << input[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	//cout << endl;
	//
	for (int i = 1; i <= n; i++) {
		if (i == x) continue; // x는 행
		for (int j = 1; j <= n; j++) {
			if (input[i][j] != 0 && input[i][j] < r) {
				int k = input[i][j];
				while (k != r) {
					k++;
					input[i][j - (k - input[i][j])] = k;
					if (j + k - input[i][j] <= n) input[i][j + k - input[i][j]] = k; // boundary!!!!
				}
				break;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (input[i][j] == -1) cout << "x ";
			else cout << input[i][j] << ' ';
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
// 이 문제도 boundary 설정 제대로 안해서 100점 못맞음.
// 절댓값으로 거리 구해서 하는것도 짜보기