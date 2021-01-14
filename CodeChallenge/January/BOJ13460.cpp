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
pair<pos, pos> moveBall(pos nowR, pos nowB, int dir);
int main() {
	int N, M;
	cin >> N >> M;
	pos blue, red;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char tmp;
			cin >> tmp;
			if (tmp != '#' && tmp != '.') {
				map[i][j] = '.';
				if (tmp == 'B') blue = { i,j };
				else if (tmp == 'R') red = { i,j };
				else  target = { i,j };
			}
			else {
				map[i][j] = tmp;
			}
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
			//������� �� ������ ���� �����̴°� ����Ʈ
			pair<pos, pos> tmp = moveBall(R, B, i);
			pos tmpR = tmp.first;
			pos tmpB = tmp.second;
			if (tmpB.row == 0) continue;
			if (tmpR.row == 0) return turn;
			if (visit[tmpR.row][tmpR.col][tmpB.row][tmpB.col] == true) continue;
			visit[tmpR.row][tmpR.col][tmpB.row][tmpB.col] = true;
			q.push({ tmpR, tmpB });
		}
	}
	return -1;
}

pair<pos, pos> moveBall(pos nowR, pos nowB, int dir) {
	bool flag = false;
	switch (dir) {
	case 0:
		flag = (nowR.col>nowB.col);
		break;
	case 1:
		flag = (nowR.row > nowB.row);
		break;
	case 2:
		flag = (nowR.col < nowB.col);
		break;
	case 3:
		flag = (nowR.row<nowB.row);
		break;
	}
	pos order[2] = { nowB,nowR };
	if (flag) {
		order[0] = nowR;
		order[1] = nowB;
	}
	//�����̴¹��� �����Ű����� ���� �ű��
	for (int i = 0; i <= 1;i++) {
		while (map[order[i].row + dirR[dir]][order[i].col + dirC[dir]] != '#') {
			//�ٸ����� �����վ break
			if (i == 1 &&order[0].row==order[1].row && order[0].col==order[1].col) break;
			order[i].row += dirR[dir];
			order[i].col += dirC[dir];
			//���� Ż���ϸ� row�� 0���� ǥ��
			if (order[i].row == target.row && order[i].col == target.col) {
				if (!flag && i == 0) {
					return { {0,0},{0,0} };
				}
				order[i].row=0;
				break;
			}
		}
	}
	if (flag) return {order[0], order[1]};
	else return { order[1], order[1] };
}