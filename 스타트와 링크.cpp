#include<iostream>
using namespace std;
int N, result = 987987987;
int S[22][22];
int team[22];
void solve(int man, int cnt) {
	if (cnt >= N / 2) {
		int start = 0, link = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j || team[i] != team[j]) continue;
				
				if (team[i] == 1)
					start += S[i][j];
				else
					link += S[i][j];
			}
		}

		int temp = (start - link) > 0 ? (start - link) : (link - start);
		
		if (result > temp)
			result = temp;

		return;
	}

	if (man >= N) return;

	team[man] = 1; // ½ºÅ¸Æ® ÆÀ
	solve(man + 1, cnt + 1);
	team[man] = 0; // ¸µÅ© ÆÀ
	solve(man + 1, cnt);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> S[i][j];
	}

	solve(0, 0);

	cout << result << endl;

	return 0;
}