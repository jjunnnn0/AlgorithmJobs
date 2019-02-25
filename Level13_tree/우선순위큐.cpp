#include <iostream>

using namespace std;

const int MAX = 100;

struct priorityQueue {
	int data[MAX];
	int len = 1; // root는 1부터 시작
	void push(int x) {
		data[len++] = x;
		int idx = len - 1; // 현재 내 위치
		while (idx > 1) { // root에 push 할 때 제외하고 부모 관계가 성립이 안되는 경우
			if (data[idx] < data[idx / 2]) {
				int temp = data[idx];
				data[idx] = data[idx / 2];
				data[idx / 2] = temp;
				idx = idx / 2;
			}
			else break;
		}
	}

	void pop() {
		data[1] = data[len - 1]; // 맨 끝 node 가져오기 root로 가져오기
		data[len - 1] = 0; // 맨 끝 node 삭제하기
		len--;
		int idx = 1;
		while (1) { // 3가지 경우 고려
			int pIdx = -1; // 우선순위가 더 높은 node 위치 저장
			if (2 * idx >= len) break; // 자식 node가 없는 경우
			else if (1 <= 2 * idx && 2 * idx < len && 2 * idx + 1 >= len) { // 왼쪽 자식 node만 있는 경우
				pIdx = 2 * idx;
			}
			else { // 둘 다 있는 경우
				if (data[2 * idx] < data[2 * idx + 1]) // 왼쪽 자식 node가 우선순위가 더 높은 경우
					pIdx = 2 * idx; 
				else pIdx = 2 * idx + 1; // 오른쪽 자식 node가 더 우선순위가 높은 경우
			}
			if (data[idx] > data[pIdx]) {
				int temp = data[idx];
				data[idx] = data[pIdx];
				data[pIdx] = temp;
				idx = pIdx; // 내 위치 update
			}
			else break;
		}
	}

	int top() {
		return data[1]; // root 반환
	}
};

int main(void) {
	int n;
	cin >> n;

	priorityQueue PQ;
	
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		PQ.push(temp);
	}
	for (int i = 1; i <= n; i++) cout << PQ.data[i]<<' ';
	cout << endl;

	cout << PQ.top() << endl;
	PQ.pop();
	cout << PQ.top() << endl;
	PQ.pop();
	cout << PQ.top() << endl;

	return 0;
}