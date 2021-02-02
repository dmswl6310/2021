#include<iostream>
#include<vector>

using namespace std;
int numMax = 0;
int N;
int dirR[4] = { -1,1,1,-1 };
int dirC[4] = { -1,-1,1,1 };
void chess(int row, int col, vector<vector<int>>arr, int num, int possible);
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	vector<vector<int>> arr(N, vector<int>(N));
	int num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin>>arr[i][j];
			if (arr[i][j]) num++;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j]) chess(i, j, arr, 1, num);
		}
	}
	cout << numMax;



}

void chess(int row, int col,vector<vector<int>>arr,int num,int possible) {
	possible--;
	arr[row][col] = 0;


	for (int i = 0; i < 4; i++) {
		int trow = row;
		int tcol = col;
		while (trow>=0 && trow<N &&tcol>=0 && tcol<N) {
			if(arr[trow][tcol]){
				possible--;
				arr[trow][tcol] = 0;
			}
			trow += dirR[i];
			tcol += dirC[i];

		}
	}

	if (possible + num < numMax) return;
	for (int j = col + 1; j < N; j++) {
		if (arr[row][j]) chess(row, j, arr, num + 1,possible);
	}
	for (int i = row+1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j]) chess(i, j, arr, num + 1,possible);
		}
	}
	if (num > numMax) numMax = num;
	return;

}
