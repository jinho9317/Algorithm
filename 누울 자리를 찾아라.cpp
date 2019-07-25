#include<iostream>
using namespace std;
int N, cnt_y, cnt_x;
char arr[101][101];
void go_right(int y, int x, int cnt) {
	if (x >= N) return;

	int nx = x + 1;
	if (cnt >= 2) {
		cnt_y++;
		
		while (nx < N && arr[y][nx] == '.') {
			nx++;
		}
	}

	if (arr[y][nx] == 'X')
		go_right(y, nx, 0);
	else
		go_right(y, nx, cnt + 1);
}
void go_down(int y, int x, int cnt) {
	if (y >= N) return;

	int ny = y + 1;
	if (cnt >= 2) {
		cnt_x++;
		
		while (ny < N&&arr[ny][x] == '.')
			ny++;
	}

	if (arr[ny][x] == 'X')
		go_down(ny, x, 0);
	else
		go_down(ny, x, cnt + 1);
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) {
		if (arr[i][0] == 'X')
			go_right(i, 0, 0);
		else
			go_right(i, 0, 1);
	}

	for (int j = 0; j < N; j++) {
		if (arr[0][j] == 'X')
			go_down(0, j, 0);
		else
			go_down(0, j, 1);
	}

	cout << cnt_y << " " << cnt_x << endl;
	return 0;
}