#include <iostream>
#include <vector>
#include <string>
#define INF 9999999;
using namespace std;

int solution(string name);
int minUpdown(char k);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << solution("BBBAAB");
}

int solution(string name) {
	int sum = 0;
	int size = name.size();
	int arr[1048576] = { 0, };
	arr[1<<n
	for (int i = 1; i < size; i++) {
		if (name[i] == 'A') ;
		sum += minUpdown(name[i]);
		}
	}


	//À½...

}

int minUpdown(char k) {
	if (k == 'N') { return 13; }
	else if (k < 'N') { return k - 'A'; }
	else { return 'Z' - k + 1; }
}