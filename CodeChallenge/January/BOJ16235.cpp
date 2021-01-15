#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct {
	int food;
	vector<int> treeAge;
}Ground;

int dirR[8] = { 0,1,1,1,0,-1,-1,-1 };
int dirC[8] = { 1,1,0,-1,-1,-1,0,1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, K;
	Ground ground[11][11];
	int foodmap[11][11];

	//�Է¹ޱ�� �ʱ�ȭ
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> foodmap[i][j];
			ground[i][j].food = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		ground[x][y].treeAge.push_back(z);
	}

	//K�� �ù�
	for (int turn = 0; turn < K; turn++) {
		//������
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				//����� ���̺��� ����(��������)
				int num = -1;
				int size = ground[i][j].treeAge.size();
				sort(ground[i][j].treeAge.begin(), ground[i][j].treeAge.end());
				while (++num < size) {
					ground[i][j].food -= ground[i][j].treeAge[num];
					if (ground[i][j].food < 0) {
						ground[i][j].food += ground[i][j].treeAge[num];
						break;
					}
					ground[i][j].treeAge[num]++;
				}
				int tmp = num;
				while (num < size) {
					ground[i][j].food += (ground[i][j].treeAge[num++] / 2);
				}
				//��� �����ϸ� �ð��ɸ��� �ѹ��� ������ ����
				ground[i][j].treeAge.resize(tmp);
			}
		}

		//�����ܿ�
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int num = 0; num < ground[i][j].treeAge.size(); num++) {
					if (ground[i][j].treeAge[num] % 5 == 0) {
						for (int pos = 0; pos < 8; pos++) {
							int row = i + dirR[pos];
							int col = j + dirC[pos];
							if (row <= 0 || row > N || col <= 0 || col > N) continue;
							ground[row][col].treeAge.push_back(1);
						}
					}
				}
				ground[i][j].food += foodmap[i][j];
			}

		}
	}
	//��Ƴ��� �������� ���
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer += ground[i][j].treeAge.size();
		}
	}
	cout << answer;
}
