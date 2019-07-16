#include<iostream>
using namespace std;
int N, result, Y, X;
int arr[21][21];
bool check[21][21];
bool eat[101];
int dy[] = { 1,1,-1,-1 };
int dx[] = { 1,-1,-1,1 };
void go(int y, int x, int d, int cnt) { // 현재 좌표, 방향, 디저트 수
	if (Y == y && X == x && d == 3) { // 시작위치로 돌아왔을 때
		if (result < cnt)
			result = cnt;
		return;
	}
	if (y < 0 || x < 0 || y >= N || x >= N || check[y][x] || eat[arr[y][x]]) return; // 좌표 범위, 방문한 카페, 먹은 디저트

	check[y][x] = true; eat[arr[y][x]] = true;

	go(y + dy[d], x + dx[d], d, cnt + 1);

	if (d < 3)
		go(y + dy[d + 1], x + dx[d + 1], d + 1, cnt + 1);

	check[y][x] = false; eat[arr[y][x]] = false;
}
int main() {
	freopen("sample_input.txt", "r", stdin);
	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		result = -1;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cin >> arr[i][j];
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				Y = i; X = j;
				check[i][j] = true; eat[arr[i][j]] = true;
				go(i + 1, j + 1, 0, 1);
				check[i][j] = false; eat[arr[i][j]] = false;
			}
		}

		cout << "#" << test << " " << result << endl;
	}
	return 0;
}