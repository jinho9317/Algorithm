#include<iostream>
#include<queue>
using namespace std;

int R, C, N;
int arr[222][222];
queue<pair<int, int>> q;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

void solve() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] > 0) {
				arr[i][j]--;
				if (arr[i][j] == 0)
					q.push(make_pair(i, j));
			}
			else
				arr[i][j] = 3;
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;

			arr[ny][nx] = 0;
		}
	}
}

int main() {
	cin >> R >> C >> N;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char c; cin >> c;
			if (c == 'O')
				arr[i][j] = 2;
		}
	}
	
	for (int time = 2; time <= N; time++)
		solve();

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 0)
				cout << '.';
			else
				cout << "O";
		}
		cout << endl;
	}

	return 0;
}