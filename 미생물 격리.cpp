#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
struct info {
	int y, x, num, d;
	bool dead;
	info(int y, int x, int num, int d) : y(y), x(x), num(num), d(d), dead(false) {}
};
int N, M, K;
vector<info> v;
int dy[] = { 0,-1,1,0,0 };
int dx[] = { 0,0,0,-1,1 };
int counter(int d) {// 방향 반대로 바꿔주는 함수
	if (d == 1) return 2;
	else if (d == 2) return 1;
	else if (d == 3) return 4;
	else return 3;
}
int arr[100][100];
void dup(int y, int x) {// 중복 처리
	int max_num = 0, max_index, sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].dead) continue;
		if (v[i].y == y && v[i].x == x) {
			if (max_num < v[i].num) {
				max_num = v[i].num;
				max_index = i;
			}
			sum += v[i].num;
			v[i].num = 0;
			v[i].dead = true;
		}
	}
	v[max_index].num = sum;
	v[max_index].dead = false;
}
void move() {
	// 이동
	// 중복 체크

	memset(arr, 0, sizeof(arr));
	// 이동
	for (int i = 0; i < v.size(); i++) {
		if (v[i].dead) continue;

		v[i].y += dy[v[i].d];
		v[i].x += dx[v[i].d];

		if (v[i].y == 0 || v[i].y == N - 1 || v[i].x == 0 || v[i].x == N - 1) { // 약품 닿을 때
			v[i].d = counter(v[i].d);
			v[i].num /= 2;
			if (v[i].num <= 0)
				v[i].dead = true;
		}

		if (v[i].dead) continue;

		arr[v[i].y][v[i].x]++;
	}
	// 중복 체크
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] <= 1) continue;
			dup(i, j);
		}
	}
}
int main() {
	freopen("sample_input.txt", "r", stdin);
	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			int y, x, n, d;
			cin >> y >> x >> n >> d;
			v.push_back(info(y, x, n, d));
		}
		for (int time = 0; time < M; time++) {
			move();
		}
		int result = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].dead) continue;
			result += v[i].num;
		}
		cout << "#" << test << " " << result << endl;
		v.clear();
	}
	return 0;
}