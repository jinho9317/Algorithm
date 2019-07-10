#include<iostream>
using namespace std;
int N, X, result;
int arr[30][30];
bool check[30][30];
void go_right(int y, int x) {
	// ���������� �̵��ϸ鼭 Ȱ�ַ� ���� Ȯ��
	// ���� �� ���� �̵��� �� ������ Ȱ�ַ� ����

	if (x >= N - 1) { // Ȱ�ַΰ���
		result++;
		return;
	}

	if (arr[y][x] == arr[y][x + 1])
		go_right(y, x + 1);
	else if (arr[y][x] < arr[y][x + 1]) { // ���� ���̰� Ŭ��
		if (arr[y][x + 1] - arr[y][x] > 1) return; // �������� 1�̻��� �Ǽ� �Ұ�

		for (int k = 0; k < X; k++) { // Ȱ�ַ� �Ǽ� ���� Ȯ��
			int nx = x - k;
			if (nx < 0 || arr[y][x] != arr[y][nx] || check[y][nx]) return; // �Ǽ� �Ұ�
		}


		for (int k = 0; k < X; k++) { // Ȱ�ַ� �Ǽ�
			int nx = x - k;
			check[y][nx] = true;
		}
		go_right(y, x + 1);
		for (int k = 0; k < X; k++) {
			int nx = x - k;
			check[y][nx] = false;
		}
	}
	else { // ���� ���̰� ������
		if (arr[y][x] - arr[y][x + 1] > 1) return;

		for (int k = 1; k <= X; k++) {
			int nx = x + k;
			if (nx >= N || arr[y][x] - 1 != arr[y][nx])	return;
		}

		for (int k = 1; k <= X; k++) {
			int nx = x + k;
			check[y][nx] = true;
		}
		go_right(y, x + X);
		for (int k = 1; k <= X; k++) {
			int nx = x + k;
			check[y][nx] = false;
		}
	}
}
void go_down(int y, int x) {
	// �Ʒ��� �̵��ϸ鼭 Ȱ�ַ� ���� Ȯ��
	// ���� �� ������ �̵��� �� ������ Ȱ�ַ� ����

	if (y >= N - 1) {
		result++;
		return;
	}

	if (arr[y][x] == arr[y + 1][x])
		go_down(y + 1, x);
	else if (arr[y][x] < arr[y + 1][x]) {
		if (arr[y + 1][x] - arr[y][x] > 1) return;
		for (int k = 0; k < X; k++) {
			int ny = y - k;
			if (ny < 0 || arr[y][x] != arr[ny][x] || check[ny][x]) return;
		}

		for (int k = 0; k < X; k++) {
			int ny = y - k;
			check[ny][x] = true;
		}
		go_down(y + 1, x);
		for (int k = 0; k < X; k++) {
			int ny = y - k;
			check[ny][x] = false;
		}
	}
	else {
		if (arr[y][x] - arr[y + 1][x] > 1) return;
		for (int k = 1; k <= X; k++) {
			int ny = y + k;
			if (ny >= N || arr[y][x] - 1 != arr[ny][x]) return;
		}

		for (int k = 1; k <= X; k++) {
			int ny = y + k;
			check[ny][x] = true;
		}
		go_down(y + X, x);
		for (int k = 1; k <= X; k++) {
			int ny = y + k;
			check[ny][x] = false;
		}
	}
}
int main()
{
	freopen("sample_input.txt", "r", stdin);
	int T; cin >> T;
	for (int test = 1; test <= T; test++) {
		result = 0;
		cin >> N >> X;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cin >> arr[i][j];
		}

		for (int i = 0; i < N; i++) // ���� Ȯ��
			go_right(i, 0);
		for (int j = 0; j < N; j++) // ���� Ȯ��
			go_down(0, j);

		cout << "#" << test << " " << result << endl;
	}
	return 0;
}