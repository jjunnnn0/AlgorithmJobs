// level 3 rook
// 1이 king, 2가 rook, 3이 그 외의 것들
// rook이 king을 잡을수있으면 1
#include <iostream>
using namespace std;
int main() {
	int chess[9][9] = { 0 };
	int cnt_rook = 0;
	int index_rook[4] = { 0 };
	int index_king[2];
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			cin >> chess[i][j];
			if (chess[i][j] == 2) {
				index_rook[2 * cnt_rook] = i;
				index_rook[2 * cnt_rook + 1] = j;
				cnt_rook++;
			}
			if (chess[i][j] == 1) {
				index_king[0] = i;
				index_king[1] = j;
			}
		}
	}

	int row_yes = 0;
	int col_yes = 0;
	for (int k = 0; k < cnt_rook; k++) {		
		if (index_king[0] > index_rook[2 * k] && index_king[1]==index_rook[2*k+1]) { // 행
			for (int j = 1; j <= 8; j++) {
				if (j > index_rook[2 * k] && j < index_king[0] && chess[j][index_king[1]] == 3) {
					row_yes = -1;
					break;
				}
				else if (j >= index_rook[2 * k] && j <= index_king[0] && chess[j][index_king[1]] != 3) {
					row_yes = 1;
				}
			}
		}
		else if (index_king[0] < index_rook[2 * k] && index_king[1] == index_rook[2 * k + 1]) {//행
			for (int j = 1; j <= 8; j++) {
				if (j<index_rook[2 * k] && j>index_king[0] && chess[j][index_king[1]] == 3) {
					row_yes = -1;
					break;
				}
				else if (j<=index_rook[2 * k] && j>=index_king[0] && chess[j][index_king[1]] != 3) {
					row_yes = 1;
				}
			}
		}

		if (index_king[1] > index_rook[2 * k + 1] && index_king[0] == index_rook[2 * k]) {//열
			for (int i = 1; i <= 8; i++) {
				if (i > index_rook[2 * k+1] && i < index_king[1] && chess[index_king[0]][i] == 3) {
					col_yes = -1;
					break;
				}
				else if (i >= index_rook[2 * k + 1] && i <= index_king[1] && chess[index_king[0]][i] != 3) {
					col_yes = 1;
				}
			}
		}
		else if (index_king[1] < index_rook[2 * k + 1] && index_king[0] == index_rook[2 * k]) {//열
			for (int i = 1; i <= 8; i++) {
				if (i < index_rook[2 * k+1] && i > index_king[1] && chess[index_king[0]][i] == 3) {
					col_yes = -1;
					break;
				}
				else if (i <= index_rook[2 * k + 1] && i >= index_king[1] && chess[index_king[0]][i] != 3) {
					col_yes = 1;
				}
			}
		}
	}
	//cout << col_yes << endl;
	//cout << row_yes << endl;
	if(col_yes==1 || row_yes==1)	cout << 1;
	else cout << 0;
	system("pause");
	return 0;
}
//// if문에서 바운더리 설정 잘하자.