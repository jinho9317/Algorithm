#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct info {
	int r, c, s;
	info(int r, int c, int s) : r(r), c(c), s(s) {}
};
int N, M, K, result = 987987987;
int arr[51][51], temp[51][51];
int turn[6]; // ȸ������ ����
bool check[6];
vector<info> v; // ȸ������ ����
void simulate() {
	// 1. �ٱ� ���� �������� ȸ��
	// 2. �Ʒ��� ���� -> �����ʿ��� �������� -> ������ �Ʒ��� -> ���ʿ��� ����������
	for (int i = 0; i < K; i++) {
		int start_y = v[turn[i]].r - v[turn[i]].s, start_x = v[turn[i]].c - v[turn[i]].s;
		int end_y = v[turn[i]].r + v[turn[i]].s, end_x = v[turn[i]].c + v[turn[i]].s;

		while (start_y < end_y) {
			int y = start_y + 1, x = start_x;
			int num = temp[start_y][start_x];

			while (y <= end_y) {
				temp[y - 1][x] = temp[y][x];
				y++;
			}
			y--; x++;
			
			while (x <= end_x) {
				temp[y][x - 1] = temp[y][x];
				x++;
			}
			x--; y--;
			
			while (y >= start_y) {
				temp[y + 1][x] = temp[y][x];
				y--;
			}
			y++; x--;
			
			while (x > start_x) {
				temp[y][x + 1] = temp[y][x];
				x--;
			}
			x++;
			temp[y][x] = num;
			start_y++; start_x++; end_y--; end_x--;
		}
	}
}
void solve(int index) {
	if (index >= K) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++)
				temp[i][j] = arr[i][j];
		}

		simulate();

		for (int i = 1; i <= N; i++) {
			int sum = 0;

			for (int j = 1; j <= M; j++)
				sum += temp[i][j];

			result = min(result, sum);
		}
		
		return;
	}

	for (int i = 0; i < K; i++) {
		if (check[i]) continue;
		
		turn[index] = i;
		check[i] = true;
		solve(index + 1);
		check[i] = false;
	}
}

int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		v.push_back(info(r, c, s));
	}

	solve(0);

	cout << result << endl;
	return 0;
}