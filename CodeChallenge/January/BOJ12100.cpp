#include <iostream>
#include <vector>
int N;
int MAX = 0;
using namespace std;
void moveBoard(vector<vector<int>> arr, int dir, int depth, int max);
int changeBoard(vector<vector<int>>& arr, int dir, int max);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int max = 0;
	cin >> N;
	vector<vector<int>> board(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] > max) max = board[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		moveBoard(board, i, 1, max);
	}
	cout << MAX;
}
void moveBoard(vector<vector<int>> arr, int dir, int depth, int max) {
	//이동
	max = changeBoard(arr, dir, max);
	if (depth == 5) {
		if (max > MAX) MAX = max;
		return;
	}
	for (int i = 0; i < 4; i++) {
		moveBoard(arr, i, depth + 1, max);
	}

}
int changeBoard(vector<vector<int>>& arr, int dir, int max) {
	switch (dir) {

	case 0:
		for (int i = 0; i < N; i++) {
			//공통된부분 2배, 남은공간은 0으로
			int move = N - 2;

			for (int j = N - 1; j >= 0; j--) {
				if (move >= j) move = j - 1;
				while (move >= 0 && arr[i][move] == 0) --move;
				if (move < 0) break;
				if (arr[i][j] == 0) {
					arr[i][j++] = arr[i][move];
					arr[i][move--] = 0;
				}
				else {
					if (arr[i][j] == arr[i][move]) {
						arr[i][j] *= 2;
						if (arr[i][j] > max) max = arr[i][j];
						arr[i][move--] = 0;
					}

				}
			}
		}
		break;

	case 1:
		for (int i = 0; i < N; i++) {
			int move = N - 2;
			for (int j = N - 1; j >= 0; j--) {
				if (move >= j) move = j - 1;
				while (move >= 0 && arr[move][i] == 0) --move;
				if (move < 0) break;
				if (arr[j][i] == 0) {
					arr[j++][i] = arr[move][i];
					arr[move--][i] = 0;
				}
				else {
					if (arr[j][i] == arr[move][i]) {
						arr[j][i] *= 2;
						if (arr[j][i] > max) max = arr[j][i];
						arr[move--][i] = 0;
					}

				}
			}
		}
		break;

	case 2:
		for (int i = 0; i < N; i++) {
			int move = 1;
			for (int j = 0; j < N; j++) {
				if (move <= j) move = j + 1;
				while (move < N && arr[i][move] == 0) ++move;
				if (move >= N) break;
				if (arr[i][j] == 0) {
					arr[i][j--] = arr[i][move];
					arr[i][move++] = 0;
				}
				else {
					if (arr[i][j] == arr[i][move]) {
						arr[i][j] *= 2;
						if (arr[i][j] > max) max = arr[i][j];
						arr[i][move++] = 0;
					}

				}
			}
		}
		break;


	case 3:
		for (int i = 0; i < N; i++) {
			int move = 1;
			for (int j = 0; j < N; j++) {
				if (move <= j) move = j + 1;
				while (move < N && arr[move][i] == 0) ++move;
				if (move >= N) break;
				if (arr[j][i] == 0) {
					arr[j--][i] = arr[move][i];
					arr[move++][i] = 0;
				}
				else {
					if (arr[j][i] == arr[move][i]) {
						arr[j][i] *= 2;
						if (arr[j][i] > max) max = arr[j][i];
						arr[move++][i] = 0;
					}

				}
			}
		}
		break;
	}
	return max;
}
