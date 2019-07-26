#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct info {
	char color; int num;
	info(char color, int num) : color(color), num(num) {}
};
vector<info> v;
int result = 0;
bool compare(info a, info b) {
	return a.num < b.num;
}
void solve() {
	if (v[0].color == v[1].color && v[1].color == v[2].color && v[2].color == v[3].color && v[3].color == v[4].color) { // 5�� �������϶�
		bool _continue = true;

		for (int i = 0; i < 4; i++) {
			if (v[i + 1].num - v[i].num == 1) continue;
			_continue = false;
			break;
		}

		if (_continue) // 1�� ��Ģ
			result = max(result, v[4].num + 900);
		else // 4�� ��Ģ
			result = max(result, v[4].num + 600);
	}
	
	int cnt[10] = { 0 }; // �� ���ں� ī�� ����
	for (int i = 0; i < 5; i++)
		cnt[v[i].num]++;

	for (int i = 1; i <= 9; i++) { // 2�� ��Ģ
		if (cnt[i] == 4) {
			result = max(result, i + 800);
		}
		if (cnt[i] == 3) {
			bool done = false;
			for (int j = 1; j <= 9; j++) {
				if (cnt[j] == 2) { // 3�� ��Ģ
					result = max(result, i * 10 + j + 700);
					done = true;
					break;
				}
			}
			if (!done) { // 6�� ��Ģ
				result = max(result, i + 400);
			}
		}
		if (cnt[i] == 2) {
			bool done = false;
			for (int j = 1; j <= 9; j++) {
				if (i == j) continue;
				if (cnt[j] == 2) { // 7�� ��Ģ
					if (i < j)
						result = max(result, j * 10 + i + 300);
					else
						result = max(result, i * 10 + j + 300);
					done = true;
					break;
				}
			}
			if (!done) { // 8�� ��Ģ
				result = max(result, i + 200);
			}
		}
	}

	bool _continue = true;
	for (int i = 0; i < 4; i++) {
		if (v[i + 1].num - v[i].num == 1) continue;
		_continue = false;
		break;
	}
	if (_continue) { // 5�� ��Ģ
		result = max(result, v[4].num + 500);
	}

	result = max(result, v[4].num + 100); // 9�� ��Ģ
}
int main() {
	for (int i = 0; i < 5; i++) {
		char c; int n;
		cin >> c >> n;
		v.push_back(info(c, n));
	}

	sort(v.begin(), v.end(), compare); // ���ڸ� �������� �������� ����

	solve();

	cout << result << endl;
	return 0;
}