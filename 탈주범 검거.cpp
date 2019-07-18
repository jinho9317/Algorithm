#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct info {
	int y, x, t;
	info(int y, int x, int t) :y(y), x(x), t(t) {}
};
int N, M, R, C, L, result;
int arr[51][51];
bool check[51][51];
queue<info> q;
int tunnel[8][4] = { {4,4,4,4}, {0,1,2,3},{0,1,4,4},{2,3,4,4},{0,3,4,4},{1,3,4,4},{1,2,4,4},{0,2,4,4} }; // 터널 방향정보
int dy[] = { -1,1,0,0,0 };
int dx[] = { 0,0,-1,1,0 };
bool possible(int d, int target) {
	if (d == 0) {
		if (target == 3 || target == 4 || target == 7) return false;
	}
	else if (d == 1) {
		if (target == 3 || target == 5 || target == 6) return false;
	}
	else if (d == 2) {
		if (target == 2 || target == 6 || target == 7) return false;
	}
	else {
		if (target == 2 || target == 4 || target == 5) return false;
	}
	return true;
}
void run() {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int time = q.front().t;
		int type = arr[y][x];
		q.pop();

		if (time == L) continue;

		for (int k = 0; k < 4; k++) {
			int ny = y + dy[tunnel[type][k]];
			int nx = x + dx[tunnel[type][k]];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M || check[ny][nx] || arr[ny][nx] == 0) continue;

			if (possible(tunnel[type][k], arr[ny][nx])) { // 해당 방향으로 다음위치로 갈 수 있는지 확인
				check[ny][nx] = true;
				q.push(info(ny, nx, time + 1));
			}
		}
	}

	result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j]) result++;
		}
	}
}
int main() {
	freopen("sample_input.txt", "r", stdin);
	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				cin >> arr[i][j];
		}

		check[R][C] = true;
		q.push(info(R, C, 1));

		run();

		cout << "#" << test << " " << result << endl;
		memset(check, false, sizeof(check));
	}
	return 0;
}