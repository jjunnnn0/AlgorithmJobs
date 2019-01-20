// level 3 colorpaper
#include <iostream>
using namespace std;

int main() {
	int N, x, y, w, h;
	cin >> N;

	int plane[101][101] = { 0 };
	int color = 0;
	int max_x = -1, max_y = -1;
	for (int k = 0; k < N; k++) {
		cin >> x >> y >> w >> h;
		if (max_x < x + w) {
			max_x = x + w;
			if (max_x > 100) max_x = 100; // boundary!!!
		}
		if (max_y < y + h) {
			max_y = y + h;
			if (max_y > 100) max_y = 100; // boundary!!!
		}
		color++;
		for (int i = y; i < y + h; i++) {
			for (int j = x; j < x + w; j++) {
				plane[i][j] = color;
			}
		}
	}
	int cnt[101] = { 0 };
	for (int k = 1; k <= N; k++) {
		for (int i = 0; i <= max_y; i++) {
			for (int j = 0; j <= max_x; j++) {
				if (plane[i][j] == k) cnt[k]++;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << cnt[i] << endl;
	}
	system("pause");
	return 0;
}
// boundary 설정 잘하자. 배열 넘어가지 않도록
// convolution 했던걸 기억하자 if문 8개쓰지 말자 (이건 지뢰찾기 문제)
// 3x3 window 사용하자.