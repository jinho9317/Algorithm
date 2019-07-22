#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int L, C;
bool check[30];
vector<char> v, result;
void solve(int index, int cnt, int mo) {
	if (cnt >= L) {
		if (mo >= 1 && cnt - mo >= 2) {
			for (int i = 0; i < result.size(); i++)
				cout << result[i];
			cout << endl;
		}
		return;
	}

	for (int i = index; i < C; i++) {
		result.push_back(v[i]);
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
			solve(i + 1, cnt + 1, mo + 1);
		else
			solve(i + 1, cnt + 1, mo);
		result.pop_back();
	}
}
int main() {
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		char c; cin >> c;
		v.push_back(c);
	}

	sort(v.begin(), v.end());

	solve(0, 0, 0);

	return 0;
}