#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, E;
vector<int> v[101];
bool check[101];
int solve(int node) {
	queue<int> q;
	q.push(node);
	check[node] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < v[node].size(); i++) {
			if (check[v[node][i]]) continue;

			check[v[node][i]] = true;
			q.push(v[node][i]);
		}
	}

	int result = 0;
	for (int i = 2; i <= N; i++) {
		if (check[i])
			result++;
	}

	return result;
}
int main() 
{
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int s, e; cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	
	cout << solve(1) << endl;

	return 0;
}