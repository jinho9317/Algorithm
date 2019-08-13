#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N, result = 1;
int arr[100][100];
bool check[100][100];
queue<pair<int, int>> q;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N || check[ny][nx]) continue;

			check[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}
	}
}
int main() {
	int Max = -987987987, Min = 987987987;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			cin >> arr[i][j];
			if (Max < arr[i][j])
				Max = arr[i][j];
			if (Min > arr[i][j])
				Min = arr[i][j];
		}
	}

	for (int water = Max - 1; water >= Min; water--) {
		int cnt = 0; // �ش� �� ���̿��� �������� ����

		for (int i = 0; i < N; i++) { // �帶
			for (int j = 0; j < N; j++) {
				if (arr[i][j] <= water)
					check[i][j] = true;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j]) continue;

				cnt++;
				check[i][j];
				q.push(make_pair(i, j));
				bfs();
			}
		}

		if (result < cnt)
			result = cnt;

		memset(check, false, sizeof(check));
	}

	cout << result << endl;

	return 0;
}