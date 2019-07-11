#include<iostream>
#include<cstring>
using namespace std;
int arr[5][8];
int direction[5]; // 돌릴 방향 저장
int K, result;
void turn_right(int index) { // 시계방향 회전
	int temp = arr[index][7];
	for (int i = 7; i > 0; i--)
		arr[index][i] = arr[index][i - 1];
	arr[index][0] = temp;
}
void turn_left(int index) { // 반시계방향 회전
	int temp = arr[index][0];
	for (int i = 0; i < 7; i++)
		arr[index][i] = arr[index][i + 1];
	arr[index][7] = temp;
}
void right_check(int index, int d) {
	// 오른쪽 방향으로 자석 확인하면서 돌릴 수 있는지 확인
	if (index > 4)	 return;

	direction[index] = d;

	if (arr[index][2] != arr[index + 1][6])
		right_check(index + 1, d*-1);
}
void left_check(int index, int d) {
	// 왼쪽 방향으로 자석 확인하면서 돌릴 수 있는지 확인
	if (index < 1) return;

	direction[index] = d;

	if (arr[index][6] != arr[index - 1][2])
		left_check(index - 1, d*-1);
}
void roll(int index, int d) {
	// 해당 위치에서 오른쪽 자석 돌릴 수 있는지 확인
	// 해당 위치에서 왼쪽 자석 돌릴 수 있는지 확인
	memset(direction, 0, sizeof(direction));

	direction[index] = d;

	if (index == 1) {
		if (arr[1][2] != arr[2][6])
			right_check(index + 1, d*-1);
	}
	else if (index == 4) {
		if (arr[4][6] != arr[3][2])
			left_check(index - 1, d*-1);
	}
	else {
		if (arr[index][2] != arr[index + 1][6])
			right_check(index + 1, d*-1);
		if (arr[index][6] != arr[index - 1][2])
			left_check(index - 1, d*-1);
	}

	for (int i = 1; i <= 4; i++) {
		if (direction[i] == 0) continue;
		else if (direction[i] == 1)
			turn_right(i);
		else
			turn_left(i);
	}
}
int main()
{
	//freopen("sample_input.txt", "r", stdin);
	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		result = 0;
		cin >> K;
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++)
				cin >> arr[i][j];
		}

		int index, d;
		for (int i = 0; i < K; i++) {
			cin >> index >> d;
			roll(index, d);
		}

		for (int i = 1; i <= 4; i++) {
			if (arr[i][0] == 0)	continue;
			if (i == 1)
				result += 1;
			else if (i == 2)
				result += 2;
			else if (i == 3)
				result += 4;
			else
				result += 8;
		}
		cout << "#" << test << " " << result << endl;
	}
	return 0;
}