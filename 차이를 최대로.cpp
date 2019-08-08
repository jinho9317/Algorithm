#include<iostream>
using namespace std;
int N, result = -987987987;
int arr[10], idx[10], temp[10];
bool check[10];
void solve(int index) {
	if (index >= N) {
		for (int i = 0; i < N; i++) {
			temp[i] = arr[idx[i]];
		}

		int sum = 0;
		for (int i = 0; i < N - 1; i++) {
			int tmp = temp[i] - temp[i + 1];
			if (tmp < 0)
				tmp *= -1;
			sum += tmp;
		}

		if (result < sum)
			result = sum;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (check[i]) continue;
		
		idx[index] = i;
		check[i] = true;
		solve(index + 1);
		check[i] = false;
	}

}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	solve(0);

	cout << result << endl;
	return 0;
}