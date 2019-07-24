#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
char prime[1003002];
int N; // N=1,000,000(최대)일때 소수&팰린드롬 값 1003001
int solve(int n) {
	string s = to_string(n);
	string r = to_string(n);
	reverse(r.begin(), r.end());

	if (s == r) {
		if (prime[n]) return -1;
		else return n;
	}
	else
		return -1;
}
int main()
{
	cin >> N;

	prime[1] = true;
	for (int i = 2; i <= 1003001; i++) {
		if (prime[i]) continue;

		for (int j = i + i; j <= 1003001; j += i)
			prime[j] = true;
	}
	
	for (int i = N;; i++) {
		if (solve(i) == -1) continue;
		else {
			cout << solve(i) << endl;
			break;
		}
	}

	return 0;
}