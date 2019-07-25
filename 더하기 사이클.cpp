#include<iostream>
using namespace std;
int N, result;
void solve(int num, int cnt) {
	if (num == N && cnt > 0) {
		result = cnt;
		return;
	}

	int r = num % 10;
	
	if (num < 10) {
		r *= 11;
		solve(r, cnt + 1);
	}
	else {
		int sum = 0, temp = num;
		while (temp / 10 > 0) {
			sum += temp % 10;
			temp /= 10;
		}
		sum += temp;
		sum %= 10;
		temp = r * 10 + sum;
		solve(temp, cnt + 1);
	}
}
int main() {
	cin >> N;
	solve(N, 0);
	cout << result << endl;
	return 0;
}