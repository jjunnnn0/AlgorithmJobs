// class president
#include <iostream>
using namespace std;

int main() {
	int students[1001][6]; // 1000명, 5개의 학년
	
	int n;
	cin >> n;
	int *same_class = (int*)calloc((n + 1)*(n + 1), sizeof(int));
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> students[i][j];
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= 5; i++) {
			int now = students[k][i];
			for (int j = 1; j <= n; j++) {
				if (students[j][i] == now && k!=j) {
					same_class[k*n+j] = 1;
				}
			}
		}
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout<<same_class[i*n+j]<<' ';
		}
		cout << endl;
	}*/

	int max = -1;
	int who = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += same_class[i*n+j];
		}
		//cout << sum << endl;
		students[i][0] = sum;
		if (max < sum) {
			max = sum;
			who = i;
		}
	}
	cout << who;

	system("pause");
	return 0;
}
