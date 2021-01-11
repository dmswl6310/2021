#include <iostream>
#include <queue>
using namespace std;
typedef struct {
	int row;
	int col;
}pos;
int dirR[4] = { 0,1,0,-1 };
int dirC[4] = { 1,0,-1,0 };
bool visit[10][10][10][10] = { false, };
char map[10][10];
pos target;
int change(pos red, pos blue);
pos knowEnd(pos nowR, pos nowB, int dir);
int main() {
	int N, M;
	cin >> N >> M;
	pos blue, red;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') blue = { i,j };
			else if (map[i][j] == 'R')red = { i,j };
			else if (map[i][j] == 'O') target = { i,j };
		}
	}
	cout << change(red, blue);



}

int change(pos red, pos blue) {
	visit[red.row][red.col][blue.row][blue.col] = true;
	queue <pair<pos, pos>> q;
	q.push({ red,blue });
	int turn = 0;
	while ((!q.empty()) && (++turn) <= 10) {
		pos R = q.front().first;
		pos B = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			//방향따라 더 가까운것 먼저 움직이는게 포인트
			pair<pos, pos> tmp = knowEnd(R, B, i);
			pos tmpR = tmp.first;
			pos tmpB = tmp.second;
			if ((tmpB.row == 0 && tmpB.col == 0) || visit[tmpR.row][tmpR.col][tmpB.row][tmpB.col] == true) continue;
			else if (tmpR.row == 0 && tmpR.col == 0) return turn;
			visit[tmpR.row][tmpR.col][tmpB.row][tmpB.col] = true;
			q.push({ tmpR, tmpB });
		}
	}
	return -1;
}

pair<pos, pos> knowEnd(pos nowR, pos nowB, int dir) {
	pair<pos, pos> position = { nowR,nowB };
	pair<pos, pos> answer = { {0,0},{0,0} };
	int rowR = nowR.row;
	int colR = nowR.col;
	int rowB = nowB.row;
	int colB = nowB.col;
	bool flag;
	switch (dir) {
	case 0:
		flag = (colR > colB);
		break;
	case 1:
		flag = (rowR > rowB);
		break;
	case 2:
		flag = (colR < colB);
		break;
	case 3:
		flag = (rowR < rowB);
		break;
	}
	if (!flag)  position = { nowB, nowR };
	int firstR = position.first.row;
	int firstC = position.first.col;
	int secondR = position.second.row;
	int secondC = position.second.col;
	while (map[firstR + dirR[dir]][firstC + dirC[dir]] != '#') {
		firstR += dirR[dir];
		firstC += dirC[dir];
		if (firstR == target.row && firstC == target.col) break;
	}
	if(answer.first.row!=0 && answer.first.col!=0) {
		position.first.row = firstR;
		position.first.col = firstC;
	}

	while (map[secondR + dirR[dir]][secondC + dirC[dir]] != '#') {
		secondR += dirR[dir];
		secondC += dirC[dir];
		if (secondR == target.row && secondC == target.col) break;
	}
	if (answer.first.row != 0 && answer.first.col != 0) {
		position.first.row = firstR;
		position.first.col = firstC;
	}


}