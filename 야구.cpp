#include<iostream>
#include<cstring>
using namespace std;
int N, result;
int lineup[10], hitter[51][10], base[5];
bool check[10];
int hit(int num) {
	for (int i = 3; i >= 1; i--) {
		if (base[i] == 0) continue;

		base[i]--;

		if (i + num > 3)
			base[4]++;
		else
			base[i + num]++;
	}

	base[num]++;

	int ret = base[4];
	base[4] = 0;
	return ret;
}
void simulation() {
	int out = 0, index = 1, score = 0;
	
	for (int ining = 1; ining <= N; ining++) {
		memset(base, 0, sizeof(base));
		out = 0;
		
		while (out < 3) {
			if (hitter[ining][lineup[index]] == 0)
				out++;
			else
				score += hit(hitter[ining][lineup[index]]);

			index++;
			if (index >= 10)
				index = 1;
		}
	}
	
	if (result < score)
		result = score;
}
void set_lineup(int index) {
	if (index >= 10) {
		simulation();
		return;
	}
	
	for (int i = 2; i <= 9; i++) {
		if (check[i]) continue;

		lineup[index] = i; check[i] = true;

		if (index == 3)
			set_lineup(index + 2);
		else
			set_lineup(index + 1);

		lineup[index] = 0; check[i] = false;
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 9; j++)
			cin >> hitter[i][j];
	}

	lineup[4] = 1;
	
	set_lineup(1);

	cout << result << endl;
	return 0;
}