#include<iostream>
#include<vector>
using namespace std;
int arr[21][21];
bool check[21][21];
int N, K, result, max_h;
vector<pair<int, int>> v; //가장 높은 봉우리 저장
int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
void go(int y, int x, int dist) {

	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d];
		int nx = x + dx[d];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N || check[ny][nx] || arr[ny][nx] >= arr[y][x]) continue;

		check[ny][nx] = true;
		go(ny, nx, dist + 1);
		check[ny][nx] = false;
	}

	if (result < dist)
		result = dist;
}
int main() {
	freopen("sample_input.txt", "r", stdin);
	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		result = 0; max_h = 0;
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
				if (max_h < arr[i][j])
					max_h = arr[i][j];
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == max_h)
					v.push_back(make_pair(i, j));
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 1; k <= K; k++) {
					if (arr[i][j] - k < 0) break;
					arr[i][j] -= k;
					for (int index = 0; index < v.size(); index++) {
						check[v[index].first][v[index].second] = true;
						go(v[index].first, v[index].second, 1);
						check[v[index].first][v[index].second] = false;
					}
					arr[i][j] += k;
				}
			}
		}

		cout << "#" << test << " " << result << endl;
		v.clear();
	}
	return 0;
}