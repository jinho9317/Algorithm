#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, result;
vector<pair<int, int>> v;
int arr[30][30];
void service(int y, int x, int k) {
	int cnt = 0;
	for (int i = 0; i < v.size(); i++){
		if (abs(y - v[i].first) + abs(x - v[i].second) < k) // 서비스 받는 집
			cnt++;
	}
	
	int cost = k * k + (k - 1)*(k - 1);
	int profit = M * cnt - cost;
	
	if (profit >= 0) {
		if (result < cnt)
			result = cnt;
	}
}
int main() {
	freopen("sample_input.txt", "r", stdin);
	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		result = 0; v.clear();
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1)
					v.push_back(make_pair(i, j));
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 1; k <= N + 1; k++) // 해당위치에서 최대 영역까지 서비스 다 해보기
					service(i, j, k);
			}
		}

		cout << "#" << test << " " << result << endl;
	}
	return 0;
}