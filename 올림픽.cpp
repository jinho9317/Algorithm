#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct info {
	int gold, silver, bronze, rank, country;
	info(int country, int gold, int silver, int bronze) : country(country), gold(gold), silver(silver), bronze(bronze) {}
};
int N, K;
vector<info> v;

bool compare(info a, info b) {
	if (a.gold > b.gold) {
		return true;
	}
	else if (a.gold == b.gold) {
		if (a.silver > b.silver)
			return true;
		else if (a.silver == b.silver) {
			if (a.bronze > b.bronze)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
void setRank(int index, int rank, int cnt) {
	if (index >= N) return;

	if ((v[index].gold == v[index - 1].gold) && (v[index].silver == v[index - 1].silver) && (v[index].bronze == v[index - 1].bronze)) {
		v[index].rank = rank;
		setRank(index + 1, rank, cnt + 1);
	}
	else {
		v[index].rank = rank + cnt;
		setRank(index + 1, rank + cnt, 1);
	}
}
int main() {
	cin >> N >> K;
	int c, g, s, b;
	for (int i = 0; i < N; i++) {
		cin >> c >> g >> s >> b;
		v.push_back(info(c, g, s, b));
	}

	sort(v.begin(), v.end(), compare);

	v[0].rank = 1;
	setRank(1, 1, 1);

	for (int i = 0; i < N; i++) {
		if (v[i].country != K) continue;

		cout << v[i].rank << endl;
		break;
	}

	return 0;
}