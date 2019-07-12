#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct info {
	int y, x, d, s;
	info(int y, int x) : y(y), x(x) {}
};
int arr[10][10];
vector<pair<int, int>> stair;
vector<info> person;
int N, result;
bool compare(int a, int b) {
	return person[a].d < person[b].d;
}
int calc(int index, int s) {
	int Y = stair[s].first - person[index].y;
	int X = stair[s].second - person[index].x;

	if (X < 0) X *= -1;
	if (Y < 0) Y *= -1;

	return X + Y;
}
void solve() {

	int check[300][2] = { 0, }; // Ư�� �ð��� �ش� ��ܿ� �� �� �ִ��� üũ
	vector<int> stair0, stair1;

	for (int i = 0; i < person.size(); i++) { // ������� �й�
		if (person[i].s == 0)
			stair0.push_back(i);
		else
			stair1.push_back(i);
	}

	// 0�� ������� �̵�
	sort(stair0.begin(), stair0.end(), compare); // �Ÿ��� ����

	int time = 0, finish_time0 = 0, finish_time1 = 0;

	for (int i = 0; i < stair0.size(); i++) {
		time = person[stair0[i]].d + 1; // ��� �������� ������ �ð�
		
		if (check[time][0] >= 3) { // ��� ��ȭ
			while (check[time][0] >= 3) // ��ܿ� �ڸ��� �������� ���
				time++;
		}

		for (int t = 0; t < arr[stair[0].first][stair[0].second]; t++)
			check[time + t][0]++;

		if (finish_time0 < time + arr[stair[0].first][stair[0].second])
			finish_time0 = time + arr[stair[0].first][stair[0].second];
	}

	// 1�� ������� �̵�
	sort(stair1.begin(), stair1.end(), compare);

	for (int i = 0; i < stair1.size(); i++) {
		time = person[stair1[i]].d + 1;

		if (check[time][1] >= 3) {
			while (check[time][1] >= 3)
				time++;
		}

		for (int t = 0; t < arr[stair[1].first][stair[1].second]; t++)
			check[time + t][1]++;

		if (finish_time1 < time + arr[stair[1].first][stair[1].second])
			finish_time1 = time + arr[stair[1].first][stair[1].second];
	}

	result = min(result, max(finish_time0, finish_time1));
}
void group(int index) {
	// 0�� �Ǵ� 1�� ������� ���� ����� ���ϴ� �Լ�

	if (index >= person.size()) {
		solve();
		return;
	}

	person[index].s = 0; // 0�����
	person[index].d = calc(index, 0);
	group(index + 1);

	person[index].s = 1; // 1�����
	person[index].d = calc(index, 1);
	group(index + 1);
}
int main() {
	freopen("sample_input.txt", "r", stdin);
	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		result = 987987987;
		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];

				if (arr[i][j] == 1)
					person.push_back(info(i, j));
				else if (arr[i][j] >= 2)
					stair.push_back(make_pair(i, j));
			}
		}

		group(0);

		cout << "#" << test << " " << result << endl;
		stair.clear(); person.clear();
	}
	return 0;
}