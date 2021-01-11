#include<iostream>
#include <queue>
#include <string>
using namespace std;

void BFS(int N, int T, int G);

int main() {
	int N, T, G;
	cin >> N >> T >> G;
	BFS(N, T, G);
}

void BFS(int N, int T, int G) {
	queue <pair<int, int>> q;
	q.push({ N,0 });
	bool visit[100000] = { false, };
	visit[N] = true;

	while (!q.empty()) {
		int num = q.front().first;
		int turn = q.front().second;


		if (turn > T) break;
		if (num == G) {
			cout << turn;
			return;
		}
		q.pop();
		//��ưA
		if (num < 99999 && visit[num + 1] == false) {
			q.push({ num + 1,turn + 1 });
			visit[num + 1] = true;;
		}
		//��ưB
		num *= 2;
		if (num > 99999 || num == 0) continue;
		string s = to_string(num);
		s[0]--;
		num = stoi(s);
		if (visit[num] == false) {
			q.push({ num,turn + 1 });
			visit[num] = true;
		}
	}
	cout << "ANG";
	return;
}