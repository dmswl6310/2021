#include <iostream>
using namespace std;
typedef struct {
	int r, c;
	//위는 두번째, 아래는 네번째
	int leftright[4];
	int updown[4];
}Dice;
Dice dice;
int dirR[4] = { 0,0,-1,1 };
int dirC[4] = { 1,-1,0,0 };
int map[20][20];
void moveDice(int N, int M, int dir);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, x, y, K;
	cin >> N >> M >> dice.r >> dice.c >>K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		dice.leftright[i] = 0;
		dice.updown[i] = 0;
	}
	for (int i = 0; i < K; i++) {
		int dir;
		cin >> dir;
		moveDice(N,M,dir);
	}

}
void moveDice(int N,int M,int dir) {
	int row = dice.r + dirR[dir-1];
	int col = dice.c + dirC[dir - 1];
	if (row < 0 || row >= N || col < 0 || col >= M) return;

	dice.r = row;
	dice.c = col;

	switch (dir) {
		int tmp;
	case 1:
		tmp = dice.leftright[3];
		for (int i = 3; i > 0; i--) {
			dice.leftright[i] = dice.leftright[i - 1];
		}
		dice.leftright[0] = tmp;
		break;

	case 2:
		tmp = dice.leftright[0];
		for (int i = 0; i < 3; i++) {
			dice.leftright[i] = dice.leftright[i + 1];
		}
		dice.leftright[3] = tmp;
		break;

	case 3:
		tmp = dice.updown[0];
		for (int i = 0; i < 3; i++) {
			dice.updown[i] = dice.updown[i + 1];
		}
		dice.updown[3] = tmp;
		break;

	case 4:
		tmp = dice.updown[3];
		for (int i = 3; i > 0; i--) {
			dice.updown[i] = dice.updown[i - 1];
		}
		dice.updown[0] = tmp;
		break;
	}
	if (dir == 1 || dir == 2) {
		dice.updown[1] = dice.leftright[1];
		dice.updown[3] = dice.leftright[3];
	}
	else {
		dice.leftright[1] = dice.updown[1];
		dice.leftright[3] = dice.updown[3];
	}

	if (map[row][col] == 0) {
		map[row][col] = dice.leftright[3];
	}
	else {
		dice.leftright[3] = dice.updown[3] = map[row][col];
		map[row][col] = 0;
	}

	cout << dice.updown[1]<<"\n";
}