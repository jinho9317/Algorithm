#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
char arr[5][6];
bool check[5][5], visit[5][5]; // check : 자리선정, visit : 인접확인
int result;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
queue<pair<int, int>> q;
void go() {
	int cnt = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		cnt++;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5 || !check[ny][nx] || visit[ny][nx]) continue;

			visit[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}
	}

	if (cnt == 7)
		result++;
}
void solve(int num, int cnt, int s) {
	// 1. 7개 자리 선정
	// 2. 인접 확인
	if (cnt >= 7) {
		if (s < 4) return;

		memset(visit, false, sizeof(visit));

		bool done = false;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (!check[i][j]) continue;

				visit[i][j] = true;
				q.push(make_pair(i, j));

				done = true;
				break;
			}
			if (done)
				break;
		}

		go();

		return;
	}

	for (int i = num + 1; i < 25; i++) {

		check[i / 5][i % 5] = true;
		if (arr[i / 5][i % 5] == 'S')
			solve(i, cnt + 1, s + 1);
		else
			solve(i, cnt + 1, s);
		check[i / 5][i % 5] = false;
	}
}
int main() {
	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	for (int i = 0; i < 25; i++) {

		check[i / 5][i % 5] = true;

		if (arr[i / 5][i % 5] == 'S')
			solve(i, 1, 1);
		else
			solve(i, 1, 0);

		check[i / 5][i % 5] = false;
	}

	cout << result << endl;

	return 0;
}