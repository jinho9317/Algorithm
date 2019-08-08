#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
int K;
bool check[10];
string arr, result_min, result_max, s;
void solve(int index) {
	if (index > K) {
		for (int i = 0; i < K; i++) {
			if (arr[i] == '<') {
				if (s[i] < s[i + 1]) continue;
				else return;
			}
			else {
				if (s[i] > s[i + 1]) continue;
				else return;
			}
		}

		if (result_min.size() == 0)
			result_min = s;

		result_max = s;
		
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (check[i]) continue;

		check[i] = true;
		s.push_back(i + '0');
		solve(index + 1);
		s.pop_back();
		check[i] = false;
	}
}
int main() {
	cin >> K;
	for (int i = 0; i < K; i++) {
		char c; cin >> c;
		arr.push_back(c);
	}

	for (int i = 0; i <= 9; i++) {
		check[i] = true;
		s.push_back(i + '0');
		solve(1);
		s.pop_back();
		check[i] = false;
	}

	cout << result_max << endl;
	cout << result_min << endl;

	return 0;
}